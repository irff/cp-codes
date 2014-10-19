#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int awal, akhir, len, nprima;
bitset<1002000> bs;
vector<int> pr,pm;
char s[100];

bool prima(int s) {
    int n = s;
    for(int i=0; i<nprima; i++) {
        while(pm[i]!=s and n%pm[i]==0) {
            n/=pm[i];
        } 
        if(n==1) return 0;
    }
    
    return 1;
}

int main() {
    bs.set();
    bs[0]=0; bs[1]=0;
    for(int i=2; i*i<=1000000; i++) 
      for(int j=i*i; j<=1000000; j+=i)
        bs[j]=0;
    
    R(i,0,1000000) if(bs[i]) pm.push_back(i);
    nprima = pm.size();
    
    scanf("%d%d", &awal, &akhir);
    R(i,awal,akhir+1) if(bs[i]) pr.push_back(i);
    
    int len = pr.size();
    int total=0;
    
    R(i,0,len) {
        R(j,0,len) {
            int n = pr[j],ctr=0;
            while(n>0) s[ctr++]=n%10+'0',n/=10;
            n = pr[i];
            while(n>0) s[ctr++]=n%10+'0',n/=10;
            reverse(s, s+ctr);
            int num = atoi(s);
            if(prima(num)) printf("%d %d\n", pr[i], pr[j]),total++;
        }
    }
    if(total==0) printf("TIDAK ADA\n");
    return 0;
}
