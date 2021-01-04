#include "../include/initialize_psd.hpp"

namespace heemodbypuls{
namespace initialize_psd{


    InitializePsd::InitializePsd(const store_data_in_memory_array::StoreDataInMemoryArray& in_store_data_in_memory_array)
    :store_data_in_memory_array_(in_store_data_in_memory_array)
    {
      
    }

    void InitializePsd::TestInitializeBy0and1(){
        for(int i = 0;i<store_data_in_memory_array_.get_data_in_memory_elements_num_();i++){
            for(int j = 0;j<store_data_in_memory_array_.get_buffer_num_();j++){
                store_data_in_memory_array_.get_data_in_memory_array_()[i][j] = j;
            }
        }
    }




}
}