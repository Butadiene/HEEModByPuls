#include "../include/initialize_psd.hpp"

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

    
    void InitializePsd::Maxwellian(std::int_fast32_t teperature){

        
        coordinate_spec::CoordinateSpec coordinate_spec = manage_psd_.get_coordinate_spec_();

        std::vector<std::int_fast32_t> focus_real_grid{coordinate_spec.get_real_dimension_num_(),0};
/*
        for(int i=0;i<coordinate_spec.get_real_dimension_num_();i++){
            for(int j =0;j<coordinate_spec.get_real_each_grid_num_()[i];j++){
                
            }
            double focus_grid_density = manage_psd_.GetRealPsd()
             for(int j = 0;i<coordinate_spec.get_velocity_dimension_num_();j++){
                 manage_psd_.SetVelocityPsd();
             }
        }
  */      
    }




}
}