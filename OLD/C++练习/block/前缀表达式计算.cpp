#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn = 5000;

struct Node {
    double dig;
    char sym;
}sta[maxn];
char buf[maxn];

double cal(double a, double b, char c){
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
    return a / b;
}

int main(){
    double val;
    int wid;
    while(gets(buf)){
        for(int i = 0, id = 0; buf[i] != '\0'; ++i){
            if(buf[i] ==' ')continue;
            if(isdigit(buf[i]) || buf[i] == '.'){
                sscanf(buf + i, "%lf%n", &val, &wid);
                while(id && !sta[id - 1].sym) {
                    val = cal(sta[id - 1].dig, val, sta[id-2].sym);
                    id -= 2;
                }
                sta[id].dig = val;sta[id++].sym = 0;
                i = i + wid - 1;
            }
            else sta[id++].sym = buf[i];
        }
        printf("%.2f\n",sta[0].dig);
    }
}
