/*************************************************************************
	> File Name: stl_sta_que_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Aug 2020 04:30:36 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;


struct node {
    int x, y;
};

int main() {
    queue<node> que;
    node a;
    a.x = 1;
    a.t = 2;
    que.push(a);
    cout << que.front().x << endl;
    cout << que.front().y << endl;
    node t = que.front();
    cout << t.x << " " << t.y << endl;
    que.push((node){3, 4});
    /*
    stack<int> sta;//生成一个 int 型的栈
    sta.push(7);//插入一个7
    for (int i = 1; i < 5; i++) {
        sta.push(i);
    }
    cout << sta.size() << endl;
    cout << sta.top() << endl;//弹出栈顶元素
    sta.pop();
    //que.empty()的返回值是1,代表栈是空的
    while (que.empty() == 0) {
        cout << sta.top() << endl;
        sta.pop();
    }
    */
    queue<int> que;
    que.push(7);
    for (int i = 1; i < 5; i++) {
        que.push(i);
    }
    cout << que.size() << endl;
    cout << que.front() << endl;
    que.pop();
    while (!que.front()) {
        cout << que.front()<< endl;
        que.pop();
    }
    return 0;
}
