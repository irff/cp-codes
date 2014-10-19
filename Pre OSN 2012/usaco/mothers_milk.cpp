/*
    ID: irfan1
    LANG: C++
    TASK: milk3
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VII;

int a, b, c;

bool dp[3][3][25][25][25];
VII v;
int kap[4], ans[25];

void tuang(int dari, int ke, VII v) {
    
    VII x = v;
    int kosong = kap[ke] - v[ke];
    int pindah = v[dari];
    int mins = min(pindah, kosong);
    
    x[ke]+=mins; x[dari]-=mins;
    if(x[0]==0) ans[ x[2] ]=1;
    
    if(dp[dari][ke][v[0]][v[1]][v[2]]) return ;
    dp[dari][ke][v[0]][v[1]][v[2]]=1;
    
    R(i,0,3) {
        R(j,0,3) {
            // ga dari dan ke ember yg sama
            if(i!=j) {
                // ga di kembaliin ke ember tadi
                if(!(i==ke and j==dari)) {
                    // ga di isi lagi
                    if(j!=ke) {
                        //printf("%d %d - %d %d\n", dari, ke, i,j);
                        tuang(i,j,x);
                    }
                }
            }
        }
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    scanf("%d%d%d", &kap[0], &kap[1], &kap[2]);
    v.push_back(0); v.push_back(0); v.push_back(kap[2]);
    tuang(2,0,v);
    tuang(2,1,v);
    int s[100], ctr=0;
    for(int i=0; i<=kap[2]; i++) 
        if(ans[i]) {
            s[ctr++]=i;
        }
    for(int i=0; i<ctr; i++) {
        printf("%d", s[i]);
        if(i!=ctr-1) printf(" ");
    }
    printf("\n");
    return 0;
}
