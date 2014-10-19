#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int m[12000];
int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)>0) {
        R(i,a,c) m[i] = max(m[i], b);
    }
    bool pertamax = 0;
    R(i,1,10000+1) {
        if(m[i]!=m[i-1]) {
            if(pertamax) printf(" ");
            pertamax = 1;
            printf("%d %d", i, m[i]);
        }
    }
    printf("\n");
    return 0;
}
