#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int>a;
    while(n--)
    {
        cin>>i;
        a.push_back(i);
    }
    sort(a.begin(),a.end());
    auto end_unique=unique(a.begin(),a.end());
    a.erase(end_unique,a.end());
    cout<<a.size()<<endl;
    auto it=a.begin();
    for(;it!=a.end()-1;it++)
        cout<<*it<<" ";
    cout<<*it<<endl;
    return 0;
}
