#include <cstdio>
#include <algorithm>
#define MAKS 1500
using namespace std;

int teskes,n,pk2,pemenang;
int a[MAKS];
int nmaks;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        pk2=1;
	nmaks=-30000;
        for(int i=0; i<n; i++)pk2*=2;
        for(int i=0; i<pk2; i++){
            scanf("%d", &a[i]);
            if(a[i]>nmaks) { nmaks=a[i]; pemenang=i; }
        }
        printf("%d\n", pemenang+1);
    }    
    return 0;
}
