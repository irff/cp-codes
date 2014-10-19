#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
 
char a[200],b[200],c[200];
int main(){
    scanf("%s", &a);
    scanf("%s", &b);
    scanf("%s", &c);
    
    for(int i=0; i<strlen(a); i++) if(isupper(a[i])) a[i]=a[i]-'A'+a;
    for(int i=0; i<strlen(b); i++) if(isupper(b[i])) b[i]=b[i]-'A'+a;
    for(int i=0; i<strlen(c); i++) if(isupper(c[i])) c[i]=c[i]-'A'+a;
    
    int len=strlen(c);
    int i=0,cta=0,ctb=0,beda=0;
    for(i=0;i<len;i++){
        if(c[i]==a[cta]){
            cta++;
        }
        else if(c[i]==b[ctb]){
            ctb++;
        }
        else { beda=1; break; }
    }
    if(beda) printf("no\n");
    else printf("yes\n");
    scanf("\n");
    return 0;
}
