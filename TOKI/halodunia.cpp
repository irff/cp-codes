#include <cstdio>
#include <cstring>
using namespace std;

char a[100];
int benar=0;
int main(){
    char b[11]="halo dunia";
    char c[11]="HALO DUNIA";	
    gets(a);
    for(int i=0; i<strlen(a); i++){
        if( (a[i]==b[i]) or (a[i]==c[i]))benar++;
    }
    printf("%d\n", benar);
    return 0;
}