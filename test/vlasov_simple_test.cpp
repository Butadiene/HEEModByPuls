#include <iostream>
#include <numeric>
#include "../include/coordinate_spec.hpp"
#include "../include/store_data_in_memory_array.hpp"
#include "../include/initialize_psd.hpp"
#include "../include/initialize_field.hpp"
#include "../include/manage_psd_data_on_coordinate.hpp"
#include "../include/manage_field_data_on_coordinate.hpp"
#include "../include/vlasov_solver1d.hpp"
using namespace heemodbypuls;

int main(){
  
  coordinate_spec::CoordinateSpec coordinate_spec;

  //for psd

  store_data_in_memory_array::StoreDataInMemoryArray psd_store_data_in_memory_array(
    coordinate_spec.get_total_grid_num_(),
    heembp_param::kPsdBufferNum);

  //for real psd
  store_data_in_memory_array::StoreDataInMemoryArray real_psd_by_integrate_velocity_psd_store_data_in_memory_array(
    coordinate_spec.get_real_grid_num_(),
    psd_store_data_in_memory_array.get_buffer_num_());

  manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate manage_psd_data(
    psd_store_data_in_memory_array,
    real_psd_by_integrate_velocity_psd_store_data_in_memory_array,
    coordinate_spec);

  initialize_psd::InitializePsd psd_initializer(manage_psd_data);

  for(int i = 0;i<manage_psd_data.GetBufferNum();i++){
   psd_initializer.Maxwellian1D1D(0);
    manage_psd_data.UpdateBufferParam();
    manage_psd_data.IntegrateVelocityPsdForRealPsd();
  }
//psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal()
  
  //for field
  std::int_fast32_t array_elements_num_for_field 
        = coordinate_spec.get_real_grid_num_()*coordinate_spec.get_field_all_dimension_num_();

  store_data_in_memory_array::StoreDataInMemoryArray field_store_data_in_memory_array(
    array_elements_num_for_field,
    heembp_param::kFieldBufferNum);

  field_store_data_in_memory_array.TestAssignmentToDataArray();

  manage_field_data_on_coordinate::ManageFieldDataOnCoordinate manage_field_data(field_store_data_in_memory_array,coordinate_spec);

  apply_boundary_condition::ApplyBoundaryCondition apply_boundary_condition(coordinate_spec);

  vlasov1d_solver::Vlasov1DSolver vlasov1d_solver(manage_psd_data,manage_field_data,apply_boundary_condition,coordinate_spec);
  vlasov1d_solver.solver();

 
  //psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();

}
