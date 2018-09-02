#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
void replac(string & s,char ch,string s1)
{
    if(ch=='%')
    {

    }
    string::iterator it=s.begin();
    while(1)
    {
        it=find(it,s.end(),ch);
        if(it==s.end())
            break;
        it=s.erase(it);
        it=s.insert(it,s1[0]);
        it++;
        it=s.insert(it,s1[1]);
        it++;
        it=s.insert(it,s1[2]);
        //it++;
   }
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s=="#")
            break;

        replac(s,' ',"%20");
        replac(s,'!',"%21");
        replac(s,'$',"%24");
        replac(s,'%',"%25");
        replac(s,'(',"%28");
        replac(s,')',"%29");
        replac(s,'*',"%2a");
         cout<<s<<endl;
    }
return 0;
}


