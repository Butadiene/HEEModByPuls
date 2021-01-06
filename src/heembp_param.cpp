#include "../include/heembp_param.hpp"
namespace heemodbypuls{
namespace heembp_param {


const std::vector<std::int_fast32_t> kRealEachGridNum{8,8,8}; 
const std::vector<std::int_fast32_t> kVelocityEachGridNum={3,3,3};
const std::int_fast32_t kPsdBufferNum = 2;

const std::vector<int_fast32_t> kFieldDimensionEachElemntsNum{3,3};//3D Electric Field and 3D magnetic Field
const std::int_fast32_t kFieldBufferNum = 1;

}  
}