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




}
}