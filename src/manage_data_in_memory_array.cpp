#include<new>
#include<iostream>
#include "../include/manage_data_in_memory_array.hpp"


namespace heemodbypuls{
namespace manage_data_in_memory_array{

    ManageDataInMemoryArray::ManageDataInMemoryArray(std::int_fast32_t require_elements_num) {
        data_in_memory_elements_num_ = require_elements_num;
        data_in_memory_array_ = new double*[data_in_memory_elements_num_];
        try{
            for (int i = 0; i<data_in_memory_elements_num_; i++){
                data_in_memory_array_[i] = new double[buffer_num_];
            }
        }
        catch(std::bad_alloc){
            std::cout<<"HEEModByPuls's error::failed to secure memory\n";
            exit(1);
        }

    }

    ManageDataInMemoryArray::~ManageDataInMemoryArray(){
        for (int i = 0; i<data_in_memory_elements_num_; i++){
            delete[] data_in_memory_array_[i];
            data_in_memory_array_[i] = 0;//Assign 0 to used pointer
        }

        delete[] data_in_memory_array_;
        data_in_memory_array_ = 0; //Assign 0 to used pointer

    }

    void ManageDataInMemoryArray::TestAssignmentToDataArray(){
        for(int i = 0;i<data_in_memory_elements_num_;i++){
            for(int j = 0;j<buffer_num_;j++){
                data_in_memory_array_[i][j] = double(i*(j+1));
              //  std::cout<<data_in_memory_array_[i][j];
              //  std::cout<<"\n";
            }
        }
    }


    std::int_fast32_t ManageDataInMemoryArray::get_buffer_num_(){
        return buffer_num_;
    }

    std::int_fast32_t ManageDataInMemoryArray::get_data_in_memory_elements_num_(){
        return data_in_memory_elements_num_;
    }
    
    double** ManageDataInMemoryArray::get_data_in_memory_array_pointer_pointer(){
        return data_in_memory_array_;
    }


}
}