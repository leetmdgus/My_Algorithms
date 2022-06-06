#include <tuple>
#include <iostream>

int main() {
  std::cout << std::boolalpha <<std::endl;

  // 튜플 두 개를 생성한다. 
  std::tuple<std::string, int, float> tup1("first", 3, 4.17f);
  auto tup2 = std::make_tuple("second", 4, 1.1);

  // 값을 읽는다. 
  std::cout << "tup1: " << std::get<0>(tup1) << ", " << std::get<1>(tup1) << ", " << std::get<2>(tup1) << std::endl;
  std::cout << "tup2: " << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " << std::get<2>(tup2) << std::endl;

  //두 튜플을 비교한다. 
  std::cout << "tup1 < tup2: " << (tup1 < tup2) << std::endl;
  std::cout<<std::endl;

  //튜플 값을 수정한다. 
  std::get<0>(tup2) = "Second";

  // 값을 읽는다. 
  std::cout << "tup1: " << std::get<0>(tup1) << ", " << std::get<1>(tup1) << ", " << std::get<2>(tup1) << std::endl;
  std::cout << "tup2: " << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " << std::get<2>(tup2) << std::endl;

  //두 튜플을 비교한다. 
  std::cout << "tup1 < tup2: " << (tup1 < tup2) << std::endl;
  std::cout<<std::endl;
  
  auto pair = std::make_pair(1, true);
  std::tuple<int, bool> tup = pair;

  return 0;
}