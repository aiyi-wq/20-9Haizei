/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 May 2020 02:07:23 PM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
//111111110000000:找最后一个1

int binary_search(int *arr, int n) {
    int head = -1, tail = n - 1, mid;//head 为虚拟头指针
    while (head < tail) {
        cout << "head : " << head << ", tail : " << tail << endl; 
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == 0) tail = mid - 1;
        else head = mid;
    }
    return head;
}
// 0000000000111111111 找最后一个1

int binary_search2(int *arr, int n) {
    int head = 0, tail = n, mid;// tail 为虚拟尾指针
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == 0) head = mid + 1;
        else tail = mid;
    }
    return head == n ? -1 : head;
}

int main() {
    int num[10] = {1, 1, 1 ,1 ,1, 0, 0, 0, 0, 0};
    int num2[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int a[10] = {1, 1, 1 ,1 ,1, 1, 1, 1, 1, 1};
    int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << binary_search(a, 10) << endl;
    cout << binary_search2(b, 10) << endl;
    return 0;
}
