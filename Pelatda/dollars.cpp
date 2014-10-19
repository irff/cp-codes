#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

long long n,cc[35000],ans;
int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
int main() {
    cc[0]=1;
    for(int i=0; i<11; i++) {
        for(int j=1; j<=35000; j++) {
            if(j-coin[i] >=0) cc[j] += cc[j-coin[i]];
        }
    }
    double x;
    int a,b;
    string s;
    while(scanf("%d.%d", &a, &b) > 0) {
       s.assign(17,' ');
       n = a*100+b;
       if(n==0) break;
       ans = cc[n];
       //printf("%lld %lld\n", n, ans);
       int ctr = 16;
       while(ans>0) {
           s[ctr]=ans%10+'0';
           ctr--; ans/=10;
       }
       
       if(a<10) printf("  %d.", a);
       else if(a<100) printf(" %d.", a);
       else printf("%d.",a);
       
       if(b<10) printf("0%d", b);
       else printf("%d", b);
       
       printf("%s\n",s.c_str());
    }

    return 0;
}
