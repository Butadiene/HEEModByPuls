//include guard
#ifndef HEEBMP_INCLUDE_MANAGE_PSD_DATA_ON_COORDINATE
#define HEEBMP_INCLUDE_MANAGE_PSD_DATA_ON_COORDINATE

#include "../include/store_data_in_memory_array.hpp"
#include "../include/coordinate_spec.hpp"

namespace heemodbypuls{
namespace manage_psd_data_on_coordinate{

class ManagePsdDataOnCoordinate{

    bool dimensional_integirity_check_;

    std::int_fast32_t num_bufferarray_;
    std::int_fast32_t num_calcarray_;

    const store_data_in_memory_array::StoreDataInMemoryArray& psd_store_data_in_memory_array_;
    const store_data_in_memory_array::StoreDataInMemoryArray& real_psd_by_integrate_velocity_psd_store_data_in_memory_array_;
    const coordinate_spec::CoordinateSpec& coordinate_spec_;



public:
    explicit ManagePsdDataOnCoordinate(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_psd_store_data_in_memory_array,
        const store_data_in_memory_array::StoreDataInMemoryArray& in_real_psd_by_integrate_velocity_psd_store_data_in_memory_array,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec);

    void UpdateBufferParam(){
        num_bufferarray_ = (num_bufferarray_ + 1 ) % 2,
        num_calcarray_ = (num_calcarray_ + 1) % 2;
    };
    void IntegrateVelocityPsdForRealPsd();
    
    void set_DimensionIntegrityTest(bool execute_test){
        dimensional_integirity_check_ = execute_test;
    };
        
    void DimensionIntegrityTest(std::vector<int_fast32_t> num_focus_elements,std::vector<int_fast32_t> dimensional_define);//if do set_DimensionIntegrityTest(false), this method don't work

    double GetRealPsd(std::vector<int_fast32_t> num_focus_real_elements);

    double GetVelocityPsd(std::vector<int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> num_focus_velocity_elements);


};



}
}


#endif