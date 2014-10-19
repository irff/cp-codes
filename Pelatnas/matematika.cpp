#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
int n;
char s[1000];
long long hasil=0LL;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%s", s);
        int len=strlen(s),maks=-1;
        R(j,0,len) {
            if(isdigit(s[j])) s[j]-='0',maks=max(maks,(int)s[j]);
            if(isupper(s[j])) s[j]=s[j]-'A'+10,maks=max(maks,(int)s[j]);
            if(islower(s[j])) s[j]=s[j]-'a'+36,maks=max(maks,(int)s[j]);
        }
        long long tmp=0LL,pkt=1;
        RV(j,len-1,0) {
            tmp+=(pkt*s[j]);
            pkt*=(maks+1);
        }
        printf("%d %lld\n", maks+1, tmp);
        hasil+=tmp;
    }
    printf("%lld\n", hasil);
    return 0;
}
