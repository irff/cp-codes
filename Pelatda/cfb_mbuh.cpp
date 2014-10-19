#pragma comment(linker, "/STACK:256000000")

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
//#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
const int M = INF;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef double D;
typedef vector<int> vi;

int pp[105];
int color[105];

int ans = 0;

int nn;

vector< vi> g;
void dfs(int v, int p)
{
	color[v] = 1;
	for (int i = 0 ; i < g[v].size() ; i++)
	{
		
		int to = g[v][i];
		if ( to == p ) continue;
		if ( color[to] == 0 )
		{
			pp[to] = v;		
			dfs(to, v);
		} else if ( color[to] == 1 )
		{
			int len = 1;
			int te = v;
			while( te != to )
			{
				te = pp[te];
				len++;
			}

			ans += len % 2;	
			nn -= len%2;
			
		}
	}
	color[v] = 2;
}


//#define ONLINE_JUDGE



int main()
{
    double TIME_START = clock();	
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUTPUT.TXT","w",stdout);
#endif

	int n,m,a,b;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	nn = n;

	for (int i = 0 ; i < n ; i++)
		if ( color[i] == 0) dfs(i,-1);

	cout<<ans+ nn%2;

				

    eprintf("\n\n%.15lf\n\n",(double)(clock() - TIME_START)/CLOCKS_PER_SEC);
    return 0;
} 