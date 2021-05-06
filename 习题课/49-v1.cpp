/*************************************************************************
	> File Name: 49-v1.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 24 Nov 2020 07:51:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, ind, c[1005], w[1005], ans[10005];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        for (int j = 0; j < d; ++j) {
            ind++;
            c[ind] = a;
            w[ind] = b;
        }
    }
    for (int i = 1; i <= ind; ++i) {
        for (int j = m; j >= c[i]; --j) {
            ans[j] = max(ans[j], ans[j - c[i]] + w[i]);
        }
    }
    cout << ans[m] << endl;
    return 0;
}
