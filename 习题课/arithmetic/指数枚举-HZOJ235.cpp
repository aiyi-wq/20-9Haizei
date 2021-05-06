/*************************************************************************
	> File Name: 指数枚举-HZOJ.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 11 Mar 2021 08:29:05 PM CST
 ************
 ************************************************************/

/*********
 题目要求：从1到n这n个整数中随机选取任意多个，每种方案的数从小到大排列，按字典序输出所有可能的选择方案

 指数型枚举（递归算法）

 输入：一个整数n（1 <= n <= 10）
 输出：每行一组方案，每组方案中两个数之间用空格分隔
 注意每行最后一个数没有空格
 
 ******/

/*****
 n = 3
 output:
 1
 1 2
 1 2 3
 1 3
 2
 2 3
 3
 analyse: 每层后一个数要比前面的大 num[i] + 1 ~ n
    第一层是 1 ~ 3
    第二层是 2 ~ 3
    第三层是 3
    把选过的数存在一个数组里，再引入一个计数器
    num[1] = 1;
    cnt ++;
    func(...);
    cnt--;
 递归函数：func(int start) 
 *****/

#include<iostream>
using namespace std;
#define MAX 10

int n, num[MAX + 5], cnt = 1;

void p() {
    for (int i = 1; i < cnt; ++i) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int start) {
    for (int i = start; i <= n; ++i) {
        num[cnt] = i;
        cnt++;
        p();
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
