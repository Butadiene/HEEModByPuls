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

class CoordinateSpec{
    // テストコードで書く、格子設定クラスの試作　
    //今回のシミュレーション用を愚直に書くが、将来的には格子設定クラスのInterfaceを用意したい
    std::int_fast8_t realDimensionNum;
    std::int_fast8_t velocityDimensionNum;

};

int main()
{
  const int c = 3;
  constexpr Integer x = c;
  static_assert(x.get() == 3, "x value must be 3");
}

/*
int main(){
    double a =coordinate_spec::kRealDimensionNum;

    std::cout << a*2. << std::endl;
}
*/