#include <cstdio>
#include <cstring>

char a[101],b[101],c[101],jadi_a,jadi_b;
int main(void){
    scanf("%s%s%s", &a,&b,&c);
    int lena=strlen(a),lenb=strlen(b),lenc=strlen(c);
    int ct=0;
    for(int i=0; ct<lena and i<lenc; i++){
        if(c[i]==a[ct]) ct++;
    }
    if(ct+1==lena) jadi_a=1;
    int ct=0;
    for(int i=0; ct<lenb and i<lenc; i++){
        if(c[i]==b[ct]) ct++;
    }
    if(ct+1==lenb) jadi_b==1;
    printf("%s\n", (jadi_a and jadi_b)?"yes":"no");
}
