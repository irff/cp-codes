/*
    ID: irfan1
    LANG: C++
    TASK: pprime
*/
#include <cstdio>

int awal, akhir, prim[6000111], na=0, pal[1000], np=0;
char s[100], c = 0;
bool bs[100111222];
int main() {
    bs[0]=1; bs[1]=1;
    for(int i=2; i<=10000; i++)
      if(!bs[i]) for(int j=i*i; j<=100000000; j+=i) bs[j] = 1;
    
    for(int i=2; i<=100000000; i++) if(!bs[i]) prim[na++]=i;
    printf("%d\n", na);
    for(int i=0; i<na; i++) {
        int x = prim[i], c=0;
        while(x>0) s[c++]=x%10+'0',x/=10;
        bool jadi = 1;
        for(int j=0; j<c/2; j++) {
            if(s[j]!=s[c-j-1]) { jadi = 0; break; }
        }
        if(jadi) pal[np++]=prim[i];
    }
    //freopen("pprime.in", "r", stdin);
    //freopen("pprime.out", "w", stdout);
    scanf("%d%d", &awal, &akhir);
    for(int i=0; i<np; i++) {
        if(pal[i] >=awal and pal[i] <= akhir) printf("%d\n", pal[i]);
    }
    return 0;
}
