/*************************************************************************
	> File Name: 迷宫.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Oct 2020 07:58:16 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

//队列存储的是自定义类型的坐标
typedef struct node {
    int x, y;
};

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
char mmap[3005][3005];
int n, m , k, temp, ans[3005][3005];
queue<node> que;

void func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
        if (ans[xx][yy] == 0 && mmap[xx][yy] != mmap[x][y]) {
            ans[xx][yy] = 1;
            temp++;
            que.push((node){xx, yy});
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >>(&mmap[i][1]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (ans[i][j] == 0) {
                temp = 1;
                que.push((node){i, j});
                ans[i][j] = 1;
                //dfs
                func(i, j);
                while (!que.empty()) {
                    node t = que.front();
                    que.pop();
                    ans[t.x][t.y] = temp;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        cout << ans[t1][t2] << endl;
    }
    return 0;
}
