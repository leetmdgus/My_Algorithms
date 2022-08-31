#include <iostream>
using namespace std;

// 0부터 차례대로 번호 매겨진 n개의 원소 중 네 개를 고르는 모든 경우를 출력하는 코드
// n == 7이라면, (0.1.2.3, (0,1,2,4), (0,1,2,5), ..., (3,4,5,6)의 모든 경우 출력

int main(void)
{
    int n = 7;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; l++) {
                    cout << i << " " << j << " " << k << " " << l << endl;
                }
            }
        }
    }
    return 0;
}