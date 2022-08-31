#include <iostream>
#include <set>

int main() {
    std::set<int> set1;
    set1.emplace(1);    //set은 데이터가 중복해서 들어가지 않음
    set1.emplace(1);
    set1.emplace(1);
    for(auto s: set1) std::cout << s << " ";
    std::cout << std::endl;
    // 결과 1
    set1.emplace(2);
    set1.emplace(3);
    for(auto s: set1) std::cout << s << " ";
    std::cout << std::endl;
    // 결과 1 2 3
    set1.erase(1);  //값 1 지움
    for(auto s: set1) std::cout << s << " ";
    std::cout << std::endl;
    // 결과 2 3
    std::cout << set1.size() <<std::endl;
    std::cout << set1.count(2) <<std::endl;

    return 0;
}