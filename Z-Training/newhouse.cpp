
#include <cstdio>
#include <algorithm>
#define R(i,_a,_b) for(int i=int(_a); i<int(_b);i++)
char z[100][100];
bool jalan,nemu,lanjut;
int teskes,bar,kol,maks;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        maks=0;
        scanf("%d", &bar);
        for(int i=0; i<bar; i++) scanf("%s", &z[i]);
        for(int i=bar; i>=1; i--){
         R(j,0,bar-i+1)
          R(k,0,bar-i+1){
           nemu=1;
           R(l,k,k+i) R(m,j,j+i) if(z[l][m]!='.') nemu=0;
           if(nemu) maks=std::max(i,maks);
          }
          
        }
        printf("%d\n", maks);
    }


}
