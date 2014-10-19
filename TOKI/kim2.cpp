#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int Q;
char s[100], in[100];
char c[1000111][12];
long long vol[1000111], num;
int ctr = 1;
int main() {
    scanf("%d", &Q);
    while(Q--) {
        scanf("%s", &s);
        //R(i,0,ctr+1) printf("%d\n", vol[i]);
        if(s[0]=='T') {
            scanf("%s", &in);
            scanf("%lld", &num);
            if(strcmp(c[ctr],in)==0) {
                vol[ctr]+=num;
            } else {
                ctr++;
                strcpy(c[ctr], in);
                vol[ctr]=num;
                //printf("%lld\n", vol[ctr]);
            }
        } else
        if(s[0]=='A') {
            scanf("%lld", &num);
            while(num>0) {
                if(num>=vol[ctr]) {
                    num-=vol[ctr];
                    ctr--;
                } else {
                    vol[ctr] -= num;
                    num = 0;
                }
            }
        } else {
            printf("%s\n", c[ctr]);
        }
    }

    return 0;
}
