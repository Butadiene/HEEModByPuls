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

        double Lvalue = 6.0;
        double R_zero = 6.4E8;
        double lightspeed = physical_constant::lightspeed;
        double B_E = 3.11E-1;
        double T_period = 1.0;
        double B_eq = B_E/(Lvalue*Lvalue*Lvalue);
        double guzai_aster = -3.0*lightspeed*T_period/Lvalue/R_zero; 
        double m_e = 9.1E-28;
        double q_e = 4.8E-10;
        double t_aster = 0.0;
        
        double PI = mathcommon::PI;
        double B_z_aster = 1.0;
        double m_aster = 1.0;
        double q_aster = 1.0;
        double Omega_e = q_e/(m_e*lightspeed)*B_eq;
        double E_aster_A = 0.0;//4.0E3/lightspeed;
        double m_number = 20.0;
        double lamda = Lvalue*R_zero*2.*PI/m_number;
        double theta = 0.0;
        double delta_theta = 2.0*PI/(m_number*real_grid_num);
     
        double delta_t_aster = 0.1;
        
        for(int i = 0;i<all_steps_;i++){
           //field_update(); not used field_component value
           theta = 0;
            for(int j=0;j<real_grid_num;j++){
                focus_real_grid[0] = j;
                focus_real_grid_plus1[0] = (j+1)%real_grid_num;
                focus_real_grid_plus2[0] = (j+2)%real_grid_num;
                focus_real_grid_plus3[0] = (j+3)%real_grid_num;               
                focus_real_grid_minus1[0] = (j-1+real_grid_num)%real_grid_num;
                focus_real_grid_minus2[0] = (j-2+real_grid_num)%real_grid_num;
                focus_real_grid_minus3[0] = (j-3+real_grid_num)%real_grid_num;
                theta += delta_theta;
                for(int k=0;k<velocity_grid_num;k++){
                    double myu = 1.0;
                    double myu_aster = B_eq/(lightspeed*lightspeed*m_e);


                   focus_velocity_grid[0] = k; 
                    double velocity_denominator = -(B_z_aster+(m_aster/q_aster)*(guzai_aster/(T_period*Omega_e)*((E_aster_A/(B_z_aster*B_z_aster))*sin(2.0*PI*(t_aster-R_zero*theta/lamda)+PI/2.0))));

                    double velocity_numerator = E_aster_A*sin(2.0*PI*(t_aster-R_zero*theta/lamda)+PI/2.0)-myu_aster/q_aster*guzai_aster/(T_period*Omega_e)+m_aster*lightspeed/q_aster*1.0/(B_z_aster*B_z_aster*B_z_aster)*guzai_aster/(T_period*Omega_e)*pow(E_aster_A*sin(2.0*PI*(t_aster-R_zero*theta/lamda)+PI/2.0),2.0);

                    double velocity = velocity_numerator/velocity_denominator;

                    //double velocity = 1.0;

                    double u_plus = 0.0;

                    double u_minus = 0.0;
                    
                  
                    double fi = manage_psd_data_.GetVelocityPsd(focus_real_grid,focus_velocity_grid);
                    double fi_plus1 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus1,focus_velocity_grid);
                    double fi_plus2 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus2,focus_velocity_grid);
                    double fi_minus1 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus1,focus_velocity_grid);
                    double fi_minus2 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus2,focus_velocity_grid);
/////////////////////////////////////////////////////////////////速度の規格化の話ががばがばなんですが！！！！
                    double nuu = -velocity*delta_t_aster/(R_zero * Lvalue * delta_theta);

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
            t_aster += delta_t_aster;
            manage_psd_data_.UpdateBufferParam();
           
        }
         

    }




}
}
