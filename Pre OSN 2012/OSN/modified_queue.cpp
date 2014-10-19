#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int n,x,y,idx,idy,all;
char s[100];
int a[10000],b[10000];
 
int main(){
    idx=0;
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        if(strcmp(s,"add")==0){
            scanf("%d%d", &x,&y);
            a[idx]=x; b[idx]=y;
            idx++; all+=y;
            printf("%d\n", all);
        } else
        if(strcmp(s,"del")==0){
            scanf("%d", &x);
            printf("%d\n", a[idy]);
            all-=x;
            while(x>0 and idx!=idy){
                b[idy]-=x;
                if(b[idy]<=0){
                    idy++;
                    x=0-b[idy-1];
                } else x=0;
            }
            //printf("idy:%d idx:%d\n", idy,idx);
            //for(int i=0; i<idx; i++) printf("%d ", a[i]);
            //printf("\n");
             
        } else {
            reverse(a+idy,a+idx);
            reverse(b+idy,b+idx);
            /*for(int i=idy; i<(idx-idy)/2; i++){
                int tmp=a[i];
                a[i]=a[idx-i+idy-1];
                a[idx-i+idy-1]=tmp;
                printf("x");
            }*/
            //for(int i=idy; i<idx; i++) printf("%d ", a[i]);
            //puts("");
        }
    }
 
    return 0;
}
