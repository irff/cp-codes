#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
#define RV(i,_a,_b) for(int i=int(_a); i>=int(_b); i--)

typedef long long LLD;
const LLD INF = 2000111222;

int a, b;
double area;

int main() {
    scanf("%d%d", &a, &b);
    area = (double)(a*b)/2;
    printf("%.2lf\n", area);
    scanf("\n");
    return 0;
}
