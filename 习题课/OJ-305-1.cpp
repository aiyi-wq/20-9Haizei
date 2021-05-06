/*************************************************************************
	> File Name: OJ-305.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Sep 2020 06:47:53 PM CST
 ************************************************************************/
//bfs,第二种做法
#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, sx, sy, ans;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, -1, 1, 1, -1, -1, -1};
char mmap[105][105];

int main() {
    cin >> m >> n >> sy >> sx;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '.') {
            }
        }
    }
    queue<node> que;
    que.push((node){n - sx + 1, sy, 0});
    mmap[n - sx + 1][sy] = 'M';
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        ans = max(ans, temp.step);
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = 'M';
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
