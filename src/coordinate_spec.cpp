#include <numeric>
#include <iostream>
#include "../include/coordinate_spec.hpp"
#include "../include/heembp_param.hpp"
namespace heemodbypuls{
namespace coordinate_spec{ 


CoordinateSpec::CoordinateSpec()
:real_each_grid_num_(heembp_param::kRealEachGridNum)
,velocity_each_grid_num_(heembp_param::kVelocityEachGridNum)
{
    real_dimension_num_ = real_each_grid_num_.size(),
    velocity_dimension_num_ = velocity_each_grid_num_.size(),

    real_grid_num_ = std::accumulate(
        real_each_grid_num_.begin(),real_each_grid_num_.end(),1,[](int acc, int i){return acc * i;}),

    velocity_grid_num_ = std::accumulate(
        velocity_each_grid_num_.begin(),velocity_each_grid_num_.end(),1,[](int acc, int i){return acc * i;}),

    total_grid_num_ = real_grid_num_ * velocity_grid_num_,

    dimensional_integirity_check_ = true;

}




void CoordinateSpec::DimensionIntegrityTest(
        std::vector<int_fast32_t> num_focus_elements,
        std::vector<int_fast32_t> dimensional_define) const{

        if(dimensional_integirity_check_){

            bool dimension_num_correct = (num_focus_elements.size()==dimensional_define.size());

            if(!dimension_num_correct){
                
                std::cout<<"HEEModByPuls's error::The number of dimensions does not match"<<"\n";
                exit(1);
                
            }else{

                bool with_in_range = true;
                for(int i = 0;i<num_focus_elements.size();i++){
                    with_in_range *= (dimensional_define[i] > num_focus_elements[i]);
                }

                if(!with_in_range){
                    std::cout<<"HEEModByPuls's error::Trying to access an element outside the range"<<"\n";
                    exit(1);
                }

            }
            
        }
      
    }




std::int_fast32_t CoordinateSpec::GetNumArrayFromCoordinateOnRealPsdArray(std::vector<int_fast32_t> num_focus_real_elements) const{
    std::vector<int_fast32_t> real_each_grid_num = real_each_grid_num_;

        DimensionIntegrityTest(num_focus_real_elements,real_each_grid_num);

        std::int_fast32_t num_psd_need_on_array = 0;

        for(int i = 0;i<num_focus_real_elements.size();i++){

            std::int_fast32_t amount_grid = 1;

            for(int j = 1;j<(num_focus_real_elements.size()-i);j++){
                amount_grid *= real_each_grid_num[i+j];
            }
            num_psd_need_on_array += num_focus_real_elements[i] * amount_grid;
        }
    return num_psd_need_on_array;
}

std::int_fast32_t CoordinateSpec::GetNumArrayFromCoordinateOnAllPsdArray(std::vector<int_fast32_t> num_focus_real_elements,std::vector<int_fast32_t> num_focus_velocity_elements) const{

    std::vector<int_fast32_t> real_each_grid_num = real_each_grid_num_;

    DimensionIntegrityTest(num_focus_real_elements,real_each_grid_num);

    std::vector<int_fast32_t> velocity_each_grid_num =velocity_each_grid_num_;

    DimensionIntegrityTest(num_focus_velocity_elements,velocity_each_grid_num);

    std::int_fast32_t num_psd_need_on_array = 0;

    std::int_fast32_t velocity_grid_num = velocity_grid_num_;

    for(int i = 0;i<num_focus_real_elements.size();i++){

        std::int_fast32_t amount_grid = 1;

        for(int j = 1;j<(num_focus_real_elements.size()-i);j++){
            amount_grid *= real_each_grid_num[i+j];
        }
        num_psd_need_on_array += num_focus_real_elements[i] * amount_grid * velocity_grid_num;
    }

    for(int i = 0;i<num_focus_velocity_elements.size();i++){

        std::int_fast32_t amount_grid = 1;

        for(int j = 1;j<(num_focus_velocity_elements.size()-i);j++){
            amount_grid *= velocity_each_grid_num[i+j];
        }
        num_psd_need_on_array += num_focus_velocity_elements[i] * amount_grid;
    }

    return num_psd_need_on_array;
    
}


}
}