#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int nseat,nparty,sum,leftover;
int a[1000],seat[1000];
pair<double,int> fract[1000];
int main() {
    printf("Number of seats: "); scanf("%d", &nseat);
    printf("Number of parties: "); scanf("%d", &nparty);
    for(int i=0; i<nparty; i++) {
        printf("Votes for party #%d: ", i+1); scanf("%d", &a[i]);
        sum+=a[i];
    }
    for(int i=0; i<nparty; i++) {
        double x=(double)a[i]/sum*nseat;
        seat[i]=(int)x;
        leftover+=seat[i];
        fract[i]=pair<double,int>(x-seat[i],i);
    }
    sort(fract,fract+nparty,greater< pair<double,int> >());
    leftover=nseat-leftover;
    int id=0;
    while(leftover>0) {
        seat[fract[id].second]++;
        id++; leftover--;
    }
    for(int i=0; i<nparty; i++) {
        printf("Seats for party #%d: %d\n", i+1,seat[i]);
    }
    return 0;
}
