// assert(x) -- if x is false, terminate the program
#include <cstdio>
#include <cassert>
using namespace std;
#define R(i,n) for(int i=0;i<int(n);i++)
#define HASHSIZE 3000001
#define IS_EMPTY(key) (e[key].song == -1)
#define QUERYLEN 10

struct Entry { short song, pos; } e[HASHSIZE];
int songs[2011][1001], query[10], N,Q,S;

bool equal(int *a, int *b){
    R(i,QUERYLEN) if(a[i]!=b[i]) return 0;
    return 1;
}

int lookup(int *melody){
    unsigned int H = 0; // initial hash
    R(i,QUERYLEN) {
        H = H + (H*13) ^ melody[i];    // simple hash function --> H + H(*13) xor melody[i]
    }
    R(i,HASHSIZE){
        int key = (H + i) % HASHSIZE;         // Linear Probing
        if( IS_EMPTY(key) ) return -key;
        int *this_melody = songs[ e[key].song ] + e[key].pos;
        if( equal(melody, this_melody) ) return key;
    }
    assert(false);                     // hash table is full!
}

int main(){
    R(i,HASHSIZE) e[i].song = -1; // PRESET
    scanf("%d %d", &N, &Q);
    R(i,N){
        scanf("%d", &S);
        R(j,S) scanf("%d", &songs[i][j]);
        R(j,S-QUERYLEN+1){               // Inserting to hash table
            int key = -lookup(songs[i]+j); // expected O(1)
            assert(key >= 0);              // should have no duplicate
            e[key]= (Entry) {i,j};
        }
    }
    R(i,Q){
        R(j,QUERYLEN) scanf("%d", &query[j]);
        int key = lookup(query);         // FIND() function, O(1)
        if (key<0) puts("not found");
        else printf("%d %d\n", e[key].song+1, e[key].pos+1);
    }
    return 0;
}
