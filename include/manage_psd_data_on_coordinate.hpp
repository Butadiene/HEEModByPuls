//include guard
#ifndef HEEBMP_INCLUDE_MANAGE_PSD_DATA_ON_COORDINATE
#define HEEBMP_INCLUDE_MANAGE_PSD_DATA_ON_COORDINATE

#include "../include/store_data_in_memory_array.hpp"
#include "../include/coordinate_spec.hpp"

namespace heemodbypuls{
namespace manage_psd_data_on_coordinate{

class ManagePsdDataOnCoordinate{

    //std::int_fast32_t bufferarray

    const store_data_in_memory_array::StoreDataInMemoryArray& psd_store_data_in_memory_array_;
    const store_data_in_memory_array::StoreDataInMemoryArray& real_psd_by_integrate_velocity_psd_store_data_in_memory_array_;
    const coordinate_spec::CoordinateSpec& coordinate_spec_;

public:
    explicit ManagePsdDataOnCoordinate(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_psd_store_data_in_memory_array,
        const store_data_in_memory_array::StoreDataInMemoryArray& in_real_psd_by_integrate_velocity_psd_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec);

    void IntegrateVelocityPsdForRealPsd();

};



}
}


#endif