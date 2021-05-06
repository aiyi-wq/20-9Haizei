/*************************************************************************
	> File Name: stuct.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 May 2020 06:07:49 PM CST
 ************************************************************************/
#include<iostream>
#include<string.h>
#define max_n 100
using namespace std;

char *str[max_n + 5];
//char **str = (char **)malloc(sizeof(char *) * max_n);

bool cmp(const char *str1, const char *str2) {
    int t = strcmp(str1, str2);
    return t < 0;
}

int main() {
    for (int i = 0; i < 10; i++) {
        str[i] = (char *)malloc(sizeof(char) * 20);
    }
    for (int i = 0; i < 10; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
