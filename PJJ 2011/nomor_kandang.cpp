#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD n, duit, harga[11], hasil=0;
bool nol = 0, memang_bener_bener_nol = 0;
LLD digits[11];
int ctr=0;
char s[100];

int main() {
    scanf("%lld", &n);
    R(i,0,n+1) scanf("%lld", &harga[i]);
    scanf("%lld", &duit);
    
    LLD pertama = 1, mins = harga[1];
    
    R(i,1,n+1) if(mins >= harga[i]) mins=harga[i],pertama=i;
    
    if(mins <= harga[0]) {       
        if(duit >= mins) {
            digits[pertama]+=(duit/mins);
            hasil+=(duit/mins);
            duit -= hasil*mins;
            
            
            for(int i=n; i>pertama; i--) {
                LLD pindah = duit/(harga[i]-mins);
                if(pindah > digits[pertama]) pindah = digits[pertama];
                digits[i] = pindah;
                digits[pertama] -= pindah;
                duit -= pindah*(harga[i]-mins);
            }
            
        } else nol = 1;
        
    } else {
        if(harga[0] > duit) nol = 1;
        else if(mins > duit) memang_bener_bener_nol = 1;
        else {
            hasil = 1+(duit-mins)/harga[0];
            digits[0] = hasil;
            duit -= hasil*harga[0];
            
            for(int i=n; i>=1; i--) {
                LLD pindah = duit/(harga[i]-harga[0]);
                if(pindah > digits[0]) pindah = digits[0];
                digits[i] = pindah;
                digits[0] -= pindah;
                duit -= pindah*(harga[i]-harga[0]);
            }
            
        }
    }
    if(nol) printf("0\n");
    else if(memang_bener_bener_nol) printf("1\n0\n0\n");
    else {
         
        ctr = 0;
        for(int i=n; i>=0 and ctr<50; i--) {
            int x = digits[i];
            while(x>0 and ctr<50) {
                s[ctr++]=i+'0';
                x--;
            }
        }
        printf("%lld\n", hasil);
        printf("%s\n",  s);
    
        ctr = 0;
        memset(s,0, sizeof s);
        for(int i=0; i<=n and ctr<50; i++) {
            int x = digits[i];
            while(x > 0 and ctr<50) {
                s[ctr++]=i+'0';
                x--;
            }
        }
        reverse(s, s+ctr);
        printf("%s\n", s);
    }
    return 0;
}
