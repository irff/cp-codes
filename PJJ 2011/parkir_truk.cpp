#include <cstdio>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
 
int bs[1000];
int a,b,c,d,e,f;
int main(){
    scanf("%d%d%d", &a,&b,&c);
    for(int i=0; i<3; i++){
        scanf("%d%d", &e, &f);
        for(int j=e+1; j<=f; j++){
           bs[j]++;
        }
    }
    for(int i=1; i<=100; i++){
        if(bs[i]==1) d+=a;
        if(bs[i]==2) d+=(b*2);
        if(bs[i]==3) d+=(c*3);
    }
    printf("%d\n", d);
    scanf("\n");
    return 0;
}
