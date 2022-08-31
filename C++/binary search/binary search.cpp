#include <iostream>
using namespace std;
#define ARRAY_SIZE 10

int main(void)
{
    int array[ARRAY_SIZE] = {1,3,5,9,13,15,16,18,62,79};

    int searchValue = 3;

    int firstIndex = 0;
    int lastIndex = ARRAY_SIZE-1;
    int middleIndex = (firstIndex+lastIndex)/2;
    
    bool IsSearch = false;
    
    while(!IsSearch)
    {
        if(firstIndex > middleIndex || middleIndex > lastIndex)
        {
            cout<<"찾고자 하는 원소가 배열 안에 없습니다. "<<endl;
            break;//탐색 실패
        }
        if(searchValue < array[middleIndex])
        {
            lastIndex = middleIndex-1;
            middleIndex = (firstIndex + lastIndex)/2;
        
        }
        else if(searchValue > array[middleIndex])
        {   
            firstIndex = middleIndex+1;
            middleIndex = (firstIndex + lastIndex)/2;
        }
        else    //searchValue == arry[middleIndex]
        {
            cout<<"인덱스 "<<middleIndex<<"번에 있습니다."<<endl;
            IsSearch = true; //탐색 성공
        }
        
    }
    return 0;
}