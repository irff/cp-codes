/*
    ID: irfan1
    LANG: C++
    TASK: prefix
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

string prim[250], s, sampah;
int ctr = 0, ans = 0, len = 0, pan[250];
int memo[200111];

int dp(int ke) {
    if(memo[ke]==-1) {
        if(ke>=len) return memo[ke] = 0;
        
        int maks = 0;
        R(i,0,ctr) {
            int j = 0;
            for(; j<pan[i]; j++) {
                if(prim[i][j]!=s[ke+j]) break;
            }
            //printf("%d %d %d\n", i, j, ke);
            if(j>=pan[i]) {
                maks = max(maks, dp(ke+j)+j);
            }
        }
        return memo[ke] = maks;
    }
    return memo[ke];
}

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    memset(memo, -1, sizeof memo);
    while( cin >> sampah) {
        if(sampah!=".") {
            pan[ctr] = sampah.length();
            prim[ctr++] = sampah;
        } else {
            break;
        }
    }
    while(cin >> sampah) {
        s+=sampah;
    }
    len = s.length();
    ans = dp(0);
    printf("%d\n", ans);
    return 0;
}
