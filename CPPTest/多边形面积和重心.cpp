#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T,n;
    double s,tmp,x1,x2,y1,y2,tx,ty,Gx,Gy;
    cin>>T;
    while(T--){
        s = Gx = Gy = 0;
        cin>>n;
        if(n > 1){
            cin>>x1>>y1;
            tx = x1;
            ty = y1;
            n--;
            while(n--){
                cin>>x2>>y2;
                tmp = (x1*y2 - y1*x2)/2;
                Gx += tmp*(x1+x2)/3.0;
                Gy += tmp*(y1+y2)/3.0;
                s += tmp;
                x1 = x2;
                y1 = y2;
            }
                tmp = (x1*ty - y1*tx)/2;
                Gx += tmp*(x1+tx)/3.0;
                Gy += tmp*(y1+ty)/3.0;
                s += tmp;
        }
        if(fabs(s) < 10e-4){
            printf("0.000 0.000\n");
        }else{
            printf("%.3f %.3f\n", fabs(s),(Gx+Gy)/s);
        }
    }
}