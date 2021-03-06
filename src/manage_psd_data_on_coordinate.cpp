#include "../include/manage_psd_data_on_coordinate.hpp"
#include <iostream>
namespace heemodbypuls{
namespace manage_psd_data_on_coordinate{


    ManagePsdDataOnCoordinate::ManagePsdDataOnCoordinate(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_psd_store_data_in_memory_array,
        const store_data_in_memory_array::StoreDataInMemoryArray& in_real_psd_by_integrate_velocity_psd_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec)
    :psd_store_data_in_memory_array_(in_psd_store_data_in_memory_array)
    ,real_psd_by_integrate_velocity_psd_store_data_in_memory_array_(in_real_psd_by_integrate_velocity_psd_store_data_in_memory_array)
    ,coordinate_spec_(in_coordinate_spec)
    {
        num_bufferarray_ = 0,
        num_calcarray_ = 1 % psd_store_data_in_memory_array_.get_buffer_num_();
    }

    void ManagePsdDataOnCoordinate::IntegrateVelocityPsdForRealPsd()
    {
        std::int_fast32_t real_grid_num = coordinate_spec_.get_real_grid_num_();
        std::int_fast32_t velocity_grid_num = coordinate_spec_.get_velocity_grid_num_();

        for(int i = 0; i < real_grid_num; i++){
            std::int_fast32_t array_num_integrate_real_grid = i * velocity_grid_num; 
            double integrate_each_real_psd = double(0.0);
            for(int j = 0; j < velocity_grid_num; j++){
                integrate_each_real_psd += 
                    psd_store_data_in_memory_array_.get_data_in_memory_array_()[array_num_integrate_real_grid+j][num_bufferarray_];
            }
            real_psd_by_integrate_velocity_psd_store_data_in_memory_array_.get_data_in_memory_array_()[i][num_bufferarray_] = integrate_each_real_psd;
        }
    }


   






    

    double ManagePsdDataOnCoordinate::GetRealPsd(std::vector<int_fast32_t> num_focus_real_elements) const{

        std::int_fast32_t num_psd_need_on_array = GetNumArrayFromCoordinateOnRealPsdArray(num_focus_real_elements);

        return real_psd_by_integrate_velocity_psd_store_data_in_memory_array_.get_data_in_memory_array_()[num_psd_need_on_array][num_bufferarray_];


    }

    double ManagePsdDataOnCoordinate::GetVelocityPsd(std::vector<int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> num_focus_velocity_elements) const{

        std::int_fast32_t num_psd_need_on_array = GetNumArrayFromCoordinateOnAllPsdArray(num_focus_real_elements,num_focus_velocity_elements);


        return psd_store_data_in_memory_array_.get_data_in_memory_array_()[num_psd_need_on_array][num_bufferarray_];


    }

    void ManagePsdDataOnCoordinate::SetRealPsd(std::vector<int_fast32_t> num_focus_real_elements,double set_val)const {

        std::int_fast32_t num_psd_need_on_array = GetNumArrayFromCoordinateOnRealPsdArray(num_focus_real_elements);

        real_psd_by_integrate_velocity_psd_store_data_in_memory_array_.get_data_in_memory_array_()[num_psd_need_on_array][num_calcarray_] = set_val;


    }

    void ManagePsdDataOnCoordinate::SetVelocityPsd(std::vector<int_fast32_t> num_focus_real_elements,
    std::vector<int_fast32_t> num_focus_velocity_elements,double set_val)const{

        std::int_fast32_t num_psd_need_on_array = GetNumArrayFromCoordinateOnAllPsdArray(num_focus_real_elements,num_focus_velocity_elements);


        psd_store_data_in_memory_array_.get_data_in_memory_array_()[num_psd_need_on_array][num_calcarray_] = set_val;


    }


}
}
