//include guard
#ifndef HEEMBP_INCLUDE_INITIALIZE_FIELD
#define HEEMBP_INCLUDE_INITIALIZE_FIELD

#include "../include/manage_field_data_on_coordinate.hpp"

namespace heemodbypuls{
namespace initialize_field{

class InitializeField{
    const manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& manage_field_;

public:
    explicit InitializeField(const manage_field_data_on_coordinate::ManageFieldDataOnCoordinate& in_manage_field_);

    void TestInitialize9();

};

    
}
}


#endif