#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
long long now,gajimaks,gaji,a[11000],jum;
int teskes,n;
long long jumlah(long long now){
     long long jum=0;
        R(j,0,n) {
               if(a[j]>now) jum+=now;
               else jum+=a[j];
        }
     return jum;
}
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        jum=0;
        scanf("%d%lld", &n, &gajimaks);
        R(i,0,n) { scanf("%lld", &a[i]); jum+=a[i]; }
        if(jum<=gajimaks) printf("-1\n");
        else {
            long long ki=0,ka=gajimaks,mid=0;
            while(ki<ka){
                mid=(ki+ka)/2;
                if(jumlah(mid)>gajimaks) ka=mid-1;
                else if(jumlah(mid)<gajimaks) ki=mid+1;
                else if(jumlah(mid)==gajimaks) break;
                else if(ki>=ka) break;
            }
            if(jumlah(mid)>gajimaks){
                while(jumlah(mid)>gajimaks){
                    mid-=1;
                }
            }
            else
            if(jumlah(mid)<gajimaks){
                while(jumlah(mid+1)<=gajimaks){
                    mid+=1;
                }
            }
            printf("%lld\n", mid);
        }
    }
    return 0;
}
