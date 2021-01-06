#include "../include/initialize_psd.hpp"

namespace heemodbypuls{
namespace initialize_psd{


    InitializePsd::InitializePsd(
        const manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd)
    :manage_psd_(in_manage_psd)
    {}

    void InitializePsd::TestInitializeBy0and1(){

        coordinate_spec::CoordinateSpec coordinate_spec = manage_psd_.get_coordinate_spec_();

       // std::vector<int_fast32_t> num_focus_real_elements()

        //manage_psd_.SetRealPsd();
       
    }




}
}