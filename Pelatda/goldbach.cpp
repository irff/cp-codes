#include <stdio.h>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int num;
int primi[2000], prim[1000000],ni=0,na=0;
bool bsi[12000];
bool bs[100111222];

int main() {
    for(int i=0; i<=10000; i++) bsi[i]=1;
    for(int i=2; i*i<=10000; i++)
      for(int j=i*i; j<=10000; j+=i) bsi[j]=0;
    
    R(i,2,10000) if( bsi[i] ) primi[ni++]=i;
    
    bs[0]=1; bs[1]=1;
    
    for(int i=0; i<ni; i++) {
      //printf("%d\n", primi[i]);
      for(int j=primi[i]*primi[i]; j<=100000000; j+=primi[i]) bs[j]=1;
    }
    prim[0]=2; na++;
    for(int i=3; i<=100000000; i+=2) if(!bs[i]) prim[na++]=i;
    //printf("%d\n", prim[na-1]);
    
    while(scanf("%d", &num)>0) {
        if(num==0 or num==1 or num==2 or num==3 or num==4) printf("1 is not the sum of two primes!\n");
        else if(num%2) {
            if(bs[num-2]) printf("%d is not the sum of two primes!\n", num);
            else printf("%d is the sum of 2 and %d.\n", num, num-2);
        } else {
          bool bisa = 0;
          
          int *pos = lower_bound(prim, prim+na, num/2-1);
          int lok = pos-prim;
          for(int i=lok; lok>=0; i--) {
            if(prim[i]*2!=num and !bs[ num-prim[i] ] and prim[i]!=num and prim[i]!=0) {
                int mins = min(prim[i],num-prim[i]);
                int maks = max(prim[i],num-prim[i]);
                printf("%d is the sum of %d and %d.\n", num, mins, maks);
                bisa = 1;
                break;
            }
          }
          if(!bisa) printf("%d is not the sum of two primes!\n", num);
        }
    }
    return 0;
}
