#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int n, tinggi, a[21000];
int main() {
    scanf("%d%d", &n, &tinggi);
    R(i,0,n) scanf("%d", &a[i]);
    sort(a, a+n);
    int sum = 0, pos = 0;
    RV(i, n-1, 0) {
        sum += a[i];
        pos++;
        if(sum >= tinggi) {
            break;
        }
    }
    printf("%d\n", pos);
    return  0;
}
