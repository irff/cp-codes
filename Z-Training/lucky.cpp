#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int n;
int sum[50];
int pola[50];
int main(){
    scanf("%d", &n);
    sum[0]=0;
    for(int i=1; i<=31; i++){
        sum[i-1]=(1 << i+1) -2;
    }
    int i=1;
    while(sum[i-1]<n){
        i++;
    }
    int lim=i;
    //printf("lim : %d\n", lim);
    int k=n-sum[lim-2];
    //printf("%d\n", k);
//-----------------------------------------
    int ct=0;
    if(k%2==1) pola[ct]=4;
    else pola[ct]=7;
    for(int i=2; i<=lim; i++){
        ct++;
        if((k-1)%((1<<i))<(1<<i-1)) pola[ct]=4;
        else pola[ct]=7;
    }
    for(int i=ct; i>=0; i--) printf("%d", pola[i]);
    puts("");
    scanf("\n");
    return 0;
}
