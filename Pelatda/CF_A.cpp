#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", (b*c)+(a-1)*(b+c-1));
    return 0;
}
