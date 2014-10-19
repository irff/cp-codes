#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

PIII a[12000];
int bar,kol,k;

int main() {
    scanf("%d%d%d", &bar, &kol, &k);
    int ctr=0;
    for(int i=1; i<=bar; i++) {
        for(int j=1; j<=kol; j++) {
            a[ctr++]=PIII(i+j,PII(i,j));
        }
    }
    sort(a,a+ctr);
    printf("%d %d\n", a[k-1].second.first, a[k-1].second.second);
    return 0;
}
