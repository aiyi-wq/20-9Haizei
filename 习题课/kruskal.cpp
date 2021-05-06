/*************************************************************************
	> File Name: kruskal.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 12 Nov 2020 07:31:50 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 200000
#define MAX_N 5000

struct edge {
    int s, e, v;
};

bool cmp(const edge &a, const edge &b ) {
    return a.v < b.v;
}

edge edg[MAX + 5];
int n, m, ans, my_union[MAX_N + 5], already = 1;

//找根节点
int find_root(int x) {
    if (my_union[x] == x) {
        return x;
    }
    return my_union = find_root(my_union[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edg[i].s >> edg[i].e >> edg[i].v;
    }
    for (int i = 1; i <= n; ++i) {
        my_union[i] = i;
    }
    sort(edg, edg + m, cmp);
    for (int i = 0; i <= m; ++i) {
        int sr = find_root(edg[i].s), er = find_root(edg[i].e);
    }
}
