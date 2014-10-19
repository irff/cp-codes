#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define LLD long long

LLD aa,bb,cc;
int ct,dd;
char a[1000],b[1000],c[1000],w[1000];
bool sama;
int main(){
    scanf("%lld%lld%lld%d", &aa,&bb,&cc,&dd);
    if(dd==1) if(aa+bb==cc) sama=1;
    if(dd==2) if(aa-bb==cc) sama=1;
    if(dd==3){
    ct=0;
    while(cc>0){
        w[ct]=cc%10+'0';
        cc/=10;
        ct++;
    }
    reverse(w,w+ct);
    ct=0;
    while(aa>0){
        a[ct]=aa%10+'0';
        aa/=10;
        ct++;
    }
    int lena=ct;
    ct=0;
    while(bb>0){
        b[ct]=bb%10+'0';
        bb/=10;
        ct++;
    }
    int leni=ct;
        //reverse(a,a+lena);
        //reverse(b,b+leni);
    
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
        //printf("%s\n", c);
        if(strcmp(c,w)==0) sama=1;
    }
    
    if(dd==4) if((double)aa/bb==(double)cc) sama=1;
    printf("%d\n", sama);
    scanf("\n");
    return 0;
}
