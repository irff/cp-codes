#include <cstdio>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[200][200],str[200];
int bar,kol,n;
int main(){
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) R(j,0,kol) s[i][j]=getchar(),s[i][j]=getchar();
    scanf("%d",&n);
    while(n--){
        scanf("%s", &str);
        int len=strlen(str);
        R(i,0,len){
            if(str[i]-'a'>=0) str[i]=str[i]-'a'+'A';
        }
        // horizontal
        int state=0;
        R(i,0,bar){
            R(j,0,kol){
                int cek=1,cek2=1,cek3=1,cek4=1;
                R(k,0,len){
                    if(j+k>=kol) cek=0;
                    if(str[k]!=s[i][j+k]) cek=0;
                    
                    if(j-k<0) cek2=0;
                    if(str[k]!=s[i][j-k]) cek2=0;
                    
                    if(i+k>=bar) cek3=0;
                    if(str[k]!=s[i+k][j]) cek3=0;
                
                    if(i-k<0) cek4=0;
                    if(str[k]!=s[i-k][j])cek4=0;
                
                }
                if(cek or cek2 or cek3 or cek4) { state=1; break;}
            }
            if(state) break;
        }
    if(!state){
        R(i,0,bar){
            R(j,0,kol){
                int cek=1,cek2=1,cek3=1,cek4=1;
                R(k,0,len){
                    if(i+k>=bar) cek=0;
                    if(j+k>=kol) cek=0;
                    if(str[k]!=s[i+k][j+k]) cek=0;

                    if(i-k<0) cek2=0;
                    if(j+k>=kol) cek2=0; 
                    if(str[k]!=s[i-k][j+k]) cek2=0;

                    if(i-k<0) cek3=0;
                    if(j-k<0) cek3=0;
                    if(str[k]!=s[i-k][j-k]) cek3=0;

                    if(i+k>=bar) cek4=0;
                    if(j-k<0) cek4=0;
                    if(str[k]!=s[i+k][j-k]) cek4=0;
                }
                if(cek or cek2 or cek3 or cek4) { state=1; break;}
            }
            if(state) break;
        }
    }    
        if(state) printf("Y\n");
        else printf("T\n");
    }
    return 0;
}
