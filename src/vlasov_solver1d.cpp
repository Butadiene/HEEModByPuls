#include "../include/vlasov_solver1d.hpp"

namespace heemodbypuls{
namespace vlasov1d_solver{

    Vlasov1DSolver::Vlasov1DSolver(manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd_data,manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field_data,
    const apply_boundary_condition::ApplyBoundaryCondition& in_apply_condition)
    :manage_psd_data_(in_manage_psd_data)
    ,manage_field_data_(in_manage_field_data)
    ,apply_boundary_condition_(in_apply_condition)
    {}

    




}
}
