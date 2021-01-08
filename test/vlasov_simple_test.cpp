#include <iostream>
#include <numeric>
#include "../include/coordinate_spec.hpp"
#include "../include/store_data_in_memory_array.hpp"
#include "../include/initialize_psd.hpp"
#include "../include/initialize_field.hpp"
#include "../include/manage_psd_data_on_coordinate.hpp"
#include "../include/manage_field_data_on_coordinate.hpp"
#include "../include/vlasov_solver.hpp"
using namespace heemodbypuls;

int main(){
  
  coordinate_spec::CoordinateSpec coordinate_spec;

  //for psd

  store_data_in_memory_array::StoreDataInMemoryArray psd_store_data_in_memory_array(
    coordinate_spec.get_total_grid_num_(),
    heembp_param::kPsdBufferNum);

  psd_store_data_in_memory_array.TestAssignmentToDataArray();

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

  initialize_psd::InitializePsd psd_initializer(manage_psd_data);


  for(int i = 0;i<manage_psd_data.GetBufferNum();i++){
    //psd_initializer.TestInitialize7();
    manage_psd_data.UpdateBufferParam();
    manage_psd_data.IntegrateVelocityPsdForRealPsd();
  }

  //psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();

  //real_psd_by_integrate_velocity_psd_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();

  std::vector<int_fast32_t> testvector{1,0,1};
  std::vector<int_fast32_t> testvector2{1,0,1};

  std::cout<<manage_psd_data.GetVelocityPsd(testvector,testvector2)<<"\n";

  
  //for field
  std::int_fast32_t array_elements_num_for_field 
        = coordinate_spec.get_real_grid_num_()*coordinate_spec.get_field_all_dimension_num_();

  store_data_in_memory_array::StoreDataInMemoryArray field_store_data_in_memory_array(
    array_elements_num_for_field,
    heembp_param::kFieldBufferNum);

    field_store_data_in_memory_array.TestAssignmentToDataArray();

  manage_field_data_on_coordinate::ManageFieldDataOnCoordinate manage_field_data(field_store_data_in_memory_array,coordinate_spec);

  initialize_field::InitializeField field_initializer(manage_field_data);

   for(int i = 0;i<manage_field_data.GetBufferNum();i++){
    //field_initializer.TestInitialize9();
    //manage_field_data.UpdateBufferParam();
   }

  field_store_data_in_memory_array.TestWriteOutDataArrayToTerminal();

  std::cout<<manage_field_data.GetFieldValue(1,testvector)[0]<<"\n";

  //apply_boundary_condition::ApplyBoundaryCondition boudary_condition_applyier(coordinate_spec);
  
  //vlasov_solver::VlasovSolver(manage_psd_data,manage_field_data,boudary_condition_applyier);



  std::cout<< coordinate_spec.get_total_grid_num_() <<"\n";
  std::cout<< coordinate_spec.get_real_dimension_num_() <<"\n";
  std::cout<< coordinate_spec.get_velocity_dimension_num_() <<"\n";
  std::cout<< "\n";
}
