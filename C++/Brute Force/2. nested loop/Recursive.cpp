#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int> &picked);
// 0부터 차례대로 번호 매겨진 n개의 원소 중 네 개를 고르는 모든 경우를 출력하는 코드
// n == 7이라면, (0.1.2.3, (0,1,2,4), (0,1,2,5), ..., (3,4,5,6)의 모든 경우 출력

// n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
void pick(int n, vector<int>& picked, int toPick) {
    if(toPick == 0) {
        printPicked(picked);
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next = smallest; next<n; ++next) {
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
}

void printPicked(vector<int> &picked) {
    for(vector<int>::iterator iter = picked.begin(); iter != picked.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> a;
    int n = 6;
    int toPick = 3;
    pick(n, a, toPick);


	return 0;
}