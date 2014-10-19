#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

char a[102],b[102],c[10000],op;
int main(){
    scanf("%s", &a);
    scanf("\n%s\n", &op);
    scanf("%s\n", &b);
    int lena=strlen(a); int leni=strlen(b);
    if(op=='+'){
        // performs ADDITION
        int leno=max(lena,leni)+1;
        reverse(a,a+lena); reverse(b,b+leni);
        for(int i=0; i<lena; i++) if(isdigit(a[i])) a[i]-='0';
        for(int i=0; i<leni; i++) if(isdigit(b[i])) b[i]-='0';
        int sisa=0;
        for(int i=0; i<leno; i++){
            c[i]=(a[i]+b[i]+sisa)%10;
            sisa=(a[i]+b[i]+sisa)/10;
        }
        while(c[leno-1]==0) leno--;
        for(int i=0; i<leno; i++) c[i]+='0';
        reverse(c,c+leno);
        printf("%s\n", c);
    } else{
        // performs MULTIPLICATION
        reverse(a,a+lena);
        reverse(b,b+leni);
        int leno=lena+leni;
        for(int i=0; i<leno; i++) c[i]='0';
        c[leno]='0';
        int hold=0,res=0,r=-1;
        for(int s=0;s<leni;s++){
            int f=0;
            for(f=0;f<lena;f++){
               res=(a[f]-'0')*(b[s]-'0') + hold+(c[f+s]-'0');
               c[f+s]=res%10+'0';
               hold=res/10;
               if(f+s>r) r=f+s;
            }
            while(hold!=0){
               res=hold+c[f+s]-'0';
               hold=res/10;
               c[f+s]=res%10+'0';
               if(r<f+s) r=f+s;
               f++;
            }
        }
        for(;r>0 && c[r]=='0';r--);
            c[r+1]='\0';
        reverse(c,c+strlen(c));
        printf("%s\n", c);
    }
    
    scanf("\n");
    return 0;
}
