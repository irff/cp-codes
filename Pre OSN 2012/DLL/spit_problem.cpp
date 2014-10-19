#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int n, x[200],d[200];
map<int,bool> bar;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &x[i], &d[i]);
    }
    bool ada = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(x[i]+d[i]==x[j] and x[j]+d[j]==x[i]) ada=1;
        }
    }
    if(ada) printf("YES\n");
    else printf("NO\n");
    return 0;
}
