#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int n, num;
map<int, bool> m;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        if(!m[num]) printf("%d\n", num);
        m[num] = 1;
    }
    return 0;
}
