/*************************************************************************
	> File Name: template.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Wed 04 Nov 2020 08:47:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//函数模板 And there is another MODULE named 类函数模板
template <typename T>
void my_swap(T& first, T& second) {
    T temp;
    temp = first;
    first = second;
    second = temp;
}

int main() {
    int a = 10;
    int b = 100;
    cout << "a = " << a << " " << "b = " << b << endl;
    my_swap(a, b);
    cout << "a = " << a << " " << "b = " << b << endl;

    double c = 3.14;
    double d = 2.99;
    cout << "c = " << c << " " << "d = " << d << endl;
    my_swap(c, d);
    cout << "c = " << c << " " << "d = " << d << endl;
    return 0;
}
