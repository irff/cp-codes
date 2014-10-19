#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef unsigned long long ULL;
int teskes, p, q;
ULL ans = 0;
string s;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        s.clear();
        ans = 0;
        scanf("%d%d", &p, &q);
        while(p>1 and q>0) {
            s+="101";
            p-=2; q--;
        }
        if(p>0 and q==0) {
            while(p>0) s+="1",p--;
        } else
        if(p==1) {
            s = "1"+s;
        }
        int len = s.length();
        ULL pangkat = 1;
        for(int i=len-1; i>=0; i--) {
            if(s[i]=='1') ans+=pangkat;
            pangkat*=2;
        }
        printf("%llu\n", ans);
        //printf("%s\n", s.c_str());
    }
    return 0;
}
