//include guard
#ifndef HEEMBP_INCLUDE_HEEMBP_PARAM
#define HEEMBP_INCLUCE_HEEMBP_PARAM

#include <cstdint>

namespace heembp_param {
    //This project(HEEModByPuls)'s Parameter without COORDINATE PARAMETER
    // if you want to customaize Coordinate parameter you should look at "/include/coordinatespec.hpp"
    // These are Global constant
    // Don't use variables! 
    // Don't use Pointer type constant

    constexpr std::int_fast8_t kRealDimensionNum = 1;
    constexpr std::int_fast8_t kVelocityDimensionNum = 2;
    constexpr std::int_fast16_t kRealGridNum[kRealDimensionNum] ={128}; 
    constexpr std::int_fast16_t kVelocityGridNum[kVelocityDimensionNum]={32,32};


}
#endif