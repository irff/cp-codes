#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n,h,m,d;
int a[1500];
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d:%d %d", &h,&m,&d);
        int awal=h*60+m;
        int akhir=awal+d;
        for(int i=awal; i<akhir; i++) a[i%1440]++;
    }
    int total=0;
    for(int i=0; i<1440; i++){
        if(i>=420 and i<1140) total+=(a[i]*10);
        else total+=(a[i]*5);
    }
    printf("%d\n", total);
    scanf("\n");
    return 0;
}
