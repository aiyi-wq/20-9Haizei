/*************************************************************************
	> File Name: Bellman-Ford-queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Oct 2020 06:54:15 PM CST
 ************************************************************************/

// 用队列优化Bellman-Ford 算法，只遍历与当前数连接的点

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct edge {
    int e, dist, next;
};

edge edg[500005];
int n, m, s, ans[10005], mark[10005], head[10005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].e = b;
        edg[i].dist = c;
        edg[i].next = head[a];
        head[a] = i;
    }
    queue<int> que;
    que.push(s);
    ans[s] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, d = edg[i].dist;
            if (ans[e] > ans[temp] + d) {
                ans[e] = ans[temp] + d;
                if (mark[e] == 0) {
                    que.push(e);
                    mark[e] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3F3F3F3F) cout << ans[i];
        else cout << 0x7FFFFFFF;
    }
    cout << endl;
    return 0;
}
