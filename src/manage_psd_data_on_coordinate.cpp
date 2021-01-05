#include "../include/manage_psd_data_on_coordinate.hpp"
#include <iostream>
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
        dimensional_integirity_ = true;
        num_bufferarray_ = 0;
        num_calcarray_ = (num_bufferarray_ + 1 ) % 2;
    }

    void ManagePsdDataOnCoordinate::IntegrateVelocityPsdForRealPsd(){
        std::int_fast32_t real_grid_num = coordinate_spec_.get_real_grid_num_();
        std::int_fast32_t velocity_grid_num = coordinate_spec_.get_velocity_grid_num_();

        for(int i = 0; i < real_grid_num; i++){
            std::int_fast32_t array_num_integrate_real_grid = i * velocity_grid_num; 
            double integrate_each_real_psd = double(0.0);
            for(int j = 0; j < velocity_grid_num; j++){
                integrate_each_real_psd += 
                    psd_store_data_in_memory_array_.get_data_in_memory_array_()[array_num_integrate_real_grid][num_bufferarray_];
            }
            real_psd_by_integrate_velocity_psd_store_data_in_memory_array_.get_data_in_memory_array_()[i][num_bufferarray_] = integrate_each_real_psd;
        }
    }



    double ManagePsdDataOnCoordinate::GetRealPsd(std::vector<int_fast32_t> num_focus_real_elements){
        if(dimensional_integirity_){

            bool dimension_num_correct = (num_focus_real_elements.size()==coordinate_spec_.get_real_dimension_num_());

            if(!dimension_num_correct){
                
                std::cout<<"HEEModByPuls's error::The number of dimensions does not match";
                exit(1);
               
            }
            
        }

        std::int_fast32_t real_dimension_num = coordinate_spec_.get_real_dimension_num_();

        

        for(int i = 0;i<real_dimension_num;i++){
            
        }
 
    
       


    }

    double ManagePsdDataOnCoordinate::GetVelocityPsd(){

    }


}
}
