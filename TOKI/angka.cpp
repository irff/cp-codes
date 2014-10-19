#include <cstdio>
#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_b);i>=int(_a);i--)
 
typedef long long LLD;
int n, len;
string s;
LLD ans, a[100];
  
void rek(int ke, LLD x) {
    if(ke>=n) {
        ans = max(ans, x);
        return ;
    }
    rek(ke+1, a[ke]^x);
    rek(ke+1, x);
}
 
int main() {
    scanf("%d%d", &n, &len);
    R(i,0,n) {
        cin >> s;
        a[i] = 0;
        for(int j=0,k=len-1; j<len; j++,k--) {
            if(s[j]=='1') a[i]+=(LLD)((LLD)1<<k);
        }
    }
    ans = 0;
    rek(0,0);
    for(int i=len-1; i>=0; i--) {
        if(ans&(LLD)((LLD)1<<i)) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
