#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n;
long jum,mins;
int a[3000];
int main(){
    mins=2123123123;;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=a[0]; i<a[n-1]; i++){
        jum=0;
        for(int j=i,k=0; j<i+n; j++,k++) jum=jum+labs(a[k]-j);
        if(jum<mins) mins=jum;
    }
    printf("%ld\n", mins);
    //system("PAUSE");
    return 0;
}
