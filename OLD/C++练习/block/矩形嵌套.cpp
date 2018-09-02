#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1010;
struct Node{
    int x,y;
    friend bool operator<(Node a,Node b){
        return a.x < b.x && a.y < b.y;
    }
};
bool com(Node a, Node b){
    if(a.x < b.x )return 1;
    else if(a.x == b.x && a.y < b.y)return 1;
    else return 0;
}
Node a[N];
int dp[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d%d",&a[i].x,&a[i].y);
            if(a[i].x > a[i].y)swap(a[i].x, a[i].y);
            dp[i] = 1;
        }
        sort(a,a+n,com);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(a[j] < a[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        sort(dp, dp + n);
        printf("%d\n",dp[n-1]);
    }
}
/*
矩形嵌套
时间限制：3000 ms  |           内存限制：65535 KB
难度：4
描述
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
输入
第一行是一个正正数N(0<N<10)，表示测试数据组数，
每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个数(n<=1000)
随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽
输出
每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行
样例输入
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
样例输出
5

*/
