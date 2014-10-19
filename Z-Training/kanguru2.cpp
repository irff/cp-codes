#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

unsigned long long n,has;
int main(){
    scanf("%llu", &n);
    if(n==1) has=4;
    else has=n*(n+2)+1;
    printf("%llu\n", has);
    scanf("\n");
    return 0;
}
