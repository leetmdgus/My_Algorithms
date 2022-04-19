#include <iostream>
using namespace std;
#define ARRAY_SIZE 5

int main(void)
{
    int array[ARRAY_SIZE] = {22,37,15,19,12};
    for(int j = 0; j<ARRAY_SIZE;j++)
    {
        for(int i = 0; i<ARRAY_SIZE-j; i++)
        {
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
}