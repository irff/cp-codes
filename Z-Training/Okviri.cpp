#include <cstring>
#include <cstdio>
using namespace std;

char a[5][500],s[100];
int main(){
    scanf("%s", &s);
    int len=strlen(s);
    for(int i=0; i<5; i++)
        for(int j=0; j<5+(4*(len-1)); j++)
           a[i][j]='.';
    for(int i=0; i<len; i++){
        a[0][4+(i-1)*2+(i*2)]=a[4][4+(i-1)*2+(i*2)]=((i+1)%3==0)?'*':'#';
        a[1][4+(2*(2*i-1))-1]=a[1][4+(2*(2*i))-1]=((i+1)%3==0)?'*':'#';
        a[2][3+(4*i)-1]=s[i];
        a[2][4+(i-1)*4]=(i!=0 and ((i+1)%3==0 or (i%3==0)))?'*':'#';
        a[3][4+(2*(2*i-1))-1]=a[3][4+(2*(2*i))-1]=((i+1)%3==0)?'*':'#';
        
    }
    if(len%3==0) a[2][4+(len-1)*4]='*'; else a[2][4+(len-1)*4]='#';
    for(int i=0; i<5; i++)
        printf("%s\n", a[i]);
    scanf("\n");
    return 0;
}
