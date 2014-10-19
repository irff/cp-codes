#include <cstdio>
#include <algorithm>
using namespace std;

int adult, children;
int main() {
    scanf("%d%d", &adult, &children);
    if( adult == 0) printf("Impossible\n");
    else if(children==0 and adult!=0) printf("%d %d\n", adult, adult);
    else {
        if(adult >=children) printf("%d ", adult);
        else {
            printf("%d ", children);
        }
        printf("%d\n", adult+children-1);
    }
}
