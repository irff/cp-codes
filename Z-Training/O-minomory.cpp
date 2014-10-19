#include <cstdio>
#include <map>
using namespace std;

map<int,int> m;
int N,Q,num;

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &num);
        m[num]=i;
    }
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &num);
        if(!m.count(num)) printf("0\n");
        else printf("%d\n", m[num]);
    }
    return 0;
}
