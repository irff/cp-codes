#include <cstdio>
#include <map>
using namespace std;

int n,x,y,def;
map<int,int> m;
int main(){
    int state=0;
    scanf("%d", &state);
    
    while(state!=3){
        if(state==0){ // new competition
            m.clear();
            scanf("%d%d", &n, &def);                  
        }
        if(state==1){
            scanf("%d%d", &x,&y);
            m[x]+=y;
        }
        if(state==2){
            scanf("%d", &x);
            printf("%d\n", m[x]+def);
        }
        scanf("%d", &state);
    }

}
