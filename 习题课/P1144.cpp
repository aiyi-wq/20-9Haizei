/*************************************************************************
	> File Name: P1144.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Oct 2020 08:20:01 PM CST
 ************************************************************************/

//Dijkstra算法，需要一个cnt[]来存储方案的个数
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct node {
    int now, dist;
    bool operator< (const node &b) const {
        return this->dist > b.dist;
    }
};

struct edge {
    int e, next;
};

int n, m, ans[1000005], head[1000005], cnt[1000005] = {0};
edge edg[4000005];
int mcnt = 0;

void add(int x, int y) {
    edg[mcnt].e = y;
    edg[mcnt].next = head[x];
    head[x] = mcnt;
    mcnt++;
}

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >>n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    ans[1] = 0;
    cnt[1] = 1;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dist > ans[temp.now]) {
            continue;
        }
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            if (ans[e] > ans[temp.now] + 1) {
                ans[e] = ans[temp.now] + 1;
                cnt[e] = cnt[temp.now];
                que.push((node){e, ans[e]});
            } else if (ans[e] == ans[temp.now] + 1) {
                cnt[e] += cnt[temp.now];
                cnt[e] %= 100003;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << endl;
    }
    return 0;
}
