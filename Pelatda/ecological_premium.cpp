#include <cstdio>

int teskes, n, area, ani, e, prem;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        prem = 0;
        while(n--) {
            scanf("%d%d%d", &area, &ani, &e);
            prem += (area*e);
        }
        printf("%d\n", prem);
    }
    return 0;
}
