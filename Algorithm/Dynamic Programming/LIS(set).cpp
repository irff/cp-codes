#include <cstdio>
#include <set>
using namespace std;

int n,x;
set<int> lis;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        if( lis.insert(x).second ){
            set<int>::iterator it=lis.find(x); it++;
            if( it!=lis.end() ) lis.erase(it);
        }
    }
    printf("%d\n", lis.size());
    scanf("\n");
    return 0;
}
