#include <algorithm>
#include <cstdio>
#include <deque>
using namespace std;

deque<long> deck;
long teskes,num;
int main(){
    scanf("%ld", &teskes);
    while(teskes--){
         scanf("%ld", &num);
         deck.push_back(num);
    }
    while(deck.size()>1){
        int fpb,kpk;
        fpb=__gcd(deck[0],deck[1]);
        kpk=(deck[0]*deck[1])/fpb;
        deck.pop_front();
        deck.pop_front();
        deck.push_front(kpk);
    }
    printf("%ld\n", deck.front());
    return 0;
}
