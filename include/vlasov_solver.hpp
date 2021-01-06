//include guard
#ifndef HEEMBP_INCLUDE_INITIALIZE_VLASOV_SOLVER
#define HEEMBP_INCLUDE_INITIALIZE_VLASOV_SOLVER

#include "../include/manage_psd_data_on_coordinate.hpp"
#include "../include/manage_field_data_on_coordinate.hpp"
#include "../include/apply_boundary_condition.hpp"

namespace heemodbypuls{
namespace vlasov_solver{

class VlasovSolver{

    manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& manage_psd_data_;

    manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& manage_field_data_;

    const apply_boundary_condition::ApplyBoundaryCondition& apply_boundary_condition_;

public:
    explicit VlasovSolver(manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd_data,manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field_data,const apply_boundary_condition::ApplyBoundaryCondition& in_apply_condition);



};






}
}



#endif