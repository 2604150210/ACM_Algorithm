#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{

    int n;
    while(cin>>n&&n!=0)
    {
        vector<string>s;
        int a[n];
        string ss;
        int i(1);
        while(i<=n&&cin>>ss)
        {
            s.push_back(ss);
            i++;
        }
        //cout<<endl;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(s[j]==s[i])
                    a[i]++;
            }
        }
        int max=a[0];
        int t;
        for(int i=0;i<n;i++)
        {
            if(max<a[i])
                {
                    max=a[i];
                    t=i;
                }
        }
        cout<<s[t]<<endl;
    }
    return 0;
}
