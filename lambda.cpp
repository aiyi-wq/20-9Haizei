/*************************************************************************
	> File Name: lambda.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Wed 04 Nov 2020 08:58:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    
    int i = 10;
    cout << i << endl;
    //[]:需要捕获的局部变量，():函数的参数，{}:函数体
    auto func_ptr = [&i]()mutable{i = 666;};
    func_ptr();
    cout << i << endl;
    return 0;
}
