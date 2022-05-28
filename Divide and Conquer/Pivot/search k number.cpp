#include <iostream>

using namespace std;
int Pivot(int k, int* num, int index_first, int index_last);

int main(void)
{
    int k;
    cin>>k;//우리가 구하고자 하는 k번째 수

    int num[10] = {7, 2, 6, 3, 10, 5, 1, 8, 4, 9};

    int index_first = 0;
    int index_last  = 9;

    Pivot(k, num, index_first, index_last);

    return 0;
}

int Pivot(int k, int* num, int index_first, int index_last)
{
    int *upPointer, *downPointer;
    upPointer = &num[index_first];
    downPointer = &num[index_last];
    
    int middle_index = (index_first+index_last) / 2; 
    
    int pivot = num[middle_index];
    
    while(index_first<index_last)
    {
        if(num[index_first] < pivot)
        {
            index_first++;
        } 
        if(num[index_last] > pivot)
        {
            index_last--;
        } 
        
        int tmp = num[index_first];
        num[index_first] = num[index_last];
        num[index_last] = tmp;
    }

    if(num[k-1] == pivot)
    {
        cout<<"k = "<<pivot<<endl;
        return 0;
    }
    else if(num[k-1] < pivot)
    {
        index_first = 0;
        index_last = k-1;
    }
    else if(num[k-1] > pivot)
    {
        index_first = k-1;
        index_last = 9;
    }
    Pivot(k, num, index_first, index_last);

}