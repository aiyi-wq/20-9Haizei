/*************************************************************************
	> File Name: 47_v2.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 24 Nov 2020 07:05:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, c[105], w[105], ans[10005];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= c[i]; j--) {
            ans[j] = max(ans[j], ans[j -c[i]]) + w[i];
        }
    }
    cout << ans[m] << endl;
}
