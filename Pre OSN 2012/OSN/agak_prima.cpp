#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int teskes, num;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &num);
        int x=2,fak=0;
        for(int i=1; i*i<=num; i++) {
            if(num%i==0) {
                fak++;
                if(i*i!=num) {
                    fak++;
                }
            }
        }
        printf("%s\n", (fak<=4?"YA":"TIDAK"));
    }
    return 0;
}
