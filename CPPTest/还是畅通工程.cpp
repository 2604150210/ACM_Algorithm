#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
    int x,y,z;
};
node a[5000];
int f[100+1];
int cmp(node a,node b){
    return a.z < b.z;
}
int getf(int x){
    if(f[x] != x){
        f[x] = getf(f[x]);
    }
    return f[x];
}
void mergef(int x,int y){
    int rootx = getf(x);
    int rooty = getf(y);
    if(rootx != rooty){
        f[rootx] = rooty;
    }
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        int m = n*(n-1)/2;
        for(int i = 0; i < m; i++){
           // cin>>a[i].x >> a[i].y >> a[i].z;
            scanf("%d %d %d",&a[i].x, &a[i].y,&a[i].z);
        }
        sort(a,a+m,cmp);

        for(int i = 1; i <=n; i++){
            f[i] = i;
        }
        int sum=0,t=0;
        for(int i = 0; i < m; i++){
            if(getf(a[i].x) != getf(a[i].y)){
                mergef(a[i].x ,a[i].y);
                sum+=a[i].z;
                t++;
                if(t > n-1)break;
            }
        }
        cout<<sum<<endl;
    }
}

/*
3
1 2 2
1 3 3
2 3 4
*/
