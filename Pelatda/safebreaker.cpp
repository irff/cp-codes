#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n;
char s[100][100], str[10], sol[10];
int bener[100], salah[100];

typedef pair<int,int> PII;

PII score(const char sa[], const char si[]) {
    char a[10], b[10];
    strcpy(a,sa); strcpy(b,si);
    PII x;
    int ben = 0, sal = 0;
    R(i,0,4) if(a[i]==b[i]) ben++, a[i] = 'A', b[i] = 'A';
    R(i,0,4) {
        R(j,0,4) {
            if(a[i]>='0' and a[i]<='9' and b[j]>='0' and b[j]<='9') {
                if(a[i]==b[j]) {
                    sal++;
                    a[i] = 'A', b[j] = 'B';
                    break;
                }
            }
        }
    }
    x = PII(ben, sal);
    return x;
}


int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        R(i,0,n) {
            scanf("%s %d/%d", &s[i], &bener[i], &salah[i]);
            //printf("%s-%d-%d\n", s[i], bener[i], salah[i]);
        }
        memset(sol, 0, sizeof sol);
        int nsol = 0;
        R(i,0,10000) {
            R(j,0,4) str[j] = '0';
            int x = i, ctr = 0;
            while(x > 0) {
                str[ctr++] = x%10+'0';
                x/=10;
            }
            reverse(str, str+4);
            //printf("%s\n", str);
            bool bisa = 1;
            R(j,0,n) {
                PII p = score(str, s[j]);
                //printf("%s - %s -> %d/%d\n", str, s[j], p.first, p.second);
                if(p.first!=bener[j] or p.second!=salah[j]) bisa = 0;
            }
            if(bisa) {
                strcpy(sol, str);
                nsol++;
            }
        }
        if(nsol==0) printf("impossible\n");
        else if(nsol==1) printf("%s\n", sol);
        else printf("indeterminate\n");
    }

    return 0;
}
