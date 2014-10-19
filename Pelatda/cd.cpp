#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;
VI v;

VI winning_solution;
int maks,n,a[30];
int ans=0, unused=2000111222, hasil = 0, sum;

void rek(int ke, int dp, int len, int sisa) {
    if(ke >=n) {
        if(sisa >= 0) {
            if(len > ans) {
                hasil = dp;
                unused = sisa;
                sum = maks-sisa;
                ans = len;
            } else if(len == ans) {
                if( sisa < unused) {
                    hasil = dp;
                    unused = sisa;
                    sum = maks-sisa;
                }
            }
        }
        return ;
    }
    // ga ngambil
    rek(ke+1, dp, len, sisa);
    // ngambil
    dp = dp | (1<<ke);
    rek(ke+1, dp, len+1, sisa-a[ke]);
}

int main() {
    while(scanf("%d", &maks)>0) {
        ans = 0; unused = 2000111222,sum=0;
        scanf("%d", &n);
        R(i,0,n) scanf("%d", &a[i]);

        rek(0,0,0,maks);
        int ctr=0;
        while(hasil>0) {
            if(hasil%2) printf("%d ", a[ctr]);
            hasil/=2;
            ctr++;
        }
        int len = ans;
        printf("sum:%d\n", sum);
    }
    return 0;
}
