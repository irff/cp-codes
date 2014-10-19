#include <cstdio>
#include <cstring>
using namespace std;

bool ca[1000];
char a[1000];
char b[1000];
int p,panjang;
int main(){
    
    scanf("%s%s", &a,&b);
    for(int i=0; i<strlen(b); i++){
        for(int j=0; j<strlen(a); j++){
            if(!ca[j] and (b[i]==a[j])){
                ca[j]=1;
                p++;
                break;
            }
        }
    }
    printf("%d\n",strlen(b)-p);
    return 0;
}
