/*
    ID: irfan1
    LANG: C++
    TASK: zerosum
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define Re(i,_a,_b) for(i=int(_a);i<int(_b);i++)
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, m[10],a[8];
int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    scanf("%d", &n);
    R(i,0,8) if(i<n-1) m[i]=3; else m[i]=1;
    
    Re(a[0],0,m[0]) Re(a[1],0,m[1]) Re(a[2],0,m[2]) Re(a[3],0,m[3]) Re(a[4],0,m[4]) Re(a[5],0,m[5]) Re(a[6],0,m[6]) Re(a[7],0,m[7]) {
        int hasil=0;
        int before = 1, tadi=1, sekarang=0;
        bool minus = 0;
        for(int i=0; i<n; i++) {
            if(i==n-1) {
                if(minus) hasil = before - tadi;
                else hasil = hasil + tadi;
                break; 
            }
            //gabung
            if(a[i]==0) { tadi = tadi*10+(i+2); }

            //plus
            if(a[i]==1) {
              if(minus) {
                  hasil = before - tadi;
                  tadi  = i+2;
                  minus = 0;
              } else {
                  hasil = hasil + tadi;
                  tadi  = i+2;
              }
            }
            
            //minus
            if(a[i]==2) {
              if(minus) {
                  hasil  = before - tadi;
                  before = hasil;
                  tadi   = i+2;
              } else {
                  before = hasil+tadi;
                  tadi   = i+2;
                  minus  = 1;
              }
              hasil=hasil+(i+2);
            }
        }
        if(hasil==0) {
            for(int i=0; i<n-1; i++) {
                printf("%d%c", i+1,(a[i]==0?' ':(a[i]==1)?'+':'-'));
            }
            printf("%d\n", n);
        }
    }

    return 0;
}
