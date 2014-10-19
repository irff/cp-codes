/*
    ID: irfan1
    LANG: C++
    TASK: pprime
*/
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int awal, akhir, prim[20000], na=0, pal[1000], np=0;
char s[100], c = 0;
bool bs[20000];
map<int,bool> m;

bool cek(int n) {
    int x = n, c=0;
    bool jadi =1;
    while(x>0 and c<na) {
        if(x%prim[c]==0 and prim[c]!=n) {
            return 0;
        }
        c++;
    }
    return 1;
}

int main() {
    bs[0]=1; bs[1]=1;
    for(int i=2; i*i<=10000; i++)
      if(!bs[i]) for(int j=i*i; j<=10000; j+=i) bs[j] = 1;
    for(int i=2; i<=10000; i++) {
      if(!bs[i]) prim[na++]=i;
    }
    
    //while(scanf("%d", &awal)>0) printf("%d\n", cek(awal));
    
    for(int ia=1; ia<10; ia+=2) {
      for(int ib=0; ib<10; ib++) {
        for(int ic=0; ic<10; ic++) {
          for(int id=0; id<10; id++) {
              int d1 = ia;
              int d2 = ia*10+ia;
              int d3 = ia*100+ib*10+ia;
              int d4 = ia*1000+ib*100+ib*10+ia;
              int d5 = ia*10000+ib*1000+ic*100+ib*10+ia;
              int d6 = ia*100000+ib*10000+ic*1000+ic*100+ib*10+ia;
              int d7 = ia*1000000+ib*100000+ic*10000+id*1000+ic*100+ib*10+ia;
              int d8 = ia*10000000+ib*1000000+ic*100000+id*10000+id*1000+ic*100+ib*10+ia;
              //if(!m[d5]) printf("%d %d %d %d %d - %d\n", ia, ib, ic, ib, ia, d5);
              if(!m[d1]) { if(cek(d1)) pal[np++]=d1; m[d1]=1; }
              if(!m[d2]) { if(cek(d2)) pal[np++]=d2; m[d2]=1; }
              if(!m[d3]) { if(cek(d3)) pal[np++]=d3; m[d3]=1; }
              if(!m[d4]) { if(cek(d4)) pal[np++]=d4; m[d4]=1; }
              if(!m[d5]) { if(cek(d5)) pal[np++]=d5; m[d5]=1; }
              if(!m[d6]) { if(cek(d6)) pal[np++]=d6; m[d6]=1; }
              if(!m[d7]) { if(cek(d7)) pal[np++]=d7; m[d7]=1; }
              if(!m[d8]) { if(cek(d8)) pal[np++]=d8; m[d8]=1; }
          }
        }
      }
    }
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    sort(pal, pal+np);
    scanf("%d%d", &awal, &akhir);
    for(int i=0; i<np; i++) {
        if(pal[i] >=awal and pal[i] <= akhir) printf("%d\n", pal[i]);
    }
    return 0;
}
