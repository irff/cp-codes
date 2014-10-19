#include <cstdio>

int x,n,id=0;
int a[100];
int main() {
    scanf("%d", &n);
    x=n;
    while(x>0)a[id++]=x%2, x/=2;
    for(int i=id-1; i>=0; i--) printf("%d", a[i]);
    printf("\n%o\n%X\n", n,n);  
}
