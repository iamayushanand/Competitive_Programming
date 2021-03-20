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
TASK: test
LANG: C++                 
*/

int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);	
	ofstream fout ("test.out");
    	ifstream fin ("test.in");
	int a, b;
	fin >> a >> b;
	fout << a+b << endl;
	return 0;
}
