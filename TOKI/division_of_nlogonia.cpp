#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int main() {
    while( scanf("%d", &n), n!=0) {
        int x, y;
        scanf("%d%d", &x, &y);
        R(i,0,n) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a==x or b==y) printf("divisa\n");
            else if(a > x and b > y) printf("NE\n");
            else if(a > x and b < y) printf("SE\n");
            else if(a < x and b < y) printf("SO\n");
            else if(a < x and b > y) printf("NO\n");
        }
    }
    return 0;
}
