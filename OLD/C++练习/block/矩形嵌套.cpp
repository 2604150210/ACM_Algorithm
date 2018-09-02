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
����Ƕ��
ʱ�����ƣ�3000 ms  |           �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ���ھ���Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ������磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С����������ѡ�������ܶ�ľ����ų�һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ�
����
��һ����һ��������N(0<N<10)����ʾ��������������
ÿ��������ݵĵ�һ����һ��������n����ʾ������������к��о��εĸ���(n<=1000)
����n�У�ÿ����������a,b(0<a,b<100)����ʾ���εĳ��Ϳ�
���
ÿ��������ݶ����һ��������ʾ�����������ľ�����Ŀ��ÿ�����ռһ��
��������
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
�������
5

*/
