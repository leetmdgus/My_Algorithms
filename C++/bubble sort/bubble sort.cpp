#include <iostream>
using namespace std;
#define ARRAY_SIZE 5

int main(void)
{
    int array[ARRAY_SIZE] = {22,37,15,19,12};
    for(int j = 0; j<ARRAY_SIZE;j++)
    {
        for(int i = 0; i<ARRAY_SIZE-j; i++)	// 큰 루프 돌 때마다, 가장 큰 숫자가 오른쪽에 가기때문에   
        {									// 마지막까지 볼 필요가 없다. 
            if(array[i]<=array[i+1])
                continue;
            else
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }

    for(int i = 0; i<ARRAY_SIZE; i++)
        cout<<array[i]<<" ";
    
    cout<<endl;
    cout<<array[5]<<endl;

}   

