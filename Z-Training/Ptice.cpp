#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int len,na,nb,nc;
char a[110],b[110],c[110],s[101];
int main(){
    for(int i=0; i<=100; i+=3){
        a[i]='A';
        a[i+1]='B';
        a[i+2]='C';
    }
    for(int i=0; i<=100; i+=4 ){
        b[i]=b[i+2]='B';
        b[i+1]='A';
        b[i+3]='C';
    }
    for(int i=0; i<=100; i+=6){
       c[i]=c[i+1]='C';
       c[i+2]=c[i+3]='A';
       c[i+4]=c[i+5]='B';
    }
    scanf("%d%s", &len, &s);
    for(int i=0; i<len; i++){
        if(s[i]==a[i]) na++;
        if(s[i]==b[i]) nb++;
        if(s[i]==c[i]) nc++;
    }
    int MAX=max(na,max(nb,nc));
    printf("%d\n", MAX);
    if(na==MAX) printf("Adrian\n");
    if(nb==MAX) printf("Bruno\n");
    if(nc==MAX) printf("Goran\n");
    return 0;
}
