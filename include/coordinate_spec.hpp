//include guard
#ifndef HEEMBP_INCLUDE_COORDINATE_SPEC 
#define HEEMBP_INCLUDE_COORDINATE_SPEC

#include <cstdint>
#include <numeric>
namespace coordinate_spec {
/*
    model description
    example: Real Space is 3D and Velocity Space is 3D
    F:Real Space density(integrate velocity space)
    f:Phase Space density
    array model: 
    F(x0[0],x1[0],x2[0]),
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
    F(x0[0],x1[0],x2[1]),
    f(x0[i],x1[0],x2[1],v0[0],v1[0],v2[0]),
    ...
    f(x0[maxx0],x1[maxx1],x2[maxx2],v0[maxv0],v1[maxv1],v2[maxv2]) 


*/
    constexpr std::int_fast8_t kRealDimensionNum = 1;
    constexpr std::int_fast8_t kVelocityDimensionNum = 2;
    constexpr std::int_fast16_t kRealGridNum[kRealDimensionNum] ={128}; 
    constexpr std::int_fast16_t kVelocityGridNum[kVelocityDimensionNum]={32,32};
    
    namespace {

    }
    /*
    constexpr std::int_fast64_t kTotalGridNum = std::accumulate(kRealGridNum[0], kRealGridNum[kRealDimensionNum], 1, [](int acc, int i) {
    return acc * i;
    
    });
    */
}
#endif