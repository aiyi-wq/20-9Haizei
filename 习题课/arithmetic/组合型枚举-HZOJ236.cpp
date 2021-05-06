/*************************************************************************
	> File Name: 组合型枚举-HZOJ236.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 16 Mar 2021 08:53:28 PM CST
 ************************************************************************/

/****
 在 HZOJ235的基础上，取数的范围由输入具体决定
 ***/

#include<iostream>
using namespace std;
#define MAX 10

int n, m, num[MAX + 5], cnt = 1;

void p() {
    for (int i = 1; i < cnt; ++i) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

int func(int start) {
    num;
    cnt++;
    p();
    cnt--;
}

int main() {
    cin >> n >> m;
    func(1);
    return 0;
}
