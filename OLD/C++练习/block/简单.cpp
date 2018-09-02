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
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
            int r;
    cin>>r;
        vector<int>v;
        int x;
        for(int i=1;i<=10;i++){
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        cout<<r<<" "<<v[7]<<endl;
    }
    return 0;
}
