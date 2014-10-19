#include <cstdio>
#include <cstring>

char sa[100],si[100];
int num;
int main(){
    scanf("%s %s", sa,si);
    int lena=strlen(sa);
    int leni=strlen(si);
    for(int i=0; i<lena; i++){
        for(int j=0; j<leni; j++){
            num+=( (sa[i]-'0') * (si[j]-'0') );
        }
    }
    printf("%d\n", num);
    return 0;
}
