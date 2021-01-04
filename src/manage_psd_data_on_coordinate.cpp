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
    {
        num_bufferarray = 0;
        num_calcarray = (num_bufferarray + 1 ) % 2;
    }

    void ManagePsdDataOnCoordinate::UpdateBufferParam(){
        num_bufferarray = (num_bufferarray + 1 ) % 2;
        num_calcarray = (num_calcarray + 1) % 2;
    }

    void ManagePsdDataOnCoordinate::IntegrateVelocityPsdForRealPsd(){
        std::int_fast32_t real_grid_num = coordinate_spec_.get_real_grid_num_();
        std::int_fast32_t velocity_grid_num = coordinate_spec_.get_velocity_grid_num_();

        for(int i = 0; i < real_grid_num; i++){
            std::int_fast32_t array_num_integrate_real_grid = i * velocity_grid_num; 
            double integrate_each_real_psd = double(0.0);
            for(int j = 0; j < velocity_grid_num; j++){
                integrate_each_real_psd += 
                    psd_store_data_in_memory_array_.get_data_in_memory_array_()[array_num_integrate_real_grid][num_bufferarray];
            }
            real_psd_by_integrate_velocity_psd_store_data_in_memory_array_.get_data_in_memory_array_()[i][num_bufferarray] = integrate_each_real_psd;
        }
    }


}
}
