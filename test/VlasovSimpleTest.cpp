#include <iostream>
#include "../include/coordinate_spec.hpp"


int main()
{
  coordinate_spec::CoordinateSpec coordinate_spec;
  std::cout<< coordinate_spec.get_total_grid_num_() <<"\n";
  std::cout<< coordinate_spec.get_real_dimension_num_() <<"\n";
  std::cout<< coordinate_spec.get_velocity_dimension_num_() <<"\n";
  std::cout<< "\n";
}
