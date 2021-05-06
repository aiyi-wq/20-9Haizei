/*************************************************************************
	> File Name: 401-象棋游戏升级版.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Sep 2020 07:21:18 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y, step;
};

int ans[505][505], n;
int dir[12][2] = {
    1, 2, -1, 2, 1, -2, -1, -2,
    2, 1, 2, -1, -2, 1, -2, -1,
    2, 2, 2, -2, -2, 2, -2, -2
};

int main() {
    queue<node> que;
    que.push((node){3, 3, 0});
    ans[3][3] = -1;//起点从-1开始
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 3 || y < 3 || x > 502 || y > 502 || ans[x][y]) continue;
            ans[x][y] = temp.step + 1;
            que.push((node){x, y, ans[x][y]});
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1 && y == 1) 
            cout << 0 << endl;
        else 
            cout << ans[x + 2][y + 2] << endl;
    }
    return 0;
}
