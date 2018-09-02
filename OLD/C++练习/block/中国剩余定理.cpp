//http://blog.sina.com.cn/s/blog_7d7f72bb0100spe6.html
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int a,b,c,d;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
            if(a==-1&&b==-1&&c==-1&&d==-1)break;
        printf("%d\n",(14421*b+1288*c+5544*a-d+21251)%21252+1);
    }
}

