#include <functional>
#include <iostream>

double divMe(double a, double b) {
  return double(a/b);
}
int main(void) {
  // 함수 오브젝트 직접 호출하기
  std::cout << "1/2.0 = " << std::bind(divMe, 1, 2.0)() << std::endl;

  // 두 인수에 대한 자리 표시자
  std::function<double(double, double)> myDivGindPlaceholder = std::bind(divMe, std::placeholders::_1, std::placeholders::_2);
  std::cout << "1/2.0 = " << std::bind(myDivGindPlaceholder, 1, 2.0)() << std::endl;

  // 두 인수에 대한 자리 표시자, 인수 맞바꾸기
  std::function<double(double, double)> myDivGindPlaceholderSwap = std::bind(divMe, std::placeholders::_2, std::placeholders::_1);
  std::cout << "1/2.0 = " << std::bind(myDivGindPlaceholderSwap, 2.0, 1)() << std::endl;
  
  // 첫 번째 인수에 대한 자리 표시자. 
  std::function<double(double)> myDivBind1St = std::bind(divMe, std::placeholders::_1, 2.0);
  std::cout << "1/2.0 = " << myDivBind1St(1) << std::endl;

  // 두 번째 인수에 대한 
  std::function<double(double)> myDivBind2Nd = std::bind(divMe, 1.0, std::placeholders::_1);
  std::cout << "1/2.0 = " << myDivBind2Nd(2.0) << std::endl;

  return 0;
}