#include <cstdio>
#include <list>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

list<int> kartu;
int nkartu, ngiliran;

int main() {
    scanf("%d%d", &nkartu, &ngiliran);
    R(i,0,nkartu) {
        int num; scanf("%d", &num);
        kartu.push_front(num);
    }
    R(i,0,ngiliran) {
        int num=kartu.front(); kartu.pop_front();
        R(j,0,num) {
            kartu.push_front(kartu.back());
            kartu.pop_back();
        }
        kartu.push_back(num);
    }
    printf("%d\n", kartu.front());
    return 0;
}
