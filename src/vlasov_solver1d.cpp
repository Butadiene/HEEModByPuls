#include "../include/vlasov_solver1d.hpp"
#include "../include/physical_constant.hpp"
#include <cmath>
#include <iostream>

namespace heemodbypuls{
namespace vlasov1d_solver{

    Vlasov1DSolver::Vlasov1DSolver(manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd_data,manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field_data,
    const apply_boundary_condition::ApplyBoundaryCondition& in_apply_condition,
    const coordinate_spec::CoordinateSpec& in_coordinate_spec)
    :manage_psd_data_(in_manage_psd_data)
    ,manage_field_data_(in_manage_field_data)
    ,apply_boundary_condition_(in_apply_condition)
    ,coordinate_spec_(in_coordinate_spec)
    {
        if(coordinate_spec_.get_real_dimension_num_()!=1||coordinate_spec_.get_velocity_dimension_num_()!=1){
            std::cout<<"HEEModByPuls's error::The number of dimensions does not match on Vlasov1D"<<"\n";
            exit(1);
                    
        }

        total_time_ = 0.0;

        delta_theta_ = theta_range_ / coordinate_spec_.get_real_each_grid_num_()[0];
        field_update();


    }

    
      double Vlasov1DSolver::calc_advection(double cfl_num,double fi_minus2,double fi_minus1, double fi,double fi_plus1,double fi_plus2){
          double Li_plus = 0.;
          double Li_minus = 0.;
      
        
          double u_plus = cfl_num*fi+cfl_num*(1.-cfl_num)*(2.-cfl_num)*Li_plus/6.+cfl_num*(1.0-cfl_num)*(1.+cfl_num)*Li_minus/6.;

          return -u_plus;

      }

      void Vlasov1DSolver::field_update(){
          
        std::int_fast32_t real_grid_num = coordinate_spec_.get_real_each_grid_num_()[0];
        std::vector<std::int_fast32_t> focus_grid(1,0);
        std::vector<double> field_vector(1.0,0);
        
        for(int i =0;i<real_grid_num;i++){
            focus_grid[0] = i;
            field_vector[0] = ulf_electric_amplitude_*std::sin(m_number_*2.0*mathcommon::PI*(total_time_/ulf_wave_period_-Radius_*delta_theta_*i/ulf_wave_length_)+mathcommon::PI/2.0);
            manage_field_data_.SetFieldValue(0.,focus_grid,field_vector);
        }
        
       
      }

   
    void Vlasov1DSolver::solver(){
        
        std::int_fast32_t real_grid_num = coordinate_spec_.get_real_each_grid_num_()[0];
        std::int_fast32_t velocity_grid_num = coordinate_spec_.get_velocity_each_grid_num_()[0];
        std::vector<std::int_fast32_t> focus_real_grid(1,0);
        std::vector<std::int_fast32_t> focus_real_grid_plus1(1,0);
        std::vector<std::int_fast32_t> focus_real_grid_plus2(1,0);
        std::vector<std::int_fast32_t> focus_real_grid_plus3(1,0);
        std::vector<std::int_fast32_t> focus_real_grid_minus1(1,0);
        std::vector<std::int_fast32_t> focus_real_grid_minus2(1,0);
        std::vector<std::int_fast32_t> focus_real_grid_minus3(1,0);
        std::vector<std::int_fast32_t> focus_velocity_grid(1,0);
        
        double guzai_aster = 1.0; 
        double myu_aster = 1.0;
        double t_aster = 1.0;
        double R_zero = 1.0;
        double T_period = 1.0;
        double B_z_aster = 1.0;
        double m_aster = 1.0;
        double q_aster = 1.0;
        double Omega_e = 1.0;
        double E_aster_A = 0.0;
        double lamda = 1.0;
        double wave_num = 1.0;
        double sita = 1.0;
        double PI = mathcommon::PI;
        double lightspeed = physical_constant::lightspeed;
        for(int i = 0;i<all_steps_;i++){
           field_update();
            for(int j=0;j<real_grid_num;j++){
                focus_real_grid[0] = j;
                focus_real_grid_plus1[0] = (j+1)%real_grid_num;
                focus_real_grid_plus2[0] = (j+2)%real_grid_num;
                focus_real_grid_plus3[0] = (j+3)%real_grid_num;               
                focus_real_grid_minus1[0] = (j-1+real_grid_num)%real_grid_num;
                focus_real_grid_minus2[0] = (j-2+real_grid_num)%real_grid_num;
                focus_real_grid_minus3[0] = (j-3+real_grid_num)%real_grid_num;
                for(int k=0;k<velocity_grid_num;k++){
                   focus_velocity_grid[0] = k; 
                    double velocity_denominator = -(B_z_aster+(m_aster/q_aster)*(guzai_aster/(T_period*Omega_e)*((E_aster_A/(B_z_aster*B_z_aster))*sin(wave_num*2.0*PI*(t_aster-R_zero*sita/lamda)+PI/2.0))));

                    double velocity_numerator = E_aster_A*sin(wave_num*2.0*PI*(t_aster-R_zero*sita/lamda)+PI/2.0)-myu_aster/q_aster*guzai_aster/(T_period*Omega_e)+m_aster*lightspeed/q_aster*1.0/(B_z_aster*B_z_aster*B_z_aster)*guzai_aster/(T_period*Omega_e)*pow(E_aster_A*sin(wave_num*2.0*PI*(t_aster-R_zero*sita/lamda)+PI/2.0),2.0);

                    double velocity = velocity_numerator/velocity_denominator;

                    //double velocity = 1.0;

                    double u_plus = 0.0;

                    double u_minus = 0.0;
                    
                  
                    double fi = manage_psd_data_.GetVelocityPsd(focus_real_grid,focus_velocity_grid);
                    double fi_plus1 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus1,focus_velocity_grid);
                    double fi_plus2 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus2,focus_velocity_grid);
                    double fi_minus1 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus1,focus_velocity_grid);
                    double fi_minus2 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus2,focus_velocity_grid);

                    double nuu = -velocity*delta_time_/delta_theta_;

                    double Li_plus = 0.0;
                    double Li_minus = 0.0;

                    double fmin1 = std::min(std::min(fi_minus1,fi),std::max(2*fi_minus1-fi_minus2,2*fi-fi_plus1));

                    double fmin2 = std::min(std::min(fi_plus1,fi),std::max(2*fi_plus1-fi_plus2,2*fi-fi_minus1));

                    double fmax1 = std::max(std::max(fi_minus1,fi),std::min(2*fi_minus1-fi_minus2,2*fi-fi_plus1));

                    double fmax2 = std::max(std::max(fi_plus1,fi),std::min(2*fi_plus1-fi_plus2,2*fi-fi_minus1));

                    double fmax = std::max(fmax1,fmax2);

                    double fmin = std::max(0.0,std::min(fmin1,fmin2));


                    if(velocity<0){
                        u_plus = nuu*fi_plus1+nuu*(1+nuu)*(2+nuu)*(fi-fi_plus1)/6+nuu*(1-nuu)*(1+nuu)*(fi_plus1-fi_plus2)/6;
                        u_minus =nuu*fi+nuu*(1+nuu)*(2+nuu)*(fi_minus1-fi)/6+nuu*(1-nuu)*(1+nuu)*(fi-fi_plus1)/6;
                    }else{
                        u_plus = nuu*fi+nuu*(1-nuu)*(2-nuu)*(fi_plus1-fi)/6+nuu*(1-nuu)*(1+nuu)*(fi-fi_minus1)/6;
                        u_minus =nuu*fi_minus1+nuu*(1-nuu)*(2-nuu)*(fi-fi_minus1)/6+nuu*(1-nuu)*(1+nuu)*(fi_minus1-fi_minus2)/6;
                        
                    }
                    
                    manage_psd_data_.SetVelocityPsd(focus_real_grid,focus_velocity_grid,1+fi+(fi+u_minus-u_plus)*0.);

                    //manage_psd_data_.SetVelocityPsd(focus_real_grid,focus_velocity_grid,k);

                }
            }
            total_time_ += delta_time_;
            manage_psd_data_.UpdateBufferParam();
           
        }
         

    }




}
}
