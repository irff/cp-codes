#include <cstdio>
#include <cstring>
#include <algorithm>

int a[3];
int main(){
    int hasil=0;
    for(int i=0; i<3; i++){
        scanf("%d%d%d", &a[0],&a[1],&a[2]);
        std::sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) hasil++;
    }
    printf("%d\n", hasil);
    scanf("\n");
    return 0;
}
