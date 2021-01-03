#include <iostream>
#include "../include/coordinate_spec.hpp"
#include "../include/manage_data_in_memory_array.hpp"
using namespace heemodbypuls;

int main(){
  
  coordinate_spec::CoordinateSpec coordinate_spec;
  manage_data_in_memory_array::ManageDataInMemoryArray manage_data_in_memory_array(coordinate_spec.get_total_grid_num_());
  manage_data_in_memory_array.TestAssignmentToDataArray();
  std::cout<< coordinate_spec.get_total_grid_num_() <<"\n";
  std::cout<< coordinate_spec.get_real_dimension_num_() <<"\n";
  std::cout<< coordinate_spec.get_velocity_dimension_num_() <<"\n";
  std::cout<< "\n";
}
