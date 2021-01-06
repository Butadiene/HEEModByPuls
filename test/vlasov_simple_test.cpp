#include <iostream>
#include <numeric>
#include "../include/coordinate_spec.hpp"
#include "../include/store_data_in_memory_array.hpp"
#include "../include/initialize_psd.hpp"
#include "../include/initialize_field.hpp"
#include "../include/manage_psd_data_on_coordinate.hpp"
#include "../include/manage_field_data_on_coordinate.hpp"
using namespace heemodbypuls;

int main(){
  
  coordinate_spec::CoordinateSpec coordinate_spec;

  //for psd

  store_data_in_memory_array::StoreDataInMemoryArray psd_store_data_in_memory_array(
    coordinate_spec.get_total_grid_num_(),
    heembp_param::kPsdBufferNum);

  psd_store_data_in_memory_array.TestAssignmentToDataArray();

/*
  initialize_psd::InitializePsd psd_initializer(
    psd_store_data_in_memory_array,
    coordinate_spec);
*/
  //psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();



  //for real psd
  store_data_in_memory_array::StoreDataInMemoryArray real_psd_by_integrate_velocity_psd_store_data_in_memory_array(
    coordinate_spec.get_real_grid_num_(),
    psd_store_data_in_memory_array.get_buffer_num_());

  real_psd_by_integrate_velocity_psd_store_data_in_memory_array.TestAssignmentToDataArray();

  // create manage psd data instance

  manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate manage_psd_data(
    psd_store_data_in_memory_array,
    real_psd_by_integrate_velocity_psd_store_data_in_memory_array,
    coordinate_spec);

  //manage_psd_data.IntegrateVelocityPsdForRealPsd();

  std::vector<int_fast32_t> test_real_array {7,7,7};
  std::vector<int_fast32_t> test_velocity_array {2,2,2};

  manage_psd_data.SetVelocityPsd(test_real_array,test_velocity_array,7776);

  //psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();

  
  //for field
  std::int_fast32_t array_elements_num_for_field 
        = coordinate_spec.get_real_grid_num_()*coordinate_spec.get_field_all_dimension_num_();

  store_data_in_memory_array::StoreDataInMemoryArray field_store_data_in_memory_array(
    array_elements_num_for_field,
    heembp_param::kFieldBufferNum);

  initialize_field::InitializeField field_initializer(field_store_data_in_memory_array,coordinate_spec);

  field_initializer.TestInitialize();

  manage_field_data_on_coordinate::ManageFieldDataOnCoordinate manage_field_data(field_store_data_in_memory_array,coordinate_spec);

  manage_field_data.SetFieldValue(1,test_real_array,test_real_array);

  field_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();

 


  std::cout<< coordinate_spec.get_total_grid_num_() <<"\n";
  std::cout<< coordinate_spec.get_real_dimension_num_() <<"\n";
  std::cout<< coordinate_spec.get_velocity_dimension_num_() <<"\n";
  std::cout<< "\n";
}
