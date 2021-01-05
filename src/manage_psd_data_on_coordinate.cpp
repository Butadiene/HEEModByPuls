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
        dimensional_integirity_check_ = true;
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

    void ManagePsdDataOnCoordinate::DimensionIntegrityTest(
        std::vector<int_fast32_t> num_focus_elements,
        std::vector<int_fast32_t> dimensional_define){

        if(dimensional_integirity_check_){

            bool dimension_num_correct = (num_focus_elements.size()==dimensional_define.size());

            if(!dimension_num_correct){
                
                std::cout<<"HEEModByPuls's error::The number of dimensions does not match"<<"\n";
                exit(1);
                
            }else{

                bool with_in_range = true;
                for(int i = 0;i<num_focus_elements.size();i++){
                    with_in_range *= (dimensional_define[i] > num_focus_elements[i]);
                }

                if(!with_in_range){
                    std::cout<<"HEEModByPuls's error::Trying to access an element outside the range"<<"\n";
                    exit(1);
                }

            }
            
        }
      
    }



    double ManagePsdDataOnCoordinate::GetRealPsd(std::vector<int_fast32_t> num_focus_real_elements){

        std::vector<int_fast32_t> coordinate_spec_real_each_grid_num = coordinate_spec_.get_real_each_grid_num_();

        DimensionIntegrityTest(num_focus_real_elements,coordinate_spec_real_each_grid_num);

        std::int_fast32_t num_psd_need_on_array = 0;

        for(int i = 0;i<num_focus_real_elements.size();i++){

            std::int_fast32_t amount_grid = 1;

            for(int j = 1;j<(num_focus_real_elements.size()-i);j++){
                amount_grid *= coordinate_spec_real_each_grid_num[i+j];
            }
            num_psd_need_on_array += num_focus_real_elements[i] * amount_grid;
        }

        return real_psd_by_integrate_velocity_psd_store_data_in_memory_array_.get_data_in_memory_array_()[num_psd_need_on_array][num_bufferarray_];


    }

    double ManagePsdDataOnCoordinate::GetVelocityPsd(std::vector<int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> num_focus_velocity_elements){

        std::vector<int_fast32_t> coordinate_spec_real_each_grid_num = coordinate_spec_.get_real_each_grid_num_();

        DimensionIntegrityTest(num_focus_real_elements,coordinate_spec_real_each_grid_num);

        std::vector<int_fast32_t> coordinate_spec_velocity_each_grid_num = coordinate_spec_.get_velocity_each_grid_num_();

        DimensionIntegrityTest(num_focus_velocity_elements,coordinate_spec_velocity_each_grid_num);

        std::int_fast32_t num_psd_need_on_array = 0;

        std::int_fast32_t velocity_grid_num = coordinate_spec_.get_velocity_grid_num_();

        for(int i = 0;i<num_focus_real_elements.size();i++){

            std::int_fast32_t amount_grid = 1;

            for(int j = 1;j<(num_focus_real_elements.size()-i);j++){
                amount_grid *= coordinate_spec_real_each_grid_num[i+j];
            }
            num_psd_need_on_array += num_focus_real_elements[i] * amount_grid * velocity_grid_num;
        }

        for(int i = 0;i<num_focus_velocity_elements.size();i++){

            std::int_fast32_t amount_grid = 1;

            for(int j = 1;j<(num_focus_velocity_elements.size()-i);j++){
                amount_grid *= coordinate_spec_velocity_each_grid_num[i+j];
            }
            num_psd_need_on_array += num_focus_velocity_elements[i] * amount_grid;
        }

        return psd_store_data_in_memory_array_.get_data_in_memory_array_()[num_psd_need_on_array][num_bufferarray_];


    }


}
}
