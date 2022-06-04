// pair.cpp
#include <utility>
#include <iostream>

int main() {
  std::pair<const char*, double> charDoub("string", 3.14);
  std::pair<const char*, double> charDoub2 = std::make_pair("string", 3.14);
  auto charDoub3 = std::make_pair("string", 3.14);

  std::cout << "charDoub: (" << charDoub.first << ", " << charDoub.second << ")" << std::endl;
  charDoub.first = "String";
  std::get<1>(charDoub) = 4.14;
  std::cout << "charDoub: (" << charDoub.first << ", " << charDoub.second << ")" << std::endl;

  std::swap(charDoub, charDoub2);
  std::cout << "charDoub: (" << charDoub.first << ", " << charDoub.second << ")" << std::endl;


}
