#include <cstdint>
#include "../include/coordinate_spec.hpp"
#include "../include/heembp_param.hpp"

namespace coordinate_spec{ 
    CoordinateSpec::CoordinateSpec()
    :realDimensionNum(heembp_param::kRealDimensionNum)
    :velocityDimensionNum(heembp_param::kVelocityDimensionNum)
    {

    }

    std::int_fast32_t CoordinateSpec::calcTotalGridNum(){

    }


}