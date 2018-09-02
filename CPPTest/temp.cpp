#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10];
int ans;

int main()
{
    int n;
    int a[10];
    while(~scanf("%d",&n))
    {
        ans=0;
        memset(a,0,sizeof(a));
        for(int i = 0; i<n; i++)
        {
            int b;
            scanf("%d",&b);
            a[b]++;
        }
        int m41=min(a[4],a[1]);
        a[5]+=m41;
        a[4]-=m41,a[1]-=m41;
        if(a[4])a[5]+=a[4];
        int m32=min(a[3],a[2]);
        a[5]+=m32;
        a[3]-=m32;
        a[2]-=m32;
        if(a[3])
        {
            if(a[1]<=a[3]*2)
            {
                a[1]=0;
                a[5]+=a[3];
                a[3]-=a[1]/2;
            }
            else
            {
                a[1]-=2*a[3];
                a[5]+=a[3];
                a[3]-=a[1]/2;

            }
        }
        if(a[2]%2==0)
        {
            a[5]+=a[2]/2;
            a[1]-=a[2]/2;
            if(a[1]<0)a[1]=0;
        }
        else
        {
            a[5]+=a[2]/2;
            a[1]-=a[2]/2;
            a[1]-=3;
            a[5]++;
            if(a[1]<0)a[1]=0;

        }
        a[5]+=(a[1]+4)/5;
        printf("%d\n",a[5]);
    }
    return 0;
}
