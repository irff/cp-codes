#include <cstdio>

bool leap;
int n;
int main(){
    scanf("%d", &n);
    if(n%400==0) leap=1;
    if(n%4==0 and n%100!=0) leap=1;
    printf("%s\n", leap?"Prestupna":"Nije prestupna");
    scanf("\n");
    return 0;
}
