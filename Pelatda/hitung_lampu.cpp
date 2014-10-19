#include <cstdio>

int n, q;
bool a[600];
int main() {
    scanf("%d%d", &n, &q);
    for(int i=0; i<q; i++) {
        int p, x, y, c = 0; scanf("%d%d%d", &p, &x, &y);
        if(p) {
            for(int j=x; j<=y; j++) if(a[j]) c++;
            printf("%d\n", c);
        }
        else for(int j=x; j<=y; j++) a[j]=!a[j];
    }
    return 0;
}
