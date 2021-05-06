/*************************************************************************
	> File Name: P1625.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 17 Nov 2020 06:17:45 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct node {
    int now;
    double val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

int n, xy[5005][2], mark[5005];
double ans, dis[5005];

//最小生成树
double func(int a, int b) {
    double xx = xy[a][0] - xy[b][0] , yy = 
    return 
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> xy[i][0] >> xy[i][1];
        dis[i] = 99999999;
    }
    int already = 0;
    priority_queue<node> que;
    que.push((node){1, 0});
    dis[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.now] == 1) continue;
        mark[temp.now] = 1;
        ans += temp.val;
        already++;
        if (already == n) break;
        for (int i = 1; i <= n; ++i) {
            if (i == temp.now) continue;
            double t = func(i, temp.now);
            if (t < dis[i]) {
                t = dis[i];
                que.push((node){i, t});
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
