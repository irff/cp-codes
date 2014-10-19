#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int a, b;
int main() {
    scanf("%d%d", &a, &b);
    printf("masing-masing %d\n", a/b);
    printf("bersisa %d\n", a%b);
    return 0;
}
