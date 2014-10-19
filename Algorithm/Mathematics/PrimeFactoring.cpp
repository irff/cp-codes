#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;

VI faktorprima,primes;
int n,num;
bitset<12000> bs;
void sieve(){
    bs.set();
    bs[0]=0; bs[1]=0; bs[2]=1;
    for(int i=2; i*i<=10000; i+=1){
        for(int j=i*i; j<=10000; j+=i){
            bs[j]=0;
        }
    }
    for(int i=0; i<=10000; i++) if(bs[i]) primes.push_back(i);
}

VI primefactors( int n){
    VI factors;
    int idx=0, pf = primes[idx];
    
    while( n != 1 and pf*pf <=n ){
        while ( n % pf == 0 ) { n/=pf; factors.push_back(pf); }
        pf = primes[++idx];
    }
    
    if(n!=1) factors.push_back(n);
    return factors;
}

int main(){
    sieve();
    //for(VI::iterator it=primes.begin(); it!=primes.end(); it++) printf("%d ", *it);
    scanf("%d", &n);
    while( n-- ){
        scanf("%d", &num);
        for(int i = 1; i <= num; i++) 
            if(num % i == 0) printf("%d ", i);
        
        //faktorprima=primefactors(num);
        
        //for(VI::iterator it=faktorprima.begin(); it!=faktorprima.end(); it++) printf("%d ", *it);
        //faktorprima.clear();
        //puts("");
    }

    return 0;
}
