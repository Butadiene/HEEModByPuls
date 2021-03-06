//include guard
#ifndef HEEBMP_INCLUDE_MANAGE_PSD_DATA_ON_COORDINATE
#define HEEBMP_INCLUDE_MANAGE_PSD_DATA_ON_COORDINATE

#include <numeric>
#include "../include/store_data_in_memory_array.hpp"
#include "../include/coordinate_spec.hpp"

namespace heemodbypuls{
namespace manage_psd_data_on_coordinate{

class ManagePsdDataOnCoordinate{

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
        std::int_fast32_t buffer_num = psd_store_data_in_memory_array_.get_buffer_num_();
        num_bufferarray_ = (num_bufferarray_ + 1 ) % buffer_num,
        num_calcarray_ = (num_calcarray_ + 1) % buffer_num;
    };
    void IntegrateVelocityPsdForRealPsd();

     std::int_fast32_t GetNumArrayFromCoordinateOnRealPsdArray (std::vector<int_fast32_t> num_focus_real_elements) const{
         return std::inner_product(num_focus_real_elements.begin(),num_focus_real_elements.end(),coordinate_spec_.get_real_grid_in_the_grid_num_().begin(),0.0);
     };

    std::int_fast32_t GetNumArrayFromCoordinateOnAllPsdArray(std::vector<int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> num_focus_velocity_elements) const{
        return std::inner_product(num_focus_real_elements.begin(),num_focus_real_elements.end(),coordinate_spec_.get_total_real_grid_in_the_grid_num_().begin(),0.0)+
        std::inner_product(num_focus_velocity_elements.begin(),num_focus_velocity_elements.end(),coordinate_spec_.get_total_velocity_grid_in_the_grid_num_().begin(),0.0);
    };
        
    

    double GetRealPsd(std::vector<int_fast32_t> num_focus_real_elements) const;

    double GetVelocityPsd(std::vector<int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> num_focus_velocity_elements) const;

    void SetRealPsd(std::vector<int_fast32_t> num_focus_real_elements,double set_val)const;

    void SetVelocityPsd(std::vector<int_fast32_t> num_focus_real_elements,
    std::vector<int_fast32_t> num_focus_velocity_elements,double set_val)const;

     coordinate_spec::CoordinateSpec get_coordinate_spec_() const {
        return coordinate_spec_;
    }

    //caution undifined access
     double GetValueFromNumArray(std::int_fast32_t num)const{
        return psd_store_data_in_memory_array_.get_data_in_memory_array_()[num][num_bufferarray_];
    }

    //caution undifined access
    void SetValueFromNumArray(std::int_fast32_t num,double value)const{
        psd_store_data_in_memory_array_.get_data_in_memory_array_()[num][num_calcarray_] = value;
    }

    std::int_fast32_t GetBufferNum() const {
        return psd_store_data_in_memory_array_.get_buffer_num_();
    }


};



}
}


#endif