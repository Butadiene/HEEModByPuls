#include <numeric>
#include "../include/coordinate_spec.hpp"
#include "../include/heembp_param.hpp"
namespace heemodbypuls{
namespace coordinate_spec{ 


CoordinateSpec::CoordinateSpec()
:real_each_grid_num_(heembp_param::kRealEachGridNum)
,velocity_each_grid_num_(heembp_param::kVelocityEachGridNum)
{
    real_dimension_num_ = real_each_grid_num_.size();
    velocity_dimension_num_ = velocity_each_grid_num_.size();
    std::int_fast32_t real_grid_num = std::accumulate(real_each_grid_num_.begin(),real_each_grid_num_.end(),1,[](int acc, int i){
        return acc * i;
    });
    std::int_fast32_t velocity_grid_num = std::accumulate(velocity_each_grid_num_.begin(),velocity_each_grid_num_.end(),1,[](int acc, int i){
        return acc * i;
    });
    total_grid_num_ = real_grid_num * velocity_grid_num;

}

std::int_fast32_t CoordinateSpec::get_real_dimension_num_(){
    return real_dimension_num_;
}

std::int_fast32_t CoordinateSpec::get_velocity_dimension_num_(){
    return velocity_dimension_num_;
}

std::int_fast32_t CoordinateSpec::get_total_grid_num_(){
    return total_grid_num_;
}

std::vector<std::int_fast32_t> CoordinateSpec::get_real_each_grid_num_(){
    return real_each_grid_num_;
}

std::vector<std::int_fast32_t> CoordinateSpec::get_velocity_each_grid_num_(){
    return velocity_each_grid_num_;
}



}
}