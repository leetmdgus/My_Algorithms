#include <iostream>
#include <string>

using namespace std;
int length(int A); //배열 A의 사이즈를 구하는 함수

int main(void)
{
    int A[] = {5,2,4,6,1,3};    //index값은 0부터 시작한다. (A[0] = 5, A[1] = 2, A[2] = 3)
    int key, comp;
    
    int lengthA= sizeof(A)/sizeof(A[0]); //sizeof는 요소의 byte수를 리턴


    for(int index = 1; index <lengthA; index++){
        key = A[index]; //  A[index]값을 저장한다.

        comp = index-1; 
        if(index == 1){
            if(key < A[comp]){
                A[index] = A[comp];
                A[0] = key;
            }

        }else{
            while(comp >=0){
                if(key < A[comp]){           // A[comp] 가 key값보다 작다면
                    A[comp+1] = A[comp];      // 오른쪽으로 한칸 미는 작업이다. key값이 들어갈 자리를 확보하기 위해서이다.
                }else{
                    A[comp+1] = key;
                    break;       
                }if(comp == 0){ //A[comp]가 0. 즉, 모든 수가 key 값보다 크다면
                    A[0] = key; 
                    
                }
                
                comp--;
            }   
        }

        
    }
    
    for(int n = 0; n<lengthA; n++)
        cout<<A[n]<<" ";

    return 0;
}

