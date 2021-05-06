/*************************************************************************
	> File Name: topo.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 19 Nov 2020 06:16:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct edge {
    int e, next;
};

edge edg[10005];
int n, m, head[10005], int_degree[10005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edg[i].e = b;
        edg[i].next = head[a];
        head[a] = i;
        int_degree[b]++;
    }
    //queue<int> que;
    stack<int> sta;
    for (int i = 1; i <= n; ++i) {
        if (int_degree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        cout << t << "-";
        for (int i =head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            int_degree[e]--;
            if (int_degree[e] == 0) {
                sta.push(e);
            }
        }
    }
}
