#include <iostream>
#include <numeric>
#include "../include/manage_field_data_on_coordinate.hpp"

namespace heemodbypuls{
namespace manage_field_data_on_coordinate{

    ManageFieldDataOnCoordinate::ManageFieldDataOnCoordinate(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_field_store_data_in_memory,
            const coordinate_spec::CoordinateSpec& in_coordinate_spec)
        :field_store_data_in_memory_array_(in_field_store_data_in_memory)
        ,coordinate_spec_(in_coordinate_spec)
    {
        num_bufferarray_ = 0;
        num_calcarray_ = (num_bufferarray_ + 1 ) % field_store_data_in_memory_array_.get_buffer_num_();
    }


    std::vector<std::int_fast32_t> ManageFieldDataOnCoordinate::GetNumArrayFromCoordinateOnFieldArray(
        std::int_fast32_t num_field_identify,
        std::vector<std::int_fast32_t> num_focus_real_elements) const
    {

        std::int_fast32_t num_field_need_on_array = std::inner_product(num_focus_real_elements.begin(),num_focus_real_elements.end(),coordinate_spec_.get_real_grid_in_the_grid_num_().begin(),0.0);

        num_field_need_on_array *= coordinate_spec_.get_field_all_dimension_num_();

        std::int_fast32_t elements_sum_before_focus_field = 0;
        for(int i = 0;i<num_field_identify;i++){
            elements_sum_before_focus_field += coordinate_spec_.get_field_dimension_each_num_()[i];
        }

        num_field_need_on_array += elements_sum_before_focus_field;

        std::int_fast32_t elements_focus_field_num = coordinate_spec_.get_field_dimension_each_num_()[num_field_identify];

        std::vector<int_fast32_t> out(elements_focus_field_num);

        for(int i = 0;i<elements_focus_field_num;i++){
            out[i] = num_field_need_on_array + i; 
        }

        return out;

    }

    std::vector<std::int_fast32_t> ManageFieldDataOnCoordinate::GetFieldValue (
        std::int_fast32_t num_field_identify,
        std::vector<std::int_fast32_t> num_focus_real_elements) const
    {

        std::vector<int_fast32_t> num_array_on_field_array =  GetNumArrayFromCoordinateOnFieldArray(num_field_identify,num_focus_real_elements);

        std::int_fast32_t elements_focus_field_num = num_array_on_field_array.size();

        std::vector<int_fast32_t> out(elements_focus_field_num);

        for(int i = 0;i<elements_focus_field_num;i++){
            out[i] = field_store_data_in_memory_array_.get_data_in_memory_array_()[num_array_on_field_array[i]][num_bufferarray_]; 
        }

        return out;
    
    }

    void ManageFieldDataOnCoordinate::SetFieldValue (
        std::int_fast32_t num_field_identify,
        std::vector<std::int_fast32_t> num_focus_real_elements,
        std::vector<int_fast32_t> set_value) const
    {


        std::vector<int_fast32_t> num_array_on_field_array =  GetNumArrayFromCoordinateOnFieldArray(num_field_identify,num_focus_real_elements);

        std::int_fast32_t elements_focus_field_num = num_array_on_field_array.size();

        if(set_value.size() != elements_focus_field_num){
    
            std::cout<<"HEEModByPuls's error::Trying to assign a vector of a different dimension"<<"\n";
            exit(1);
            
        }

        for(int i = 0;i<elements_focus_field_num;i++){
            field_store_data_in_memory_array_.get_data_in_memory_array_()[num_array_on_field_array[i]][num_calcarray_] = set_value[i]; 
        }



    }





}
}