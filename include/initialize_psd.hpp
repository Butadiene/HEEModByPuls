//include guard
#ifndef HEEMBP_INCLUDE_INITIALIZE_PSD
#define HEEMBP_INCLUDE_INITIALIZE_PSD

#include "../include/manage_psd_data_on_coordinate.hpp"

namespace heemodbypuls{
namespace initialize_psd{

    class InitializePsd{
        const manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& manage_psd_;

    public:
        explicit InitializePsd(
            const manage_psd_data_on_coordinate::ManagePsdDataOnCoordinate& in_manage_psd
        );

        void TestInitialize7();

        void Maxwellian(std::int_fast32_t teperature);

    };





}
}

#endif