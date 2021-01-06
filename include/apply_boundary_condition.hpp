//include guard
#ifndef HEEMBP_INCLUDE_APPLY_BOUNDARY_CONDITION
#define HEEMBP_INCLUDE_APPLY_BOUNDARY_CONDITION

#include <cstdint>
#include <vector>
#include "../include/coordinate_spec.hpp"
namespace heemodbypuls{
namespace apply_boundary_condition{

class ApplyBoundaryCondition{

    const coordinate_spec::CoordinateSpec& coordinate_spec_;

public:
    explicit ApplyBoundaryCondition( const coordinate_spec::CoordinateSpec& in_coordinate_spec);
    
    


};








}
}


#endif