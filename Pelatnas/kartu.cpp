#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int nkartu;
list<int> kartu;
int main() {
    scanf("%d", &nkartu);
    for(int i=1; i<=nkartu; i++) kartu.push_back(i);
    
    while(kartu.size()!=1) {
        printf("%d", kartu.front());
        kartu.pop_front();
        kartu.push_back(kartu.front());
        kartu.pop_front();
        if(kartu.size()!=1) printf(" ");
    }
    printf("\n%d\n", kartu.front());
    return 0;
}
