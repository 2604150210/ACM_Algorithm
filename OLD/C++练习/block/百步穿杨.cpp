#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>m;
        pair<int,int>p;
        for(int i=0;i<n;i++)
        {
            cin>>p.first>>p.second;
            m.insert(p);
        }
        for(auto x:m)
        {
            for(int i=1;i<=x.second;i++)
            {
                cout<<">+";
                for(int j=1;j<=x.first-2;j++)
                {
                    cout<<"-";
                }
                cout<<"+>"<<endl;
            }
            cout<<endl;
        }

    }
return 0;
}
