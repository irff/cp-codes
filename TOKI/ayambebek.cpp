#include <ctime>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)

struct tpoint { double x; double y;  };
struct tline  { int a; int b; int c; };

const int maxn = 2005;

int    teskesler,n, m, p;
tline  line[maxn];
double r = 1e6;

bool intersect(tline one, tline two, tpoint &ans) {
	if ( one.a * two.b == one.b * two.a ) return false;
	int one_b = one.b, two_b = two.b;
	one.a *= two_b, one.b *= two_b, one.c *= two_b;
	two.a *= one_b, two.b *= one_b, two.c *= one_b;
	ans.x = (double)(one.c - two.c) / (one.a - two.a);
	ans.y = (double)(one.c - (ans.x * one.a)) / one.b;
	return true;
}

bool greater(tline &one, tline &two) {
	return one.a * two.b > one.b * two.a;
}

int main()
{
    scanf("%d", &teskesler);
    while(teskesler--){
        r=1e6;
        scanf( "%d %d %d", &n, &m, &p );
    	for ( int i = 0; i < p; i++ ) {
    		scanf( "%d %d %d", &line[i].a, &line[i].b, &line[i].c );
    		if ( line[i].b == 0 ) {
    			r = min(r, (double)line[i].c/line[i].a);
    			i--, p--;
    		}
    	}
    	
        vector <tpoint> pos;
    
    	tpoint cut_y = {0, 1E6}, cut_x = {r, 0}, cut_r = {r, 1E6};
    	REP(i,p) cut_y.y = min(cut_y.y, (double)line[i].c/line[i].b);
    	REP(i,p) cut_x.x = min(cut_x.x, (double)line[i].c/line[i].a);
    	REP(i,p) cut_r.y = min(cut_r.y, ((double)line[i].c - r * line[i].a) / line[i].b);
    	pos.push_back(cut_x);
    	pos.push_back(cut_y);
    	if ( cut_r.y > 0 ) pos.push_back(cut_r);
    	
    	tpoint cut;
    	REP(i,p) REP(j,p) if ( intersect(line[i],line[j],cut) )
    		pos.push_back(cut);
    
    	double ans = 0.0;
    	REP(i,pos.size()) {
    		if ( pos[i].x < 0 ) continue;
    		if ( pos[i].y < 0 ) continue;
    		if ( pos[i].x > r ) continue;
    		bool valid = true;
    		REP(j,p) if ( line[j].a*pos[i].x + line[j].b*pos[i].y > line[j].c+1E-9 ) { valid = false; break; }
    		if ( valid ) ans = max(ans, n*pos[i].x + m*pos[i].y);
    	}
    
    	cout << setprecision(3) << fixed << ans << endl;
    }
    return 0;
}
