#include <iostream>
#include "../include/coordinate_spec.hpp"
#include "../include/store_data_in_memory_array.hpp"
#include "../include/initialize_psd.hpp"
#include "../include/initialize_field.hpp"
using namespace heemodbypuls;

int main(){
  
  coordinate_spec::CoordinateSpec coordinate_spec;

  //for psd
  std::int_fast32_t array_elements_num_for_psd = coordinate_spec.get_total_grid_num_();
  store_data_in_memory_array::StoreDataInMemoryArray psd_store_data_in_memory_array(
    array_elements_num_for_psd,
    heembp_param::kPsdBufferNum);

  psd_store_data_in_memory_array.TestAssignmentToDataArray();

  initialize_psd::InitializePsd psd_initializer(
    psd_store_data_in_memory_array,
    coordinate_spec);

  psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();



  //for real psd
  store_data_in_memory_array::StoreDataInMemoryArray real_psd_by_integrate_velocity_psd_store_data_in_memory_array(
    coordinate_spec.get_real_grid_num_(),
    heembp_param::kPsdBufferNum);


  // create manage psd data instance

  //for field
  std::int_fast32_t array_elements_num_for_field 
        = coordinate_spec.get_real_dimension_num_()*coordinate_spec.get_real_grid_num_();

  store_data_in_memory_array::StoreDataInMemoryArray field_store_data_in_memory_array(
    array_elements_num_for_field,
    heembp_param::kFieldBufferNum);

  initialize_field::InitializeField field_initializer(field_store_data_in_memory_array,coordinate_spec);

  field_initializer.TestInitializeBy0and1();

  field_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();



  std::cout<< coordinate_spec.get_total_grid_num_() <<"\n";
  std::cout<< coordinate_spec.get_real_dimension_num_() <<"\n";
  std::cout<< coordinate_spec.get_velocity_dimension_num_() <<"\n";
  std::cout<< "\n";
}
