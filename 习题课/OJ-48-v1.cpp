/*************************************************************************
	> File Name: OJ-48-v1.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 24 Nov 2020 07:24:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int n, m, c[105], w[105], ans[105][10005];

int main() {
    cin >> n >> m ;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j >= c[i]) {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - c[i]] + w[i]);
            } else {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    cout << ans[n][m] << endl;
    return 0;
}
