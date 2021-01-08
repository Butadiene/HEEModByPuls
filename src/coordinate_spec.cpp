#include <numeric>
#include <iostream>
#include "../include/coordinate_spec.hpp"
#include "../include/heembp_param.hpp"
namespace heemodbypuls{
namespace coordinate_spec{ 


CoordinateSpec::CoordinateSpec()
:real_each_grid_num_(heembp_param::kRealEachGridNum)
,velocity_each_grid_num_(heembp_param::kVelocityEachGridNum)
,field_dimension_each_num_(heembp_param::kFieldDimensionEachElemntsNum)
{
    real_dimension_num_ = real_each_grid_num_.size(),
    velocity_dimension_num_ = velocity_each_grid_num_.size(),

    real_grid_num_ = std::accumulate(
        real_each_grid_num_.begin(),real_each_grid_num_.end(),1,[](int acc, int i){return acc * i;}),

    velocity_grid_num_ = std::accumulate(
        velocity_each_grid_num_.begin(),velocity_each_grid_num_.end(),1,[](int acc, int i){return acc * i;}),

    total_grid_num_ = real_grid_num_ * velocity_grid_num_,

    field_all_dimension_num_ =  std::accumulate(field_dimension_each_num_.begin(),field_dimension_each_num_.end(),0),

    dimensional_integirity_check_ = true;

    std::vector<std::int_fast32_t> temp_real_grid_in_the_grid_num(real_dimension_num_); 

    std::vector<std::int_fast32_t> temp_total_real_grid_in_the_grid_num(real_dimension_num_);

    std::vector<std::int_fast32_t> temp_total_velocity_grid_in_the_grid_num(velocity_grid_num_); 

    for(int i = 0;i<real_dimension_num_;i++){
        std::int_fast32_t amount_grid = 1;
         for(int j = 1;j<(real_dimension_num_-i);j++){
            amount_grid *= real_each_grid_num_[i+j];
        }
        temp_real_grid_in_the_grid_num[i] = amount_grid;
        temp_total_real_grid_in_the_grid_num[i] = velocity_grid_num_ * amount_grid;
    }

    real_grid_in_the_grid_num_ = temp_real_grid_in_the_grid_num;

    total_real_grid_in_the_grid_num_ =  temp_total_real_grid_in_the_grid_num;

    
    for(int i = 0;i<velocity_dimension_num_;i++){
        std::int_fast32_t amount_grid = 1;
         for(int j = 1;j<(velocity_dimension_num_-i);j++){
            amount_grid *= velocity_each_grid_num_[i+j];
        }
         temp_total_velocity_grid_in_the_grid_num[i] = amount_grid;
    }

    total_velocity_grid_in_the_grid_num_ = temp_total_velocity_grid_in_the_grid_num;
   


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

    void CoordinateSpec::FieldDimensionIntegrityTest(std::int_fast32_t num_field_identify)const{
        
        if(dimensional_integirity_check_){
            if(!(num_field_identify<field_dimension_each_num_.size())){
                std::cout<<"HEEModByPuls's error::Trying to access an element for field outside the range"<<"\n";
                exit(1);
            }

        }
    }





}
}