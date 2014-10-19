#include <cstdio>
#include <algorithm>
using namespace std;

int cc[2000],coin[10];
int main(){
    for(int i=0; i<10; i++) scanf("%d", &coin[i]);
    cc[0]=1;
    for(int i=0; i<10; i++)
     for(int j=2000; j>=coin[i]; j--){
         if(cc[j-coin[i]]==1) cc[j]=1;
     }
    int a=99999,b=-99999;
    for(int i=101; i<2000; i++)
        if(cc[i]) { a=i; break; }
    for(int i=99; i>=0; i--){
        if(cc[i]) { b=i; break; }
    }
    
    if(cc[100]) printf("%d\n", 100);
    else 
    if( (a-100) > (100-b) ) printf("%d\n", b);
    else printf("%d\n", a);
    scanf("\n");
    return 0;
}
