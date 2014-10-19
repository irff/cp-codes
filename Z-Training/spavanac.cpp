#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int ha,ma;
int main(){
    scanf("%d%d", &ha,&ma);
    printf("%d %d\n", (ha+24-(1-ma/45))%24,(ma+15)%60);
    scanf("\n");
    return 0;
}
