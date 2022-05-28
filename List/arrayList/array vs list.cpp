#include <iostream>
using namespace std;

// 배열의 문제!
int main(void){
  int array[3] = {1,2,3};//가득참!
  int newArray[9] = {};//새로운 array생성!
  
  // time complexity 0(n)
  for(int i = 0; i<3; i++){
    newArray[i] = array[i];
  }
}



