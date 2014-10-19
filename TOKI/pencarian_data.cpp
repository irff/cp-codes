#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    int ukuran, urut;
    string nama, tipe;
} data;

typedef vector<data> VD;

VD v[10];
int n, q;

bool cp1(data a, data b) {
     if(a.nama == b.nama)
         return a.urut < b.urut;
     return a.nama < b.nama;
}

bool cp2(data a, data b) {
    if(a.tipe == b.tipe)
        return a.urut < b.urut;
    return a.tipe < b.tipe; // ascending
}

bool cp3(data a, data b) {
    if(a.ukuran == b.ukuran)
        return a.urut < b.urut;
    return a.ukuran < b.ukuran;
}

bool cp4(data a, data b) {
    if(a.tipe == b.tipe) {
        if(a.ukuran == b.ukuran)
            return a.urut < b.urut;
        return a.ukuran < b.ukuran;
    }
    return a.tipe < b.tipe;
}

bool cp5(data a, data b) {
    if(a.nama == b.nama) {
        if(a.ukuran == b.ukuran)
            return a.urut < b.urut;
        return a.ukuran < b.ukuran;
    }
    return a.nama < b.nama;
}

bool cp6(data a, data b) {
    if(a.nama == b.nama) {
        if(a.tipe == b.tipe)
            return a.urut < b.urut;
        return a.tipe < b.tipe;
    }
    return a.nama < b.nama;
}

int main() {
    scanf("%d%d", &n, &q);
    R(i,0,n) {
        data x;
        cin >> x.nama >> x.tipe >> x.ukuran;
        x.urut = i+1;
        v[0].push_back(x);
    }
    sort(v[0].begin(), v[0].end(), cp1);
    v[1] = v[0];
    
    sort(v[0].begin(), v[0].end(), cp2);
    v[2] = v[0];
    
    sort(v[0].begin(), v[0].end(), cp3);
    v[3] = v[0];
    
    sort(v[0].begin(), v[0].end(), cp4);
    v[4] = v[0];
    
    sort(v[0].begin(), v[0].end(), cp5);
    v[5] = v[0];
    
    sort(v[0].begin(), v[0].end(), cp6);
    v[6] = v[0];
    
    R(i,0,q) {
        int x, y;
        scanf("%d%d", &x, &y);
        //printf("%d %d\n", v[x][y-1].ukuran, v[x][y-1].urut);
        R(i,0,n) printf("%s %s %d %d\n", v[x][i].nama.c_str(), v[x][i].tipe.c_str(), v[x][i].ukuran, v[x][i].urut);
    }
    return 0;
}
