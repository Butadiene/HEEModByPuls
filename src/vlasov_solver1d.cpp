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


      void Vlasov1DSolver::calcFminFmax(double &fmin,double &fmax,double fi_plus2,double fi_plus1,double fi,double fi_minus1,double fi_minus2){
        double fmax1 = std::max(std::max(fi_minus1,fi),std::min(2*fi_minus1-fi_minus2,2*fi-fi_plus1));

        double fmax2 = std::max(std::max(fi_plus1,fi),std::min(2*fi_plus1-fi_plus2,2*fi-fi_minus1));

        double fmin1 = std::min(std::min(fi_minus1,fi),std::max(2*fi_minus1-fi_minus2,2*fi-fi_plus1));

        double fmin2 = std::min(std::min(fi_plus1,fi),std::max(2*fi_plus1-fi_plus2,2*fi-fi_minus1));

        fmax = std::max(fmax1,fmax2);

        fmin = std::max(0.0,std::min(fmin1,fmin2));
      };


    double Vlasov1DSolver::Li_plusFunc(double fmin,double fmax,double value1,double value2){
        float res = 0.0;
        if(value1>=value2){res = std::min(2*(value2-fmin),value1-value2);}
        else{res = std::max(2*(value2-fmax),value1-value2);}
        return value1-value2;
      }

      double Vlasov1DSolver::Li_minusFunc(double fmin,double fmax,double value1,double value2){
        float res = 0.0;
        if(value1>=value2){res = std::min(2*(fmax-value1),value1-value2);}
        else{res = std::max(2*(fmin-value1),value1-value2);}
        return value1-value2;
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

        constexpr double Lvalue = 6.0;
        constexpr double R_zero = 6.4E8;
        constexpr double lightspeed = physical_constant::lightspeed;
        constexpr double B_E = 3.11E-1;
        constexpr double T_period = 100.0;
        constexpr double B_eq = B_E/(Lvalue*Lvalue*Lvalue);
        constexpr double guzai_aster = -3.0*lightspeed*T_period/Lvalue/R_zero; 
        constexpr double m_e = 9.1E-28;
        constexpr double q_e = 4.8E-10;
        double t_aster = 0.0;
        
        constexpr double PI = mathcommon::PI;
        constexpr double B_z_aster = 1.0;
        constexpr double m_aster = 1.0;
        constexpr double q_aster = 1.0;
        constexpr double Omega_e = B_eq*q_e/(m_e*lightspeed);
        constexpr double E_aster_A = 1.0E-7/B_eq;//4.0E3/lightspeed;
        constexpr double m_number = 20.0;
        constexpr double lamda = Lvalue*R_zero*2.*PI/m_number;
        double theta = 0.0;
        double delta_theta = 2.0*PI/(m_number*real_grid_num);
     
        double delta_t_aster = 0.15;
        
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
                    double v_perp_ast = 0.01;
                    double myu_aster = m_aster*v_perp_ast*v_perp_ast/(2.0*B_z_aster);
                    double delta_x_aster = (R_zero * Lvalue * delta_theta)/(lightspeed*T_period);



                    float phase = 2.0*PI*(t_aster-Lvalue*R_zero*(theta+0.5*delta_theta)/lamda)+PI/2.0;
                
                   // phase = PI/2.0; //constant electric field

                    double velocity_aster_denominator = -(B_z_aster+(m_aster/q_aster)*(guzai_aster/(T_period*Omega_e)*((E_aster_A/(B_z_aster*B_z_aster))*std::sin(phase))));

                    double velocity_aster_numerator = -(E_aster_A*std::sin(phase)-myu_aster/q_aster*guzai_aster/(T_period*Omega_e)+m_aster/q_aster*1.0/(B_z_aster*B_z_aster*B_z_aster)*guzai_aster/(T_period*Omega_e)*std::pow(E_aster_A*std::sin(phase),2.0));

                    double velocity_aster = velocity_aster_numerator/velocity_aster_denominator;

                    double nuu_plus = velocity_aster*delta_t_aster/delta_x_aster;





                    phase = 2.0*PI*(t_aster-Lvalue*R_zero*(theta-0.5*delta_theta)/lamda)+PI/2.0;
                
                    //phase = PI/2.0; //constant electric field

                    velocity_aster_denominator = -(B_z_aster+(m_aster/q_aster)*(guzai_aster/(T_period*Omega_e)*((E_aster_A/(B_z_aster*B_z_aster))*std::sin(phase))));

                    velocity_aster_numerator = -(E_aster_A*std::sin(phase)-myu_aster/q_aster*guzai_aster/(T_period*Omega_e)+m_aster/q_aster*1.0/(B_z_aster*B_z_aster*B_z_aster)*guzai_aster/(T_period*Omega_e)*std::pow(E_aster_A*std::sin(phase),2.0));

                    velocity_aster = velocity_aster_numerator/velocity_aster_denominator;

                    double nuu_minus = velocity_aster*delta_t_aster/delta_x_aster;



                    double u_plus = 0.0;

                    double u_minus = 0.0;

                    double fi = manage_psd_data_.GetVelocityPsd(focus_real_grid,focus_velocity_grid);
                    double fi_plus1 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus1,focus_velocity_grid);
                    double fi_plus2 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus2,focus_velocity_grid);
                    double fi_plus3 = manage_psd_data_.GetVelocityPsd(focus_real_grid_plus3,focus_velocity_grid);
                    double fi_minus1 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus1,focus_velocity_grid);
                    double fi_minus2 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus2,focus_velocity_grid);
                    double fi_minus3 = manage_psd_data_.GetVelocityPsd(focus_real_grid_minus3,focus_velocity_grid);

                  
                    double Li_plus = 0.0;
                    double Li_minus = 0.0;

                    double fmax,fmin;

                    if(velocity_aster<0){
                         calcFminFmax(fmin,fmax,fi_minus1,fi,fi_plus1,fi_plus2,fi_plus3);
                        Li_plus = Li_plusFunc(fmin,fmax,fi,fi_plus1);
                        Li_minus = Li_minusFunc(fmin,fmax,fi_plus1,fi_plus2);
                        u_plus = nuu_plus*fi_plus1+nuu_plus*(1+nuu_plus)*(2+nuu_plus)*(Li_plus)/6+nuu_plus*(1-nuu_plus)*(1+nuu_plus)*(Li_minus)/6;

                         calcFminFmax(fmin,fmax,fi_minus2,fi_minus1,fi,fi_plus1,fi_plus2);;
                        Li_plus = Li_plusFunc(fmin,fmax,fi_minus1,fi);
                        Li_minus = Li_minusFunc(fmin,fmax,fi,fi_plus1);
                        u_minus =nuu_minus*fi+nuu_minus*(1+nuu_minus)*(2+nuu_minus)*(Li_plus)/6+nuu_minus*(1-nuu_minus)*(1+nuu_minus)*(Li_minus)/6;
                    }else{
                        calcFminFmax(fmin,fmax,fi_plus2,fi_plus1,fi,fi_minus1,fi_minus2);
                         Li_plus = Li_plusFunc(fmin,fmax,fi_plus1,fi);
                        Li_minus = Li_minusFunc(fmin,fmax,fi,fi_minus1);
                        u_plus = nuu_plus*fi+nuu_plus*(1-nuu_plus)*(2-nuu_plus)*(Li_plus)/6+nuu_plus*(1-nuu_plus)*(1+nuu_plus)*(Li_minus)/6;

                       calcFminFmax(fmin,fmax,fi_plus1,fi,fi_minus1,fi_minus2,fi_minus3);
                        Li_plus = Li_plusFunc(fmin,fmax,fi,fi_minus1);
                        Li_minus = Li_minusFunc(fmin,fmax,fi_minus1,fi_minus2);
                        u_minus =nuu_minus*fi_minus1+nuu_minus*(1-nuu_minus)*(2-nuu_minus)*(Li_plus)/6+nuu_minus*(1-nuu_minus)*(1+nuu_minus)*(Li_minus)/6;

                    }
                    
                    manage_psd_data_.SetVelocityPsd(focus_real_grid,focus_velocity_grid,(fi+u_minus-u_plus));
          

                }
                
            }
            t_aster += delta_t_aster;
            manage_psd_data_.UpdateBufferParam();
           
        }
         

    }




}
}
