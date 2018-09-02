#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int main(){
    int n,Q;
    cin>>n>>Q;
    vector<int>v;
    v.push_back(0);
    int r;
    for(int i=1;i<=n;i++){
        cin>>r;
        v.push_back(r);
    }
    int x,y;
    while(cin>>x){
        if(x==0)break;
        cin>>y;
        int s=1,max=1;
        for(int i=x+1;i<=y;i++){
            if(v[i-1]==v[i]){
                s++;
            }
            else
            {
                if(s>max){
                    max=s;
                }
                s=1;
            }
        }
        if(s>max)
            max=s;
        cout<<max<<endl;
    }
}
