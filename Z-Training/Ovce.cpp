#include <cstring>
#include <cstdio>
using namespace std;

char s[100];
int a[2];
int main(){
    scanf("%s", &s);
    int len=strlen(s);
    for(int i=0; i<strlen(s); i++){
        if(s[i]!='#'){
            if(s[i]=='V') a[1]++;
            else a[0]++;
        }
        else {
            if(a[0]>a[1]){
                while(a[0]--) printf("O");
            }
            else while(a[1]--) printf("V");
            a[0]=0,a[1]=0;
            printf("#");
        }
    }
    scanf("\n");
    return 0;
}
