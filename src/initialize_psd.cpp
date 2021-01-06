#include "../include/initialize_psd.hpp"

namespace heemodbypuls{
namespace initialize_psd{


    InitializePsd::InitializePsd(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_psd_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec)
    :psd_store_data_in_memory_array_(in_psd_store_data_in_memory_array)
    ,coordinate_spec_(in_coordinate_spec)
    {}

    void InitializePsd::TestInitializeBy0and1(){
        for(int i = 0;i<psd_store_data_in_memory_array_.get_data_in_memory_elements_num_();i++){
            for(int j = 0;j<psd_store_data_in_memory_array_.get_buffer_num_();j++){
                psd_store_data_in_memory_array_.get_data_in_memory_array_()[i][j] = j;
            }
        }
    }




}
}