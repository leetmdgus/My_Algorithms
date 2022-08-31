#include <iostream>
#include <set>

int main() {
    std::set<int> set1;
    set1.emplace(1);    //set�� �����Ͱ� �ߺ��ؼ� ���� ����
    set1.emplace(1);
    set1.emplace(1);
    for(auto s: set1) std::cout << s << " ";
    std::cout << std::endl;
    // ��� 1
    set1.emplace(2);
    set1.emplace(3);
    for(auto s: set1) std::cout << s << " ";
    std::cout << std::endl;
    // ��� 1 2 3
    set1.erase(1);  //�� 1 ����
    for(auto s: set1) std::cout << s << " ";
    std::cout << std::endl;
    // ��� 2 3
    std::cout << set1.size() <<std::endl;
    std::cout << set1.count(2) <<std::endl;

    return 0;
}