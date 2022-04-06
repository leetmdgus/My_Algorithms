#include <iostream>
#include <string>

using namespace std;
int length(int A); //배열 A의 사이즈를 구하는 함수

int main(void)
{
    int A[] = {5,2,4,6,1,3};    //index값은 0부터 시작한다. (A[0] = 5, A[1] = 2, A[2] = 3)
    int key;

    int lengthA= sizeof(A)/sizeof(A[0]); //sizeof는 요소의 byte수를 리턴

    for(int index = 1; index <lengthA; index++){
        key = A[index]; //  A[index]값을 저장한다.
        cout<<"key: "<<key<<endl;
        int comp = index-1; 
        while(A[index] < A[comp] && comp >=0){      // A[index] 가 A[index-1]보다 작고, index가 0보다 크다면
            if(index == 1){
                cout<<"A[comp]: "<<A[comp]<<endl;
                A[index] = A[comp];
                A[comp] = key;
                break;
            } else if(comp == 0){ //A[comp]가 0. 즉, 모든 수가 key 값보다 크다면
                A[0] = key;
            }
            else{
                A[comp] = A[comp-1];
                if(A[comp-1] < key){           // A[comp-1] 가 key값보다 작다면
                    A[comp] = key;      // 오른쪽으로 한칸 미는 작업이다. key값이 들어갈 자리를 확보하기 위해서이다.
                
                }
                else{
                    break;
                }
            }
            comp--;
        }
        
        cout<<lengthA<<endl;
        cout<<"A[0]: "<<A[0]<<endl;
        cout<<"A[1]: "<<A[1]<<endl;
        cout<<"A[2]: "<<A[2]<<endl;
        cout<<"A[3]: "<<A[3]<<endl;
        cout<<"A[4]: "<<A[4]<<endl;
        cout<<"A[5]: "<<A[5]<<endl;
        // for(int i = 0; i<lengthA; i++)
        //     cout<<A[i]<<endl;
    }
    
}

