#include <functional>
#include <iostream>

using namespace std::placeholders;

double divMe(double a, double b) {
  return double(a/b);
}

int main() {
  //함수 오브젝트 직접 호출하기.
  std::cout << "1/2.0= " << std::bind(divMe, 1, 2.0)() << std::endl;
  
  // 두 인수에 대한 자리 표시자
  std::function<double(double, double)> myDivBindPlaceholder = std::bind(divMe, _1, _2);
  std::cout << "1/2.0= " << myDivBindPlaceholder(1,2.0) << std::endl;
  
  // 두 인수에 대한 자리 표시자, 인수 맞바꾸기
  std::function<double(double, double)> myDivBindPlaceholderSwap = std::bind(divMe, _2, _1);
  std::cout << "1/2.0= " << myDivBindPlaceholderSwap(2.0,1) << std::endl;

  // 첫 번째 인수에 대한 자리 표시자.
  std::function<double(double)> myDivBind1St = std::bind(divMe, _1, 2.0);
  std::cout << "1/2.0= " << myDivBind1St(1) << std::endl;

  // 두 번째 인수에 대한 자리 표시자.
  std::function<double(double)> myDivBind2Nd = std::bind(divMe, 1, _1);
  std::cout << "1/2.0= " << myDivBind2Nd(2.0) << std::endl;

}