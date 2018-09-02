const int MAXN = 10000;//求MAXN范围内的素数
vector<int>P;
bool isprime[MAXN];
void prime(){
    memset(isprime,true,sizeof(isprime));//初始化所有的数为素数
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i <= MAXN; i++){
        if(isprime[i]){
            P.push_back(i);
        }
        for(int j = 0; j < P.size() && P[j] * i <=MAXN; j++){
            isprime[P[j]*i] = 0;//筛掉小于等于i的素数和i的积构成的合数
        }
    }
}
