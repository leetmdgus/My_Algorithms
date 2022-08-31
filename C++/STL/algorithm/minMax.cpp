// minMax. cpp

#include <algorithm>
#include <iostream>
int main(void)
{
	std::string first{ "first" };
	std::string second{ "second" };

	auto minInt = std::min({3,1,2011,2014,-5});	
	// std::min(1,2,3,4)에러 발생 -> (1,2,3,4) 이니셜라이저리스트 아님

	std::cout << "std::min(2011, 2014): " << std::min(2011, 2014) << std::endl;//2011
	std::cout << "std::min(first, second): " << std::min(first, second) << std::endl;//first
	std::cout << "std::min({3,1,2011,2014,-5}): " << std::min({ 3,1,2011,2014,-5 }) << std::endl;//-5
	std::cout << "std::min(-10,-5, [](int a, int b){return std::abs(a) < std::abs(b);}): " << std::min(-10, -5, [](int a, int b) {return std::abs(a) < std::abs(b); }) << std::endl;//
	// -5
	// lambda!

	std::cout << std::endl;

	std::cout << "std::max(2011, 2014): " << std::max(2011, 2014) << std::endl; // 2014
	std::cout << "std::max(first, second): " << std::max(first, second) << std::endl; // second
	std::cout << "std::max({3,1,2011,2014,-5}): " << std::max({ 3,1,2011,2014,-5 }) << std::endl;// 2014
	std::cout << "std::max(-10,-5, [](int a, int b){return std::abs(a) < std::abs(b);}): " << std::max(-10, -5, [](int a, int b) {return std::abs(a) < std::abs(b); }) << std::endl;
	// -5

	std::cout << std::endl;

	auto pairInt = std::minmax(2011, 2014);	
	auto pairStr = std::minmax(first, second);
	auto pairSeq = std::minmax({ 3,1,2011,2014,-5 });
	auto pairAbs = std::minmax({ -10, -5, 2011, 2014, 3 }, [](int a, int b) {return std::abs(a) < std::abs(b); });

	std::cout << "(pairInt.first, pairInt.second): (" << pairInt.first << ", " << pairInt.second << ")" << std::endl;// (2011,2014)
	std::cout << "(pairStr.first, pairStr.second): (" << pairStr.first << ", " << pairStr.second << ")" << std::endl;// (first, second)
	std::cout << "(pairSeq.first, pairSeq.second): (" << pairSeq.first << ", " << pairSeq.second << ")" << std::endl;// (-5, 2014)
	std::cout << "(pairAbs.first, pairAbs.second): (" << pairAbs.first << ", " << pairAbs.second << ")" << std::endl;

	return 0;

}