#include <cstdio>
#include <algorithm>
using namespace std;

int V, E;
int a, b;
int pset[10000];

int findset(int i) { return (pset[i]==i)?i:(pset[i]=findset(pset[i])); }
void join(int i, int j) { pset[findset(i)]=findset(j); }
bool sameset(int i, int j) { return findset(i)==findset(j);}
int main() {
    scanf("%d%d", &V, &E);
    for(int i=0; i<=E; i++) pset[i] = i;
    for(int i=0; i<E; i++) {
        scanf("%d%d", &a,&b);
        join(a,b);
    }
    for(int i=0; i<=V; i++) {
        printf("%d %d\n", i, pset[i]);
    }
}
