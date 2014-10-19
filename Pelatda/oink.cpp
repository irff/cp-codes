#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD n, num, a[30], m[30];
bool palsu[30];
LLD ans = 0;
char sampah[1000];

LLD lcm(LLD a, LLD b) {
    return a*(b/__gcd(a,b));
}

void rek(int ke, int sub, LLD kpk) {
    if(ke==n) return ;
    //printf("%d %d\n", sub, kpk);
    if(sub%2==0) {
        ans-=(LLD)(num/kpk);
    } else {
        ans+=(LLD)(num/kpk);
    }
    R(i,ke+1,n) {
        rek(i,sub+1,lcm(m[i],kpk));
    }
}

int main() {
    gets(sampah);
    scanf("%lld%lld", &n, &num);
    R(i,0,n) {
        scanf("%lld", &a[i]);
    }
    R(i,0,n) {
        R(j,i+1,n) {
            if(a[i] % a[j] == 0) palsu[i] = 1;
            if(a[j] % a[i] == 0) palsu[j] = 1;
            if(a[i] == a[j]) palsu[i] = 0;
        }
    }
    int nasli = 0;
    R(i,0,n) if(!palsu[i]) m[nasli++] = a[i];
    n = nasli;
    //R(i,0,n) ans += (LLD)(num/m[i]);
    
    /*
    printf("%lld\n", ans);
    R(i,0,n) {
        R(j,i+1,n) {
            ans -= (LLD)(num/(m[i]*m[j]));
        }
    }*/
    R(i,0,n) rek(i,1,m[i]);
    printf("%lld\n", ans);
    
    return 0;
}
