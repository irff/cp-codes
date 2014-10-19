#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d, xa, xb, xc;
int main() {
    while( scanf("%d %d %d %d", &a, &b, &c, &d) > 0 ) {
        int x = 1080;
        xa = (a-b+40)%40;
        xb = 40-(b-c+40)%40;
        xc = (c-d+40)%40;
        //printf("%d %d %d\n", xa, xb, xc);
        x += (xa+xb+xc) * 9;
        printf("%d\n", x);
    }
    return 0;
}
