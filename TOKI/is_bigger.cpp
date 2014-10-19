#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	#include <string>
	#include <cctype>
	#include <stack>
#include <queue>
	#include <vector>
	#include <map>
	#include <sstream>
	#include <set>
	#include <math.h>
	#define N 1000000
	using namespace std;
	 
	struct elephant {
	    int weight;
	    int iq;
	    int index;
	} a [1000 + 10];
	 
	bool cmp (elephant x, elephant y)
	{
	    if ( x.iq >= y.iq )
	        return true;
	    return false;
	}
	 
	void lis (int len)
	{
    int best [1000 + 10];
	    int parent [1000 + 10];
	    //memset (best, 1, 1010 * sizeof (int));
	 
	    for ( int i = 0; i < 1010; i++ ) {
	        best [i] = 1;
	        parent [i] = -1;
	    }
	 
	    for ( int i = 1; i < len; i++ ) {
	        for ( int j = 0; j < i; j++ ) {
	            if ( a [i].weight > a [j].weight && best [i] < best [j] + 1 ) {
	                best [i] = best [j] + 1;
	                parent [i] = j;
	            }
	        }
	    }
	 
	    // output
	 
	    int max = 0;
	    int indexNum;
	 
	    for ( int i = 0; i < len; i++ ) {
	        if ( best [i] > max ) {
	            max = best [i];
	            indexNum = i;
	        }
	    }
	 
	    vector <int> finalList;
	    finalList.clear ();
	 
	    while ( parent [indexNum] != -1 ) {
	        finalList.push_back (a [indexNum].index);
	        indexNum = parent [indexNum];
	    }
	 
	    finalList.push_back (a [indexNum].index);
	    reverse (finalList.begin (), finalList.end ());
	 
	 
	    printf ("%d\n", finalList.size ());
	 
	    for ( unsigned i = 0; i < finalList.size (); i++ )
	        printf ("%d\n", finalList [i]);
	}
	 
	int main ()
	{
	    int length = 0;
	 
	    while ( scanf ("%d %d", &a [length].weight, &a [length].iq) != EOF ) {
	        a [length].index = length + 1;
	        length++;
	    }
	 
	    sort (a, a + length, cmp);
	 
	    lis (length);
	 
return 0;
}
