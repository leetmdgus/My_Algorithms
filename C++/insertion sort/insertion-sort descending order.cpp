#include <iostream>

using namespace std;
int length(int A); //�迭 A�� ����� ���ϴ� �Լ�

int main(void)
{
    int A[] = {7,219,22,30722,82};    //index���� 0���� �����Ѵ�. (A[0] = 5, A[1] = 2, A[2] = 3)
    int key, comp;
    
    int lengthA= sizeof(A)/sizeof(A[0]); //sizeof�� ����� byte���� ����


    for(int index = 1; index <lengthA; index++){
        key = A[index]; //  A[index]���� �����Ѵ�.

        comp = index-1; 
        if(index == 1){
            if(key > A[comp]){
                A[index] = A[comp];
                A[0] = key;
            }

        }else{
            while(comp >=0){
                if(key > A[comp]){           // A[comp] �� key������ �۴ٸ�
                    A[comp+1] = A[comp];      // ���������� ��ĭ �̴� �۾��̴�. key���� �� �ڸ��� Ȯ���ϱ� ���ؼ��̴�.
                }else{
                    A[comp+1] = key;
                    break;       
                }if(comp == 0){ //A[comp]�� 0. ��, ��� ���� key ������ ũ�ٸ�
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

