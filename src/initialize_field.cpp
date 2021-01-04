#include "../include/initialize_field.hpp"

namespace heemodbypuls{
namespace initialize_field{


    InitializeField::InitializeField(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_field_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec)
    :field_store_data_in_memory_array_(in_field_store_data_in_memory_array)
    ,coordinate_spec_(in_coordinate_spec)
    {}

    void InitializeField::TestInitializeBy0and1(){
        for(int i = 0;i<field_store_data_in_memory_array_.get_data_in_memory_elements_num_();i++){
            for(int j = 0;j<field_store_data_in_memory_array_.get_buffer_num_();j++){
                field_store_data_in_memory_array_.get_data_in_memory_array_()[i][j] = j;
            }
        }
    }


}
}