#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ctr=0, sum=0, orens=999;
int bs[1000000];
int main() {
    int nol=0;
    while(scanf("%d", &n)>0) {
            if(n==0) nol++;
            
            if( nol == 0 ) {
                int hijau = n;
                sum+=n;
                for(int i=0; (i+1)*hijau<=100000; i++) {
                    if(i%2==0) {
                        for(int j=i*(hijau); j<(i+1)*hijau-5; j++) {
                            bs[j]++;
                        }
                        //printf("%d %d\n", i*hijau, (i+1)*hijau-6);
                    }
                }
                orens = min(orens,n);
                ctr++;
            } else if(nol==1 and sum!=0){
                int detik = 0;
                for(int i=orens; i<=18000; i++) {
                    //printf("%d %d ", i, bs[i]);
                    if(bs[i]==ctr) {
                        detik = i;
                        break;
                    }
                }
                //printf("\n");
                if(detik==0) printf("Signals fail to synchronise in 5 hours\n");
                else {
                    int jam = detik/3600; detik%=3600;
                    int menit = detik/60; detik%=60;
                    if(jam<10) printf("0%d:", jam);
                    else printf("%d:", jam);
                    if(menit<10) printf("0%d:", menit);
                    else printf("%d:", menit);
                    if(detik<10) printf("0%d\n", detik);
                    else printf("%d\n", detik);
                }
                sum = 0;
                memset(bs,0,sizeof bs);
                ctr = 0;
                nol = 0;
                orens = 999;
            } else if(nol==3) return 0;
    }
    return 0;
}
