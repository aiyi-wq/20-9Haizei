/*************************************************************************
	> File Name: 最大黑色区域.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Sep 2020 12:28:41 PM CST
 ************************************************************************/
//具体看Haizei-OJ536题目

#include<iostream>
using namespace std;

//方向数组
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];
int n, m, ans, temp;

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '1') {
            temp++;
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '1') {
                temp = 1;
                mmap[i][j] = 0;
                func(i, j);
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
