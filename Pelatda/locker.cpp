#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int n, k;
int main() {
    scanf("%d%d", &n, &k);
    R(i,0,k) {
        int num;
        scanf("%d", &num);
        int x = (int)sqrt( (double)num);
        if(x*x == num) {
            printf("TUTUP\n");
        } else printf("BUKA\n");
    }

    return 0;
}
