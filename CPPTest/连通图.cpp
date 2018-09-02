/*
author : Ji Ailing
email:jal@webturing.com
language: C++
*/
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
struct node{
    int x,y;
};
int f[1002];

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
    int n,m;
    while(cin>>n>>m){
        if(n==0)break;
        for(int i = 1; i <= n; i++){
            f[i] = i;
        }
        vector<node>v;
        for(int i = 0; i < m; i++){
            node var;
            scanf("%d %d",&var.x,&var.y);
            v.push_back(var);
        }
        //cout<<"input over"<<endl;
        int t = 0;
        int flag = 0;
        for(int i = 0; i < v.size(); i ++){
            if(getf(v[i].x) != getf(v[i].y)){
                mergef(v[i].x,v[i].y);
                t++;
                if(t >= n-1){
                    //printf("%d ** %d\n",t,n-1);
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
