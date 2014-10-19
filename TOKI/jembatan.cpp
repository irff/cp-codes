#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

char s[3000];
int len;
double hasil=0.00,dp[3000];

double rek(int id) {
    if(id>len) return 0;
    
    if(dp[id]>-1) return dp[id];
    
    if(s[id]=='.') {
        dp[id]=rek(id+1);
        return dp[id];
    }
    double hasil=0.00,tmp=0.00,mins=1000111222.00;
    for(int i=id; i<=len; i++) {
        if(s[i]=='X') {
            tmp=(double)sqrt(i-id+1);
            mins=min(mins,tmp+rek(i+1));
        }
    }
    dp[id]=mins;
    return dp[id];
}

int main() {
    memset(dp,-999999.00,sizeof dp);
    scanf("%s", s);
    len=strlen(s);
    for(int i=len; i>=1; i--) s[i]=s[i-1];
    hasil=rek(1);
    printf("%.3lf\n", hasil);
    return 0;
}
