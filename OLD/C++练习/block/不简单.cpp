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
    string q1="Is this NEUQ£¿",q2="I have some question!",s1;

    getline(cin,s1);
    if(s1==q1){
        printf("Yes, welcome to NEUQ.\n");
    }
    if(s1==q2){
        printf("What can I do for you?\n");
    }
    return 0;


}
