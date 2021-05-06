/*************************************************************************
	> File Name: OJ-48-v2.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 24 Nov 2020 07:38:20 PM CST
 ************************************************************************/

//完全背包空间优化

#include<iostream>
using namespace std;

int n, m, c[10005], w[10005], ans[10005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> w[i];
    }
    //数组压缩
    for (int i = 1; i <= n; ++i) {
        for (int j = c[i]; j <= m; ++j) {
            ans[j] = max(ans[j], ans[j - c[i]] + w[i]);
        }
    }

    cout << ans[m] << endl;
    return 0;
}
