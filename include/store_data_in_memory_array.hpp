//include guard
#ifndef HEEMBP_INCLUDE_STORE_DATA_IN_MEMORY_ARRAY 
#define HEEMBP_INCLUDE_STORE_DATA_IN_MEMORY_ARRAY


#include<cstdint>
namespace heemodbypuls{
namespace store_data_in_memory_array{

// in the future, maybe we want to use "Singleton"
/* store data array class
    Do not create multiple instance
*/
class StoreDataInMemoryArray{
    const std::int_fast32_t buffer_num_ = 2;
    std::int_fast32_t data_in_memory_elements_num_;
    double** data_in_memory_array_; //pointer to array data
    //in the future, we want to use template for array data type


public:
    StoreDataInMemoryArray(std::int_fast32_t require_elements_num);
    ~ StoreDataInMemoryArray();

    void TestAssignmentToDataArray();

    void TestWriteOutDataArrayToTerminal();
    
    std::int_fast32_t get_buffer_num_();

    std::int_fast32_t get_data_in_memory_elements_num_();

    double** get_data_in_memory_array_();




};

}
}

#endif