#include <cstdio>
#include <algorithm>
using namespace std;

int na, nb, a[100000], ke;
int main() {
    scanf("%d%d%d", &na, &nb, &ke);
    for(int i=0; i<na+nb; i++) scanf("%d", &a[i]);
    sort(a, a+(na+nb));
    printf("%d\n", a[ke-1]);
    return 0;
}
