#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
#define eps 1e-8
#define PI 3.1415926535898
#define MAX 1000
struct node
{
    double x,y;
    node() {}
    node(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    node operator +(const node &b)const
    {
        return node(x+b.x,y+b.y);
    }
    node operator -(const node &b)const
    {
        return node(x-b.x,y-b.y);
    }
    double operator *(const node &b)const
    {
        return x*b.x+y*b.y;
    }
    double operator ^(const node &b)const
    {
        return x*b.y-y*b.x;
    }
};
double dis(node a,node b)
{
    return sqrt((a-b)*(a-b));
}
int sgn(double a)
{
    if(abs(a)<eps)return 0;
    if(a<0)return -1;
    return 1;
}
node node_set[MAX];
int ans[MAX],top;
bool cmp(node p1,node p2)
{
    double tmp=(p1-node_set[0])^(p2-node_set[0]);
    if(sgn(tmp)>0) return true;
    else if(sgn(tmp)==0&&dis(node_set[0],p1)<dis(node_set[0],p2)) return true;
    else return false;
}
void init(int n)
{
    int k;
    node p0;
    cin>>node_set[0].x>>node_set[0].y;
    p0.x=node_set[0].x;
    p0.y=node_set[0].y;
    k=0;
    for(int i=1; i<n; i++)
    {
        cin>>node_set[i].x>>node_set[i].y;
        if((p0.y>node_set[i].y)||((p0.y==node_set[i].y)&&(p0.x>node_set[i].x)))
        {
            p0.x=node_set[i].x;
            p0.y=node_set[i].y;
            k=i;
        }
    }
    node_set[k]=node_set[0];
    node_set[0]=p0;
    sort(node_set+1,node_set+n,cmp);
}
void graham(int n)
{
    if(n==1)
    {
        top=0;
        ans[0]=0;
    }
    if(n==2)
    {
        top=1;
        ans[0]=0;
        ans[1]=1;
    }
    if(n>2)
    {
        ans[0]=0;
        ans[1]=1;
        top=1;
        for(int i=2; i<n; i++)
        {
            while(top>0&&((node_set[ans[top]]-node_set[ans[top-1]])^(node_set[i]-node_set[ans[top-1]]))<=0) top--;
            top++;
            ans[top]=i;
        }
    }
}