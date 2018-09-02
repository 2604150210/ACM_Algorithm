#include <iostream>
#include <Sales_data.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
inline void output_words(vector<string>&words)
{
    for(auto m:words)
        cout<<m<<" ";
    cout<<endl;
}
bool compareIsbn(const Sales_item &lst,const Sales_item &rhs)
{
    return (lhs.isbn()<rhs.isbn());
}
/*void elimDups(vector<string>&sv)
{
     output_words(sv);
     sort(sv.begin(),sv.end());
     output_words(sv);
     auto end_unique=unique(sv.begin(),sv.end());
     output_words(sv);
     sv.erase(end_unique,sv.end());
     output_words(sv);
     stable_sort(sv.begin(),sv.end(),compareIsbn);
     output_words(sv);
}*/

int main(int argc,char * argv[])
{
    vector <Sales_item> sds;
    Sales_item sd;
    while(read(in,sd))
        sds.push_back(sd);
    sort(sds.begin(),sds.end(),compareIsbn);
    return 0;

}


