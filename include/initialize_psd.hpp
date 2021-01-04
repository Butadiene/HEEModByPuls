//include guard
#ifndef HEEMBP_INCLUDE_INITIALIZE_PSD
#define HEEMBP_INCLUDE_INITIALIZE_PSD

#include "../include/store_data_in_memory_array.hpp"

namespace heemodbypuls{
namespace initialize_psd{

class InitializePsd{
    const store_data_in_memory_array::StoreDataInMemoryArray& store_data_in_memory_array_;

public:
    explicit InitializePsd(const store_data_in_memory_array::StoreDataInMemoryArray& in_store_data_in_memory_array);

    void TestInitializeBy0and1();

};





}
}

#endif