/*************************************************************************
	> File Name: ez_dfs.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2020 08:39:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

char mmap[2005][2005];
int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};
int n, m, sx, sy, ex, ey;

int func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == 'g') {
            return 1;
        }
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '#';
            int t = func(xx, yy);
            if (t == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                sx = i;
                sy =j;
            }
            if (mmap[i][j] == 'g') {
                ex = i; 
                ey =j;
            }
        }
    }
    int t = func(sx, sy);
    if (t == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
