#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int teskes;
char s[100], garap[100],angka[100],bar[100],kol[100],basis[100];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &s);
        int len = strlen(s);
        int ketemu = 0;
        R(i,0,len) {
            if(s[i] >= '0' and s[i] <='9') {
                if( s[i+1] < '0' or s[i+1] >'9') {
                    ketemu++;
                }
            }
        }
        if(ketemu==1) {
            memset(garap,0,sizeof garap);
            memset(angka,0,sizeof angka);
            int ctr=0;
            R(i,0,len) {
                if(s[i]>='A' and s[i]<='Z') garap[ctr++]=s[i];
                else break;
            }
            int lena=strlen(garap);
            ctr=0;
            R(i,lena,len) angka[ctr++]=s[i];
            int pangkat=1,col=0;
            
            RV(i,lena-1,0) {
                col+=(pangkat*(garap[i]-'A'+1));
                pangkat*=26;
            }
            printf("R%sC%d\n", angka, col);
        
        } else {
            memset(bar, 0, sizeof bar);
            memset(kol, 0, sizeof kol);
            memset(basis, 0, sizeof basis);
            int ctr=0;
            R(i,1,len) {
                if(s[i] >= '0' and s[i] <= '9') bar[ctr++] = s[i];
                else break;
            }
            int lena=ctr;
            ctr=0;
            R(i,lena+2,len) {
                if(s[i] >= '0' and s[i] <= '9') kol[ctr++] = s[i];
                else break;
            }
            int num = atoi(kol);
            ctr = 0;
            int pangkat = 1;
            while(num > 0) {
                if(num%26==0) basis[ctr++]='Z',num-=1;
                else basis[ctr++] = 'A'+(num%26)-1;
                num/=26;
            }
            reverse(basis,basis+ctr);
            printf("%s%s\n", basis,bar);
        }
    }
    return 0;
}
