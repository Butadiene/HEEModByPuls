#include "../include/initialize_psd.hpp"
#include <iostream>
namespace heemodbypuls{
namespace initialize_psd{


    InitializePsd::InitializePsd(
        const manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd)
    :manage_psd_(in_manage_psd)
    {}

    void InitializePsd::TestInitialize7(){

        coordinate_spec::CoordinateSpec coordinate_spec = manage_psd_.get_coordinate_spec_();
        
        for(int i =0;i<coordinate_spec.get_total_grid_num_();i++){
            manage_psd_.SetValueFromNumArray(i,7.0);
        }
        
    }

    
    void InitializePsd::Maxwellian1D1D(std::int_fast32_t teperature){

        
        coordinate_spec::CoordinateSpec coordinate_spec = manage_psd_.get_coordinate_spec_();

        if(coordinate_spec.get_real_dimension_num_()!=1||coordinate_spec.get_velocity_dimension_num_()!=1){
              std::cout<<"HEEModByPuls's error::The number of dimensions does not match on Maxwellian1D1D"<<"\n";
            exit(1);
            
        }

        std::vector<std::int_fast32_t> focus_real_grid(1,0);
        std::vector<std::int_fast32_t> focus_velocity_grid(1,0);


        for(int i =0;i<coordinate_spec.get_real_each_grid_num_()[0];i++){
            focus_real_grid[0] = i;
            double focus_grid_density = manage_psd_.GetRealPsd(focus_real_grid);

            for(int j = 0;j<coordinate_spec.get_velocity_each_grid_num_()[0];j++){
                focus_velocity_grid[0] = 1;
                manage_psd_.SetVelocityPsd(focus_real_grid,focus_velocity_grid,j);
             }
        }
           
             
        
       
    }




}
}