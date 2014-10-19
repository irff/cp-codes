#include <cstdio>
#include <algorithm>
using namespace std;

int a[10], ans, satu=0, dua=0, tiga = 0;
int main() {
    scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
    while(a[1]!=0 or a[2]!=0 or a[3]!=0 or a[4]!=0 or a[6]!=0) {
        ans = a[6]; satu=0, dua=0, tiga=0;
        ans +=a[5]; satu+=(a[5]*11);
        ans +=a[4]; dua +=(a[4]*5);
        ans +=a[3]/4; tiga = a[3]%4;
        
        if(tiga!=0) ans++;
        if(tiga==1) dua+=5,satu+=7;
        else if(tiga==2) dua+=3,satu+=6;
        else if(tiga==3) dua+=1,satu+=5;
        
        if(a[2] <= dua) {
            dua-=a[2];
            satu+=(dua*4);
        } else {
            a[2]-=dua;
            int sisa = 0;
            ans+=a[2]/9; dua=a[2]%9;
            if(dua!=0) {
                satu+=(dua*4);
                ans++;
            }
        }
        
        if(a[1] > satu) {
            a[1]-=satu;
            ans+=a[1]/36; satu = a[1]%36;
            if(satu!=0) ans++;
        }
        printf("%d\n", ans);
        scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
    }
    return 0;
}
