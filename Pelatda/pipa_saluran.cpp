#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;

int n, q;
int p[50200];
bool closed[50200];
int udah[50200];
VI tree[50200];

int find_parent(int i) {
    return p[i]==i?i:p[i]=find_parent(p[i]);
}

VI traverse(int i) {
    VI veka, veki;
    veka.push_back(i);
    if(p[i]==i) { return veka; }
    veki = traverse(p[i]);
    veka.insert(veka.end(), veki.begin(), veki.end());
    return veka;
}

int main() {
    scanf("%d", &n);
    n++;
    R(i,0,n) p[i]=i;
    R(i,1,n) {
        int v;
        scanf("%d", &v);
        closed[v]=1;
        int pa = find_parent(i), pi = find_parent(v);
        p[pa] = p[pi];
    }
    R(i,1,n) {
        if(!closed[i]) {
            tree[i] = traverse(p[i]);
            //printf("%d - ", i);
            //printf("%d\n", tree[i].size());
            //R(j,0,tree[i].size()) printf("%d ", tree[i][j]);
            //printf("\n");
        }
    }
    scanf("%d", &q);
    R(i,0,q) {
        int va, vi;
        scanf("%d%d", &va, &vi);
        
        R(j,0,n) udah[j] = -1;
        int lena = tree[va].size();
        R(j,0,lena-1) udah[ tree[va][j] ] = j;
        int leni = tree[vi].size();
        int ans = -1;
        R(j,0,leni-1) {
            if(udah[ tree[vi][j] ] != -1) {
                ans = udah[ tree[vi][j]]-j;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
