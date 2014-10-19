#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long nkwak, nkwek,num,posisi;
vector<long> bebek;
vector<long>::iterator it=bebek.begin();
int main(){
    scanf("%ld%ld%ld", &nkwak, &nkwek, &posisi);
    nkwak+=nkwek;
    while(nkwak--){
        scanf("%ld", &num);
        bebek.push_back(num);
    }
    
    sort(bebek.begin(),bebek.end());

    printf("%ld\n", bebek[posisi-1]);
    return 0;
}
