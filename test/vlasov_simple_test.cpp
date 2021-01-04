#include <iostream>
#include "../include/coordinate_spec.hpp"
#include "../include/store_data_in_memory_array.hpp"
#include "../include/initialize_psd.hpp"
using namespace heemodbypuls;

int main(){
  
  coordinate_spec::CoordinateSpec coordinate_spec;
  store_data_in_memory_array::StoreDataInMemoryArray store_data_in_memory_array(coordinate_spec.get_total_grid_num_());
  store_data_in_memory_array.TestAssignmentToDataArray();
  int ba = 3;
  initialize_psd::InitializePsd(ba);
  store_data_in_memory_array.TestWriteOutDataArrayToTerminal();
  std::cout<< coordinate_spec.get_total_grid_num_() <<"\n";
  std::cout<< coordinate_spec.get_real_dimension_num_() <<"\n";
  std::cout<< coordinate_spec.get_velocity_dimension_num_() <<"\n";
  std::cout<< "\n";
}
