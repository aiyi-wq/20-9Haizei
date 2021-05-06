/*************************************************************************
	> File Name: OJ-561.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 24 Nov 2020 08:43:12 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int n, m, mempty, mfull, c[505], w[505], ans[10005];
int main() {
    memset(ans, 0X3F, sizeof(ans));
    cin >> mempty >> mfull;
    m = mfull - mempty;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> c[i];
    }
    ans[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = c[i]; j <= m; ++j) {
            ans[j] = min(ans[j], ans[j - c[i]] + w[i]);
        }
    }
    if (ans[m] != 0x3F3F3F3F) {
        cout << "The minimum amount of money in the piggy-bank is " << ans[m] << ".\n";
    } else {
        cout << "This is impossible." << endl;
    }
    return 0;
}
