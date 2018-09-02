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

