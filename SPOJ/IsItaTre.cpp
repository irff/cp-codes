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
    int V,E;
    bool tree=1;
    scanf("%d%d", &V,&E);
    for(int i=0; i<E; i++){
        scanf("%d%d", &a,&b);
        if(sameset(a,b)) { tree=0; break; }
        join(a,b);
    }
    printf("%s\n", tree?"YES":"NO");
    scanf("\n");
    return 0;
}
