//include guard
#ifndef HEEMBP_INCLUDE_INITIALIZE_FIELD
#define HEEMBP_INCLUDE_INITIALIZE_FIELD

#include "../include/store_data_in_memory_array.hpp"
#include "../include/coordinate_spec.hpp"

namespace heemodbypuls{
namespace initialize_field{

class InitializeField{
    const store_data_in_memory_array::StoreDataInMemoryArray& field_store_data_in_memory_array_;
    const coordinate_spec::CoordinateSpec& coordinate_spec_;

public:
    explicit InitializeField(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_field_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec);

     void TestInitializeBy0and1();

};

    
}
}


#endif