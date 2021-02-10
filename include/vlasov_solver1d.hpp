//include guard
#ifndef HEEMBP_INCLUDE_VLASOV_SOLVER1D
#define HEEMBP_INCLUDE_VLASOV_SOLVER1D

#include "../include/manage_psd_data_on_coordinate.hpp"
#include "../include/manage_field_data_on_coordinate.hpp"
#include "../include/apply_boundary_condition.hpp"

namespace heemodbypuls{
namespace vlasov1d_solver{

class Vlasov1DSolver{

    manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& manage_psd_data_;

    manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& manage_field_data_;

    const apply_boundary_condition::ApplyBoundaryCondition& apply_boundary_condition_;

    //void set_field
    

public:
    explicit Vlasov1DSolver(manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd_data,manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field_data,const apply_boundary_condition::ApplyBoundaryCondition& in_apply_condition);




};






}
}



#endif