#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int cmp(pair<char,int> a, pair<char,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return   a.second > b.second;
}
int main(){
    string str;
    while(cin>>str){
        vector<pair<char,int> >v;
        for(char  i = 'a'; i <= 'z'; i++){
            v.push_back({i,0});
        }
        for(int i = 0; i < str.size(); i++){
            if(str[i] >='A' && str[i] <= 'Z'){
                str[i] += 32;
            }
            v[str[i] - 'a'].second++;
        }
        //reverse(v.begin(),v.end());
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == 0)break;
            cout<<v[i].first;
        }
        cout<<endl;
    }
}
