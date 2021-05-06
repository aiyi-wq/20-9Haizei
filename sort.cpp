/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 May 2020 07:31:14 PM CST
 ************************************************************************/
#include<iostream>
#include <algorithm>
#define max_n 100
using namespace std;

int arr[max_n + 5] = {0};

int cmp(int a, int b) {
    return a > b;
} 

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n,cmp);
    for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
