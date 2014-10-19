#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;


char z[100][100];
bool jalan,nemu,lanjut;
int teskes,bar,kol,maks,kotak;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        maks=0;
        scanf("%d", &bar);
        for(int i=0; i<bar; i++) scanf("%s", &z[i]);
        lanjut=1;
        kotak=bar;
        for(int i=kotak; i>=1; i--){
         for(int j=0; j<=(kotak-i); j++)
          for(int k=0; k<=(kotak-i); k++){
           nemu=1;
           for(int l=k; l<(k+i); l++)
             for(int m=j; m<(j+i); m++)
                 if(z[l][m]!='.') nemu=0;
           if(nemu) maks=max(i,maks);
          }
          
        }
        printf("%d\n", maks);
    }


}
