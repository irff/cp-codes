#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, ca, cb, n;
int main() {
    bool pertamax = 1;
    while(scanf("%d%d%d", &ca, &cb, &n) > 0) {
        a = 0, b = 0;
        bool success = 0;
        while(!success) {
            if(b == n) {
                printf("success");
                success = 1;
            } else
            if(b == cb) {
                printf("empty B");
                b = 0;
            } else
            if(a == 0) {
                printf("fill A");
                a = ca;
            } else {
                printf("pour A B");
                if( a + b >= cb) {
                    a = (a+b) % cb;
                    b = cb;
                } else {
                    b+=a;
                    a = 0;
                }
            }
            printf("\n");
        }
    }

    return 0;
}
