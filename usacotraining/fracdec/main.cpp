#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007

/*
ID: iamayus1
TASK: fracdec
LANG: C++                 
*/
ofstream out("fracdec.out");

int colcount=0;

int numBeforeRepeat(int n, int d) {
    int c2=0, c5=0;
    if (n == 0) return 1;
    while (d%2==0) { d/=2; c2++; }
    while (d%5==0) { d/=5; c5++; }
    while (n%2==0) { n/=2; c2--; } /* can go negative */
    while (n%5==0) { n/=5; c5--; } /* can go negative */
    if (c2>c5)
        if (c2>0) return c2;
        else return 0;
    else
        if (c5>0) return c5;
        else return 0;
}

void print (char c) {
    if (colcount==76) {
        out<<endl;
        colcount=0;
    }
    out<<c;
    colcount++;
}

void print (int n) {
    if (n>=10) print (n/10);
    print ((char)('0'+(n%10)));
}

int main() {
    int n, d;
    ifstream in("fracdec.in");
    in>>n>>d;
    in.close();

    print (n/d);
    print ('.');
    n=n%d;
    int m=numBeforeRepeat(n,d);
    for(int i=0;i<m;i++) {
        n*=10;
	print (n/d);
        n%=d;
    }
    int r=n;
    if(r!=0) {
	print ('(');
        do {
            n*=10;
	    print (n/d);
            n%=d;
        } while (n!=r);
	print (')');
    }
    out<<endl;
    out.close();
    exit (0);
}
