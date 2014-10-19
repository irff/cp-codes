#include <cstdio>
#include <cstdlib> 
 
int main(){
//------------------------------------
    int a,b,c,d;
    scanf("%d%d%d%d", &a,&b,&c,&d);
    int hasil=abs(a-c)+abs(b-d);
    printf("%d\n", hasil);
//------------------------------------
    return 0;
}
