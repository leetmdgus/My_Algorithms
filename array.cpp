#include <iostream>

using namespace std;

int main(void)
{
    int *ptr = new int[3]();    //힙 공간에 동적으로 int형 배열을 할당한다. 

    for(int i = 0; i<7; i++)
        ptr[i] = i; //ptr[0]~ptr[6]에 0부터 6까지 집어 넣는다.

    for(int i = 0; i <7; i++)
        cout<<ptr[i]<<" ";  //ptr[0]~ptr[6]를 출력한다.
    
    //결과: 0 1 2 3 4 5 6 
    cout<<endl;

    for(int i = 0; i <7; i++)
        cout<<&ptr[i]<<" ";   //ptr[0]~ptr[6]의 주솟값을 확인한다. 
    
    //결과: 0xfe19b0 0xfe19b4 0xfe19b8 0xfe19bc 0xfe19c0 0xfe19c4 0xfe19c8
    delete[] ptr;
    return 0;
}