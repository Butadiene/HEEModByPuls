//include guard
#ifndef HEEMBP_INCLUDE_HEEMBP_PARAM
#define HEEMBP_INCLUCE_HEEMBP_PARAM

#include <vector>
#include <cstdint>
namespace heemodbypuls{
namespace heembp_param {


extern const std::vector<std::int_fast32_t> kRealEachGridNum; 
extern const std::vector<std::int_fast32_t> kVelocityEachGridNum;
extern const std::int_fast32_t kPsdBufferNum;

extern const std::vector<std::int_fast32_t> kFieldDimensionEachElemntsNum;
extern const std::int_fast32_t kFieldBufferNum;

}
}
#endif