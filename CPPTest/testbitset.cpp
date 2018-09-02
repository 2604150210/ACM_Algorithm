#include<bits/stdc++.h>
using namespace std;
const int n=4;
vector<int> a(n);
bitset<n> v;

void dfs(int k)
{
    if(k==n)
    {
        copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!v.test(i))
        {
            v.set(i);
            a[k]=i;
            dfs(k+1);
            v.reset(i);
        }
    }

}


int main()
{
    bitset<32> b(-1);
    cout<<b<<endl;
    b.flip(31);
    cout<<b<<endl;
    dfs(0);
    return 0;
}
