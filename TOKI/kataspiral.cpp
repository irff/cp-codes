#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

char m[100][100],s[500];
short a,b,bar,kol,arah,x,y;
bool temua,temub,temuc,temud;
int main(){
    
    gets(s);
    bar=(short)floor((double)sqrt(strlen(s)));
    kol=(short)ceil((double)sqrt(strlen(s)));
    a=bar/2,b=kol/2;
    m[a][b]=(s[0]==' ')?'_':s[0],arah=4;
    for(int i=1; i<strlen(s); i++){
        if(s[i]==' ') s[i]='_';
        if(arah==1){
            if(m[a+1][b]=='\0'){
                m[++a][b]=s[i];
                arah=2;
            }
            else{
                m[a][++b]=s[i];
            }
        }
        else if(arah==2){
            if(m[a][b-1]=='\0'){
                m[a][--b]=s[i];
                arah=3;
            }
            else{
                m[++a][b]=s[i];
            }
        }
        else if(arah==3){
            if(m[a-1][b]=='\0'){
                m[--a][b]=s[i];
                arah=4;
            }
            else {
                m[a][--b]=s[i];
            }
        }
        else if(arah==4){
            if(m[a][b+1]=='\0'){
                m[a][++b]=s[i];
                arah=1;
            }
            else{
                m[--a][b]=s[i];
            }
        }
    }
    for(int i=0; i<=kol; i++) if(m[0][i]!='\0') temua=1;
    for(int i=0; i<=bar; i++) if(m[i][0]!='\0') temub=1;
    for(int i=0; i<=kol; i++) if(m[bar][i]!='\0') temuc=1;
    for(int i=0; i<=bar; i++) if(m[i][kol]!='\0') temud=1;
    if(!temua) x++;
    if(!temub) y++;
    if(!temuc) bar--;
    if(!temud) kol--;
    for(int i=x; i<=bar; i++){
        for(int j=y; j<=kol; j++) printf("%c", (m[i][j]=='\0')?'_':m[i][j]);
        puts("");
    }
    return 0;
}
