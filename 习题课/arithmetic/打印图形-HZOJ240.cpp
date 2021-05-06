/*************************************************************************
	> File Name: 打印图形-HZOJ.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 09 Mar 2021 04:27:55 PM CST
 ************************************************************************/

/****
 输入：输入共 n + 1行，前n行每行一个数，表示要输出的图形的大小
 最后一行输入-1代表程序结束。（1 <= n <= 7）
 输出：每输入一个数输出一组图形，并在图形的下一行输出一个 ——
 注意，图形后应补齐空格
 ****/



/********
 递归算法，图形————mmap, 数组
 单独一个函数处理递归，递归需要找出口（边界）
 先计算大小
 1.n = 2, 长为 3，宽为 3 ( 3^1 )
 2.n = 3, 长为 9, 宽为 9 ( 3^2 )
 3.n = 4, 长为 27, 宽为 27 ( 3^3 )
 ......
 n = k, 长为 3^(k - 1) = 729

 ex: n = 2的图形

 X X
  X
 X X

 ********/


#include<iostream>
using namespace std;
#define MAX 5000

char ans[MAX + 5][MAX + 5];
int num[10] = {0, 1}; //存边长

//递归函数
//x代表图形'X'开始位置的横坐标，y即为纵坐标，n代表图形的大小（num[n]表示边长）
//func(1, 1, 7) -> 分解为 n = 6的五个小分块的 ->
//func(1, 1, 6)->左上角
//func(x, y + num[n] / 3 * 2, 6)->右上角
//func(x + num[n] / 3 * 2, y , 6)->左下角
//func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, 6)->右下角
//func(x + num[n] / 3, y + num[n] / 3, 6) ->中间
//递归出口就是n == 1
void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
}

int main() {
    for (int i = 2; i <= 7; ++i) {
        num[i] = num[i - 1] * 3;
    }    
    func(1, 1, 7);
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        for (int i = 1; i <= num[n]; i++) {
            for (int j = 1; j <= num[n]; j++) {
                if (ans[i][j] == 'X') {
                    cout << 'X';
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
