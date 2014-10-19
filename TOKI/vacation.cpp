#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

string sa, si;
int lena, leni, kasus = 0;

int memo[120][120];

int rek(int a, int b) {
    int x = lena-a, y = leni-b;
    if(memo[a][b]==-1) {
        if(min(x,y)==0) return 0;
        int ret = 0;
        if(sa[a]==si[b]) ret = rek(a+1,b+1)+1;
        else {
            ret = max(ret, rek(a,b+1));
            ret = max(ret, rek(a+1,b));
        }
        return memo[a][b] = ret;
    }
    return memo[a][b];
}

int main() {
    getline(cin,sa);
    while(sa!="#") {
        getline(cin, si);
        lena = sa.length();
        leni = si.length();
        memset(memo, -1, sizeof memo);
        int ans = rek(0, 0);
        kasus++;
        printf("Case #%d: you can visit at most %d cities.\n", kasus, ans);
        getline(cin, sa);
    }

    return 0;
}
