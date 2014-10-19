#include <cstdio>
using namespace std;

int n,num;
bool m[100111];
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num);
        if(!m[num]) {
            printf("%d\n", num);
            m[num]=1;
        }
    }
    return 0;
}
