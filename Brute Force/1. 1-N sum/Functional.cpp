// 필수 조건 n >= 1
// 결과: 1부터 n까지의 합을 반환한다.
int sum(int n) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += i;
    }
    return ret;
}
