#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <vector>
using namespace std;

int awal, akhir, len;

bitset<100200> bs;
vector<int> p;
char s[30];

bool cek(long long num) {
    int ctr=0;
    long long x = num;
    while(ctr<len) {
        while(x%p[ctr]==0 and p[ctr]!=num) {
            x/=p[ctr];
        }
        ctr++;
    }
    if(x==num) return 1;
    return 0;
}

int main() {
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2; i*i<=100000; i++)
        for(int j=i*i; j<=100000; j+=i) bs[j]=0;
    for(int i=2; i<=100000; i++) if(bs[i]) p.push_back(i);
    len = p.size();
    int p_awal = -1, p_akhir = -1;
    
    scanf("%d%d", &awal, &akhir);
    for(int i=0; i<len; i++) {
        if(p[i] >= awal and p_awal == -1) p_awal=i; 
        if(p[i] > akhir and p_akhir == -1) p_akhir=i;
    }
    bool dapet = 0;
    for(int i=p_awal; i<p_akhir; i++) {
        for(int j=p_awal; j<p_akhir; j++) {
           memset(s,0,sizeof s);
           int ctr = 0;
           int x = p[j];
           while(x>0) s[ctr++]+=x%10+'0',x/=10;
           x = p[i];
           while(x>0) s[ctr++]+=x%10+'0',x/=10;
           long long num=0;
           for(long long k=0,pkt=1; k<ctr; k++,pkt*=10) {
               num+=(s[k]-'0')*pkt;
           }
           bool prima = cek(num);
           if(prima) {
               dapet = 1;
               printf("%d %d\n", p[i], p[j]);
           }
        }
    }
    if(!dapet) printf("TIDAK ADA\n");
    
    return 0;
}
