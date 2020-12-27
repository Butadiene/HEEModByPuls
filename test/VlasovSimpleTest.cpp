#include <iostream>
#include "../include/coordinate_spec.hpp"
//constexprとクラスを混ぜて次元解析モジュールを作ってみる
class Integer {
  int value_;
public:
  constexpr Integer(int value)
    : value_(value) {}

  constexpr int get() const
  { return value_; }
};

int main()
{
  constexpr Integer x = 3;
  static_assert(x.get() == 3, "x value must be 3");
}

/*
int main(){
    double a =coordinate_spec::kRealDimensionNum;

    std::cout << a*2. << std::endl;
}
*/