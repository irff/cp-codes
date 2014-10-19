/*
    ID: irfan1
    LANG: C++
    TASK: crypt1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, numbers[100], prima[100];
int a, b;
int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    scanf("%d", &n);
    int ctr = 0;
    for(int i=0; i<n; i++) {
        int num; scanf("%d", &num); numbers[num]=1;
        if(num==2 or num==3 or num==5 or num==7) prima[num]=1;
    }
    for(int i=100; i<=999; i++) {
        for(int j=10; j<=99; j++) {
    
            int x = i;
            bool bisa = 1;
            while(x>0 and bisa) {
                if(!numbers[x%10]) bisa = 0;
                x/=10;
            }
    
            x = j;
            while(x>0 and bisa) {
                if(!numbers[x%10]) bisa = 0;
                x/=10;
            }
    
            int step = 0;
            x = i*(j/10);
            while(x > 0 and bisa) {
                if(!numbers[x%10]) bisa = 0;
                x/=10;
                step++;
            }
            if(step!=3) bisa=0;
            
            step = 0;
            x = i*(j%10);
            while(x > 0 and bisa) {
                if(!numbers[x%10]) bisa = 0;
                x/=10;
                step++;
            }
            if(step!=3) bisa = 0;
            
            step = 0;
            x = i*j;
            while(x>0 and bisa) {
                if(!numbers[x%10]) bisa = 0;
                x/=10;
                step++;
            }
            
            if(bisa and step==4) {
                ctr++;
                /*
                printf("%d\n %d\n",i,j);
                printf("----\n");
                printf(" %d\n",i*(j%10));
                printf("%d \n", i*(j/10));
                printf("----\n");
                printf("%d\n", i*j);
                printf("\n");
                */
            }
        }
    }
    printf("%d\n", ctr);
    return 0;
}
