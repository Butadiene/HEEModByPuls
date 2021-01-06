#include "../include/initialize_field.hpp"

namespace heemodbypuls{
namespace initialize_field{


    InitializeField::InitializeField(const manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field)
    :manage_field_(in_manage_field)
    {}

    void InitializeField::TestInitialize9(){
        coordinate_spec::CoordinateSpec coordinate_spec = manage_field_.get_coordinate_spec_();

        for(int i = 0;i<coordinate_spec.get_field_all_dimension_num_()*coordinate_spec.get_real_grid_num_();i++){
            manage_field_.SetValueFromNumArray(i,9.0);
        }

    }


}
}