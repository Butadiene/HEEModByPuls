#include "../include/manage_psd_data_on_coordinate.hpp"

namespace heemodbypuls{
namespace manage_psd_data_on_coordinate{


    ManagePsdDataOnCoordinate::ManagePsdDataOnCoordinate(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_store_data_in_memory_array,
        const store_data_in_memory_array::StoreDataInMemoryArray& in_real_psd_by_integrate_velocity_psd_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec)
    :psd_store_data_in_memory_array_(in_store_data_in_memory_array)
    ,real_psd_by_integrate_velocity_psd_store_data_in_memory_array_(in_real_psd_by_integrate_velocity_psd_store_data_in_memory_array)
    ,coordinate_spec_(in_coordinate_spec)
    {}


    void ManagePsdDataOnCoordinate::IntegrateVelocityPsdForRealPsd(){
        for(int i = 0;i<coordinate_spec_.get_real_grid_num_();i++){
            double integrate_each_real_psd = double(0.0);
            for(int j = 0;j<coordinate_spec_.get_velocity_grid_num_();j++){
                //integrate_each_real_psd += 
            }
        }
    }


}
}
