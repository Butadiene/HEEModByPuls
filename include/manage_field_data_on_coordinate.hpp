//include guard
#ifndef HEEBMP_INCLUDE_MANAGE_FIELD_DATA_ON_COORDINATE
#define HEEBMP_INCLUDE_MANAGE_FIELD_DATA_ON_COORDINATE

#include "../include/store_data_in_memory_array.hpp"
#include "../include/coordinate_spec.hpp"

namespace heemodbypuls{
namespace manage_field_data_on_coordinate{

class ManageFieldDataOnCoordinate{

    std::int_fast32_t num_bufferarray_;
    std::int_fast32_t num_calcarray_;

    const store_data_in_memory_array::StoreDataInMemoryArray& field_store_data_in_memory_array_;
    const coordinate_spec::CoordinateSpec& coordinate_spec_;

public:
    explicit ManageFieldDataOnCoordinate(
        const store_data_in_memory_array::StoreDataInMemoryArray& in_field_store_data_in_memory,
        const coordinate_spec::CoordinateSpec& in_coordinate_spec);

        void UpdateBufferParam(){
        std::int_fast32_t buffer_num = field_store_data_in_memory_array_.get_buffer_num_();
        num_bufferarray_ = (num_bufferarray_ + 1 ) % buffer_num,
        num_calcarray_ = (num_calcarray_ + 1) % buffer_num;
    };

    std::vector<std::int_fast32_t> GetNumArrayFromCoordinateOnFieldArray(std::int_fast32_t num_field_identify,std::vector<std::int_fast32_t> num_focus_real_elements) const;

    std::vector<std::int_fast32_t> GetFieldValue (std::int_fast32_t num_field_identify,std::vector<std::int_fast32_t> num_focus_real_elements) const;

    void SetFieldValue (std::int_fast32_t num_field_identify,std::vector<std::int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> set_value);

    coordinate_spec::CoordinateSpec get_coordinate_spec_(){
        return coordinate_spec_;
    }

};




}
}

#endif