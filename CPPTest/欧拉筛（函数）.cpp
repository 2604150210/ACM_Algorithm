const int MAXN = 10000;//��MAXN��Χ�ڵ�����
vector<int>P;
bool isprime[MAXN];
void prime(){
    memset(isprime,true,sizeof(isprime));//��ʼ�����е���Ϊ����
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i <= MAXN; i++){
        if(isprime[i]){
            P.push_back(i);
        }
        for(int j = 0; j < P.size() && P[j] * i <=MAXN; j++){
            isprime[P[j]*i] = 0;//ɸ��С�ڵ���i��������i�Ļ����ɵĺ���
        }
    }
}
