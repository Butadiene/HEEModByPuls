//include guard
#ifndef HEEMBP_INCLUDE_VLASOV_SOLVER1D
#define HEEMBP_INCLUDE_VLASOV_SOLVER1D

#include "../include/math_common.hpp"
#include "../include/manage_psd_data_on_coordinate.hpp"
#include "../include/manage_field_data_on_coordinate.hpp"
#include "../include/apply_boundary_condition.hpp"

namespace heemodbypuls{
namespace vlasov1d_solver{

class Vlasov1DSolver{

    manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& manage_psd_data_;

    manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& manage_field_data_;

    const apply_boundary_condition::ApplyBoundaryCondition& apply_boundary_condition_;

    const coordinate_spec::CoordinateSpec& coordinate_spec_;



    const std::int_fast32_t all_steps_ = 64 ;


    //void set_field

   
    double calc_advection(double cfl_num,double fi_minus2,double fi_minus1, double fi,double fi_plus1,double fi_plus2);

   
  

public:
    explicit Vlasov1DSolver(manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd_data,manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field_data,const apply_boundary_condition::ApplyBoundaryCondition& in_apply_condition, const coordinate_spec::CoordinateSpec& in_coordinate_spec);

    
    void field_update();

    void solver();


};






}
}



#endif