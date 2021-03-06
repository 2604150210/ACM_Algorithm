// http://blog.163.com/lz_666888/blog/static/1147857262009914112922803/
// nyist.164
#include <cstdio>
#include <iostream>
using namespace std;
int a[101][110]={0};
int main(){
    int b[101];
    a[1][0]={1};//低坐标存放大数的地位
    int len = 1 ;
    b[1]=1;
    int t,r,j,temp;
    for(int i=2;i<=100;i++){
        t = i-1;
        for(int j=0;j<len;j++){//模拟乘法，从低位开始
            a[i][j] = a[i-1][j] * (4 * t + 2);
        }
        for(r = 0 ,j = 0;j<len;j++){
            temp = a[i][j] + r;
            a[i][j] = temp % 10;
             r = temp/10;
        }
        while(r){//进位处理
            a[i][len++]=r%10;
            r/=10;
        }

        for(j = len -1, r= 0;j>=0;j--){//模拟除法，从高位开始
            temp = r*10 +a[i][j];
            a[i][j] = temp /(t+2);
            r = temp % (t+2);
        }

        while(!a[i][len-1]){//高位零处理
            len--;
        }
        b[i] = len;//记录结果的长度
    }
    int n;
    while(cin>>n&&n!=-1){
        for(j = b[n] - 1 ; j>=0; j--){
            printf("%d",a[n][j]);
        }
        printf("\n");
    }
}
/*
Catalan数

　　中文:卡特兰数

　　原理：

　　令h(1)＝1,h(0)=1，catalan数满足递归式：

　　h(n)= h(1)*h(n-1) + h(2)*h(n-2) + ... + h(n-1)h(1) (其中n>=2)

　　另类递归式：

　　h(n)=((4*n-2)/(n+1))*h(n-1);

　　该递推关系的解为：

　　h(n+1)=C(2n,n)/(n+1) (n=1,2,3,...)

　　我并不关心其解是怎么求出来的，我只想知道怎么用catalan数分析问题。

　　我总结了一下，最典型的四类应用：（实质上却都一样，无非是递归等式的应用，就看你能不能分解问题写出递归式了）

　　1.括号化问题。

　　矩阵链乘： P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案？(h(n)种)

　　2.出栈次序问题。

　　一个栈(无穷大)的进栈序列为1,2,3,..n,有多少个不同的出栈序列?

　　类似：有2n个人排成一行进入剧场。入场费5元。其中只有n个人有一张5元钞票，另外n人只有10元钞票，剧院无其它钞票，问有多少中方法使得只要有10元的人买票，售票处就有5元的钞票找零？(将持5元者到达视作将5元入栈，持10元者到达视作使栈中某5元出栈)

　　3.将多边行划分为三角形问题。

　　将一个凸多边形区域分成三角形区域的方法数?

　　类似：一位大城市的律师在她住所以北n个街区和以东n个街区处工作。每天她走2n个街区去上班。如果她

　　从不穿越（但可以碰到）从家到办公室的对角线，那么有多少条可能的道路？

　　类似：在圆上选择2n个点,将这些点成对连接起来使得所得到的n条线段不相交的方法数?

　　4.给顶节点组成二叉树的问题。

　　给定N个节点，能构成多少种不同的二叉树？

　　（能构成h（N）个）

Catalan数的解法

Catalan数的组合公式为 Cn=C(2n,n) / (n+1);

此数的递归公式为 h(n ) = h(n-1)*(4*n-2) / (n+1)

*/
