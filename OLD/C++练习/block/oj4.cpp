#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdlib>
#include <map>
using namespace std;
bool low(string s1,string s2){
    queue<char>q1,q2;
    for(int i=0;i<s1.size();i++){
        q1.push(s1[i]);
    }for(int i=0;i<s2.size();i++){
        q2.push(s2[i]);
    }

    int sum1=0,sum2=0;
    while(q1.front()!='.'){
        sum1=sum1*10+q1.front()-'0';
        q1.pop();
    }
        while(q2.front()!='.'){
        sum2=sum2*10+q2.front()-'0';
        q2.pop();
    }
    if(sum1<sum2)return 1;
    if(sum1>sum2)return 0;
    q1.pop();
    q2.pop();
    sum1=0,sum2=0;
    while(q1.front()!='.'){
        sum1=sum1*10+q1.front()-'0';
        q1.pop();
    }
        while(q2.front()!='.'){
        sum2=sum2*10+q2.front()-'0';
        q2.pop();
    }
    if(sum1<sum2)return 1;
    if(sum1>sum2)return 0;
    q1.pop();
    q2.pop();

    sum1=0,sum2=0;
    while(!q1.empty()){
        sum1=sum1*10+q1.front()-'0';
        q1.pop();
    }
        while(!q2.empty()){
        sum2=sum2*10+q2.front()-'0';
        q2.pop();
    }
    if(sum1<sum2)return 1;
    if(sum1>sum2)return 0;
}
int main(){
    int n;
    cin>>n;
    map<string , string>m;
    string s1,s2;
    for(int i=1;i<=6;i++){
        cin>>s1>>s2;
        m[s1]=s2;
    }
    int t;
    cin>>t;
    string s3,s4;
    for(int i=1;i<=t;i++){
        cin>>s3>>s4;
        if(m[s3]!=s4){
            if(low(m[s3],s4)){
                cout<<s3<<" -1.-1.-1"<<endl;
            }
            else{
                cout<<s3<<" "<<m[s3]<<endl;;
            }
        }
    }

}

