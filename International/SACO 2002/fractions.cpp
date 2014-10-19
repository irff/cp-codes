#include <cstdio>
#include <algorithm>
using namespace std;

int a,b;

int main() {
    scanf("%d%d", &a,&b);
    for(int i=2; i<10000; i++) {
        int e=i*a-b;
        if(e > 0) {
            a=e; b*=i;
            int g=__gcd(a,b);
            a/=g; b/=g;
            printf("1/%d+", i);
        }
        if(a == 1) {
            printf("1/%d\n", b);
            break;
        } else 
        if(e == 0) {
            printf("1/%d\n", i);
            break;
        }
    }
    return 0;
}
