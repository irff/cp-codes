#include <cstdio>
#include <algorithm>
using namespace std;

int t, a, b;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        printf("%c\n", a==b?'=':(a<b?'<':'>'));
    }
    return 0;
}
