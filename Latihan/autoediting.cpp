#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string fin[15],rep[15],s;
int main() {
    printf("%d", '\n');
    while(scanf("%d", &n) > 0 and n!=0) {
        scanf("\n");
        for(int i=0; i<n; i++) getline(cin,fin[i]),getline(cin,rep[i]);
        
        getline(cin, s);
        for(int i=0; i<n; i++) {
            int len=fin[i].length();
            string::size_type loc = s.find(fin[i],0);
            while(loc != string::npos) {
                s.erase(loc,len);
                s.insert(loc,rep[i]);
                loc = s.find(fin[i],0);
            }
        }
        cout << s << endl;
        
    }
    return 0;
}
