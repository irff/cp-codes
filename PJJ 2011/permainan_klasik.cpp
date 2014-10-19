#include <cstdio>
using namespace std;

int teskes, n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        if(n % 6 == 0) printf("TIDAK\n");
        else printf("YA\n");
    }

    return 0;
}
