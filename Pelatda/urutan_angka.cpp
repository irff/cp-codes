#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LLD;

LLD ke;
LLD d[10];
int main() {
    LLD n=1, inc=0, x = 1, sel=0,dig = 1;
    scanf("%lldd", &ke);
    while(1) {
        if(n > ke) {
            n-=inc;
            x--;
            sel = ke-n;
            break;
        }
        if(x<10) {
            dig=1;
            inc++;
        } else
        if(x<100) {
           dig=2;
           inc+=2;
        } else
        if(x<1000) {
            dig=3;
           inc+=3;
        } else
        if(x<10000) {
           dig=4;
           inc+=4;
        } else
        if(x<100000) {
           dig=5;
           inc+=5;
        }
        n+=inc;
        x++;
    }
    //printf("%d\n", x);
    LLD ans = 0, tmp = n;
    dig=1;
    
    for(LLD i=1; i<=x; i++) {
        
        if(i<10) tmp++,dig=1;
        else if(i<100) tmp+=2,dig=2;
        else if(i<1000) tmp+=3,dig=3;
        else if(i<10000) tmp+=4,dig=4;
        else if(i<100000) tmp+=5,dig=5;
        if(tmp>=ke) {
          //printf("%d\n", i);
          tmp-=dig;
          LLD num = i, ctr=0; 
          while(num>0) { 
            d[ctr++]=num%10; num/=10;
          }
          reverse(d,d+ctr);
          for(LLD j=0; j<ctr; j++) {
            if(tmp==ke) { printf("%d\n", d[j]); return 0; }
            tmp++;
          }
        }
    }
    return 0;
}
