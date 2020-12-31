//include guard
#ifndef HEEMBP_INCLUDE_COORDINATE_SPEC 
#define HEEMBP_INCLUDE_COORDINATE_SPEC

#include <cstdint>

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
    class CoordinateSpec{
    // テストコードで書く、格子設定クラスの試作　
    //今回のシミュレーション用を愚直に書くが、将来的には格子設定クラスのInterfaceを用意したい
        static const std::int_fast8_t realDimensionNum = kRealDimensionNum;
        static const std::int_fast8_t velocityDimensionNum = kVelocityDimensionNum;
        static const std::int_fast16_t realGridNum[realDimensionNum];
        static const std::int_fast16_t velocityGridNum[kVelocityDimensionNum];
        std::int_fast32_t totalGridNum;
        std::int_fast32_t calcTotalGridNum();
        
    public:
        CoordinateSpec();

        

    };
    

}
#endif