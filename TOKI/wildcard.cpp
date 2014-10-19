#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,a,b) for(int i=int(a);i<int(b);i++)
char kunci[100],kata[100];
char awal[100],akhir[100];
int nkata,poskunci,lkunci;
bool sama;
int main(){
    scanf("%s", &kunci);
    scanf("%d", &nkata);
    R(i,0,strlen(kunci)) if(kunci[i]=='*'){ poskunci=i; break;}
    if(poskunci==strlen(kunci)-1 and poskunci==0){
        // Just *
        while(nkata--){
            scanf("%s", &kata);
            printf("%s\n", kata);
        }
    } else
    if(poskunci==strlen(kunci)-1 and poskunci!=0){
        // Prefix
        kunci[poskunci]='\0';
        lkunci=strlen(kunci);
        while(nkata--){
            scanf("%s", &kata);
            sama=1;
            R(i,0,lkunci) if(kata[i]!=kunci[i]) {sama=0; break;}
            if(sama) printf("%s\n", kata);
        }
    } else
    if(poskunci!=strlen(kunci)-1 and poskunci==0){
        // Postfix
        R(i,0,strlen(kunci)) kunci[i]=kunci[i+1];
        lkunci=strlen(kunci);
        reverse(kunci,kunci+lkunci);
        while(nkata--){
            scanf("%s", &kata);
            sama=1;
            reverse(kata,kata+(strlen(kata)));
            R(i,0,lkunci) if(kata[i]!=kunci[i]) {sama=0; break;}
            if(sama){
                reverse(kata,kata+(strlen(kata)));
                printf("%s\n", kata);
            }
        }
    }else
    if(poskunci!=strlen(kunci)-1 and poskunci!=0){
        // Prefix & Postfix
        lkunci=strlen(kunci);
        R(i,0,poskunci) awal[i]=kunci[i];
        awal[poskunci]='\0';
        R(i,poskunci+1,lkunci) akhir[i-poskunci-1]=kunci[i];
        akhir[lkunci-1]='\0';
        reverse(akhir,akhir+(strlen(akhir)));
      while(nkata--){
        scanf("%s", &kata);
        sama=1;
        R(i,0,strlen(awal)) if(kata[i]!=awal[i]){ sama=0; break;}
        if(sama){
            reverse(kata,kata+(strlen(kata)));
            R(i,0,strlen(akhir)) if(kata[i]!=akhir[i]){ sama=0; break; }
        }
        if(sama and strlen(kata)>=(strlen(awal)+strlen(akhir))){
            reverse(kata,kata+strlen(kata));
            printf("%s\n", kata);
        }
      }
    }
    return 0;
}
