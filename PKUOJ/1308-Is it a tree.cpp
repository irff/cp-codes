#include <cstdio>


int a,b;
int pset[1000000];

int findset(int i){ return (pset[i]==i)?i:(pset[i]=findset(pset[i])); }
void join(int i, int j){ pset[findset(i)]=findset(j); }
bool sameset(int i, int j){ return findset(i)==findset(j); }
int main(){
    int kasus=1;
    bool sikel=0;
    for(int i=0; i<=1000000; i++){
        pset[i]=i;
    }
    scanf("%d%d", &a,&b);
    while(a!=-1 and b!=-1){
        if(a==0 and b==0){
            if(!sikel){
                printf("Case %d is a tree.\n", kasus);
            }
            else printf("Case %d is not a tree.\n", kasus);
            sikel=0;
            kasus++;
            for(int i=0; i<=1000000; i++){
                pset[i]=i;
            }
        }
        else {
            if(sameset(a,b)) sikel=1;
            join(a,b);
        }
        scanf("%d%d", &a,&b);
    }
    return 0;
}
