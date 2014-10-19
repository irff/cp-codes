#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, a[1000], low, high;
int main() {
    scanf("%d", &teskes);
    R(k,0,teskes) {
        scanf("%d", &n);
        R(i,0,n) scanf("%d", &a[i]);
        low = 0, high = 0;
        R(i,1,n) 
            if(a[i] < a[i-1]) low++;
            else if(a[i] > a[i-1]) high++;
        printf("Case %d: %d %d\n", k+1, high, low);
    }
    return 0;
}
