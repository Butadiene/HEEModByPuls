//include guard
#ifndef HEEMBP_INCLUDE_COORDINATE_SPEC 
#define HEEMBP_INCLUDE_COORDINATE_SPEC

#include <cstdint>
#include <vector>
#include "../include/heembp_param.hpp"
namespace heemodbypuls{
namespace coordinate_spec {
/*
    model description
    example: Real Space is 3D and Velocity Space is 3D
    f:Phase Space density
    array model: 
    f(x0[0],x1[0],x2[0],v0[0],v1[0],v2[0]),
    f(x0[0],x1[0],x2[0],v0[0],v1[0],v2[1]),
    f(x0[0],x1[0],x2[0],v0[0],v1[0],v2[2]),
    ...
    f(x0[0],x1[0],x2[0],v0[0],v1[0],v2[maxv2]),
    f(x0[0],x1[0],x2[0],v0[0],v1[1],v2[0]),
    ...
    f(x0[0],x1[0],x2[0],v0[0],v1[1],v2[maxv2]),
    f(x0[0],x1[0],x2[0],v0[0],v1[2],v2[0]),
    ...
    f(x0[0],x1[0],x2[0],v0[maxv0],v1[maxv1],v2[maxv2]),
    f(x0[i],x1[0],x2[1],v0[0],v1[0],v2[0]),
    ...
    f(x0[maxx0],x1[maxx1],x2[maxx2],v0[maxv0],v1[maxv1],v2[maxv2]) 


*/



// Coordinate Specification
class CoordinateSpec{
    
    std::int_fast32_t real_dimension_num_;
    std::int_fast32_t velocity_dimension_num_;
    std::int_fast32_t real_grid_num_;
    std::int_fast32_t velocity_grid_num_;
    std::int_fast32_t total_grid_num_;

    std::vector<std::int_fast32_t> real_each_grid_num_;
    std::vector<std::int_fast32_t> velocity_each_grid_num_;

public:
    CoordinateSpec();
    std::int_fast32_t get_real_dimension_num_() const {return real_dimension_num_;}
    std::int_fast32_t get_velocity_dimension_num_() const {return velocity_dimension_num_;}
    std::int_fast32_t get_real_grid_num_() const {return real_grid_num_;}
    std::int_fast32_t get_velocity_grid_num_() const {return velocity_grid_num_;}
    std::int_fast32_t get_total_grid_num_() const {return total_grid_num_;}
    std::vector<std::int_fast32_t> get_real_each_grid_num_() const {return real_each_grid_num_;}
    std::vector<std::int_fast32_t> get_velocity_each_grid_num_()const {return velocity_each_grid_num_;}

};


}
}
#endif