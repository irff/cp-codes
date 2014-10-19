#include <stdio.h>
#include <bool.h>
#define R(i,_a,_b) for(i=(_a);i<(_b);i++)

int num;
int primi[2000], prim[1000000],ni=0,na=0;
bool bsi[12000];
bool bs[100111222];

int main() {
    int i,j;
    for(i=0; i<=10000; i++) bsi[i]=1;
    for(i=2; i*i<=10000; i++)
      for(j=i*i; j<=10000; j+=i) bsi[j]=0;
    
    R(i,2,10000) if( bsi[i] ) primi[ni++]=i;
    
    bs[0]=1; bs[1]=1;
    
    for(i=0; i<ni; i++) {
      //printf("%d\n", primi[i]);
      for(j=primi[i]*primi[i]; j<=100000000; j+=primi[i]) bs[j]=1;
    }
    prim[0]=2; na++;
    for(i=3; i<=100000000; i+=2) if(!bs[i]) prim[na++]=i;
    //printf("%d\n", prim[na-1]);
    
    while(scanf("%d", &num)>0) {
        if(num%2) {
            if(bs[num-2]) printf("%d is not the sum of two primes!\n", num);
            else printf("%d is the sum of 2 and %d.\n", num, num-2);
        } else {
          bool bisa = 0;
          
          for(i=0; i<na and prim[i]<num; i++) {
            if(prim[i]*2!=num and !bs[ num-prim[i] ]) {
                printf("%d is the sum of %d and %d.\n", num, prim[i], num-prim[i]);
                bisa = 1;
                break;
            }
          }
          if(!bisa) printf("%d is not the sum of two primes!\n", num);
        }
    }
    return 0;
}
