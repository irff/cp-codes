#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

vector<int> v;

int n, perm[1000], com[1000];
int main() {
    R(i,1,20+1) {
        R(j,1,3+1) {
            v.push_back(i*j);
        }
    }
    v.push_back(50);
    v.push_back(0);
    
    sort(v.begin(), v.end());
    //R(i,0,len) printf("%d\n", v[i]);
    
    //printf("%d\n", v.size());
    vector<int>::iterator it = unique(v.begin(), v.end());
    int len = it-v.begin();
    
    //R(i,0,len) printf("%d\n", v[i]);
    //printf("%d\n", len);
    R(i,0,len)
        R(j,0,len)
            R(k,0,len)
                perm[v[i]+v[j]+v[k]]++;
    
    R(i,0,len)
        R(j,i,len)
            R(k,j,len)
                com[v[i]+v[j]+v[k]]++;
    
    while( scanf("%d", &n) > 0) {
        if(n<=0) { printf("END OF OUTPUT\n"); break; }
        if(perm[n]==0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, com[n]);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm[n]);
        }
        R(i,0,70) printf("*");
        printf("\n");
    }
    return 0;
}
