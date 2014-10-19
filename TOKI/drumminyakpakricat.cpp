#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF=1000111222;

int memo1[1200], memo2[1200];
int k[1200], h[1200];
int teskes, nliter, kapdrum, hardrum, nfas;

int f1(int kapmaks) {
    int mins=INF;
    if(kapmaks == 0) return 0;
    if(kapmaks < 0 ) return INF;
    
    if(memo1[kapmaks] != -1) return memo1[kapmaks];
    
    for(int i=0; i<nfas; i++) {
        mins=min(mins, f1(kapmaks-k[i])+h[i]);
    }
    return memo1[kapmaks]=mins;
}

int f2(int n) {
    int mins=INF;
    if(n == 0) return 0;
    if(n < 0) return INF;
    
    if(memo2[n] != -1) return memo2[n];
    
    for(int i=1; i<=kapdrum; i++) {
        mins=min(mins, f2(n-i)+f1(i)+hardrum);
    }
    return memo2[n]=mins;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(memo1, -1, sizeof memo1);
        memset(memo2, -1, sizeof memo2);
        scanf("%d%d%d%d", &nliter, &kapdrum, &hardrum, &nfas);
        for(int i=0; i<nfas; i++) scanf("%d%d", &k[i], &h[i]);
        
        int hasil=f2(nliter);
        if(hasil==INF) hasil=-1;
        printf("%d\n", hasil);
    }    
    return 0;
}
