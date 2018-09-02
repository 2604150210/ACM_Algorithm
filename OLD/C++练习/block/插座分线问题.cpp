
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

    int n,m;
    cin>>n>>m;
    vector<int>v;
    int x;
    for(int i=1;i<=m;i++){
        cin>>x;
        v.push_back(x);
    }
    if(n==0||n==1){
        cout<<0<<endl;
        return 0;
    }
    if(m==0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    int s=v[0],i;
    for(i=1;i<v.size();i++){
            //if(v[i]==0)break;
        if(s>=n)break;
        s+=v[i]-1;
    }
    if(i>=v.size()||s<n)
        cout<<"Impossible"<<endl;
    else
    cout<<i<<endl;
}



