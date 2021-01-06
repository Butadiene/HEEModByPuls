#include<new>
#include<iostream>
#include "../include/store_data_in_memory_array.hpp"


namespace heemodbypuls{
namespace store_data_in_memory_array{


    StoreDataInMemoryArray::StoreDataInMemoryArray(
        std::int_fast32_t require_elements_num,
        std::int_fast32_t in_buffer_num)
    :buffer_num_(in_buffer_num)
    {
        data_in_memory_elements_num_ = require_elements_num;
        data_in_memory_array_ = new double*[data_in_memory_elements_num_];
        try{
            for (int i = 0; i<data_in_memory_elements_num_; i++){
                data_in_memory_array_[i] = new double[buffer_num_];
            }
        }
        catch(std::bad_alloc){
            std::cout<<"HEEModByPuls's error::failed to secure memory<<\n";
            exit(1);
        }

    }

    StoreDataInMemoryArray::~StoreDataInMemoryArray(){
        for (int i = 0; i<data_in_memory_elements_num_; i++){
            delete[] data_in_memory_array_[i];
            data_in_memory_array_[i] = 0;//Assign 0 to used pointer
        }

        delete[] data_in_memory_array_;
        data_in_memory_array_ = 0; //Assign 0 to used pointer

    }

    void StoreDataInMemoryArray::TestAssignmentToDataArray(){
        for(int i = 0;i<data_in_memory_elements_num_;i++){
            for(int j = 0;j<buffer_num_;j++){
                data_in_memory_array_[i][j] = double(i*(j+1));
            }
        }
    }

    void StoreDataInMemoryArray::TestWriteOutDataArrayToTerminal() const {
        for(int i = 0;i<data_in_memory_elements_num_;i++){
            for(int j = 0;j<buffer_num_;j++){
                std::cout<<data_in_memory_array_[i][j];
                std::cout<<"\n";
            }
        }
    }

}
}