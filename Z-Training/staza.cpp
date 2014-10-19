#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a,b,n,sam[3];
int main(){
    scanf("%d", &n);
    for(int i=0; i<2*n; i++){
        scanf("%d:%d", &a,&b);
        if(i+1%n==0) sam[i/n]=a*60+b;
    }
    printf("%s\n", sam[1]<sam[2]?"Marko":"Dario");
    scanf("\n");
    return 0;
}
