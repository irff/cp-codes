#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef map<double,int> MDI;

const double INF = 99333222111.00;

MDI m;
int n, a[310000], maks = 0, ctr = 0;
double r[310000], may[310000];
int main() {
	scanf("%d", &n);
	R(i,0,n) scanf("%d", &a[i]);
	
	R(i,1,n) {
	    if(a[i-1]==0 and a[i]!=0) r[i] = INF;
		else if(a[i]==0) r[i] = 0.00;
		else r[i] = (double) a[i]/a[i-1];
		m[ r[i] ]++;
		maks = max(maks, m[ r[i] ]);
	}
	
	if(n==1) printf("BARISAN GEOMETRI\n");
	else if(n==2 and a[0]==0 and a[1]!=0) printf("MIRIP BARISAN GEOMETRI\n");
	else if(n==2) printf("BARISAN GEOMETRI\n");
	else {
		
		for(MDI::iterator it=m.begin(); it!=m.end(); it++) {
		    if(it -> second == maks) {
			    may[ctr++] = it-> first;
			}
		}
		/*
		R(i,0,ctr) printf("%.2lf\n", may[i]);
		*/
		if(m.size() == 1) { printf("BARISAN GEOMETRI\n"); return 0; }
		if(ctr > 3) { printf("BUKAN BARISAN GEOMETRI\n"); return 0; }
		bool mirip = 0;
		bool awal_hilang = 1;
		R(i,2,n-1) {
		    if(r[i] != r[i+1]) {
			    awal_hilang = 0; break;
			}
		}
		if(awal_hilang) { printf("MIRIP BARISAN GEOMETRI\n"); return 0; }
		          
		bool akhir_hilang = 1;
		R(i,1,n-2) {
		    if(r[i] != r[i+1]) {
			    akhir_hilang = 0; break;
			}
		}
		
        if(akhir_hilang) { printf("MIRIP BARISAN GEOMETRI\n"); return 0; }
		bool jadi = 1, udah = 0;
		
		R(i,0,ctr) {
			jadi = 1, udah = 0;
		    R(j,1,n-1) {
			    if(r[j] != may[i] and !udah) {
				    double rat = 0.00;
					if(a[j-1] == 0 and a[j+1] != 0) rat = INF;
					else if(a[j-1] == 0) rat = 0.00;
					else rat = (double) a[j+1] / a[j-1];
					if(rat == may[i]) {
						udah = 1;
						j++;
					} else jadi = 0;
				} else if(r[j] != may[i] and udah) {
				    jadi = 0;
				}
			}
			if(jadi) { printf("MIRIP BARISAN GEOMETRI\n"); return 0; }
		}
		printf("BUKAN BARISAN GEOMETRI\n");
	}

	return 0; 
}
