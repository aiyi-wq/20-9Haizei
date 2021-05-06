/*************************************************************************
	> File Name: OJ-404-bfs.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Sep 2020 07:41:00 PM CST
 ************************************************************************/
//广搜
#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y;  
};

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];
int n, m, sx, sy, cnt;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            mmap[i][j] -= '0' - 1;
        }
    }
    cin >> sx >> sy;
    queue<node> que;
    que.push((node){sx, sy});
    cnt = 1;
    mmap[sx][sy]= -mmap[sx][sy];
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m || mmap[x][y] < 0 || mmap[x][y] == abs(mmap[temp.x][temp.y])) continue;
            cnt++;
            mmap[x][y] = -mmap[x][y];
            que.push((node){x, y});
        }
    }
    cout << cnt << endl;
    return 0;
}
