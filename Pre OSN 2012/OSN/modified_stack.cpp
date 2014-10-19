#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int n,x,y,idx,all;
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
            printf("%d\n",all);
        } else
        if(strcmp(s,"del")==0){
            scanf("%d", &x);
            all-=x;
            if(all<0) all=0;
            printf("%d\n", a[idx-1]);
            while(x>0 and idx > 0){
                b[idx-1]-=x;
                if(b[idx-1]<=0){
                    idx--;
                    x=0-b[idx];
                } else x=0;
            }
            //for(int i=0; i<idx; i++) printf("%d ", a[i]);
            //printf("\n");
             
        } else
        if(strcmp(s,"adx")==0){
            scanf("%d", &x);
            for(int i=0; i<idx; i++) a[i]+=x;
        } else {
            scanf("%d", &x);
            for(int i=0; i<idx; i++) a[i]-=x;
        }
    }
 
    return 0;
}
