#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string data[1001];

bool sep(string a, string b)
{
    int sa = a.size(), sb = b.size();
    int ma = (sa-1)/2, mb = (sb-1)/2, ix = 1, ka = 0, ki = 0;
    while( a[ma] == b[mb])
    {
        if( 1 & ix ) ma += ix, mb += ix; else ma -= ix, mb -= ix;
        ix++;
    }
    return a[ma] < b[mb];
}

int main()
{
    int N; cin>>N;
    for(int i=0; i<N; i++) cin>>data[i];
    sort(data, data+N, sep);
    for(int i=0; i<N; i++) cout<<data[i]<<endl;
    return 0;
}
