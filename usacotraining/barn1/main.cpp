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
TASK: barn1
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("barn1.out");
    	ifstream fin ("barn1.in");
	int M,S,C;
	fin>>M>>S>>C;
	int cow[C];
	for(int i=0;i<C;i++){
		fin>>cow[i];
	}
	sort(cow,cow+C);
	vector<int> rng;
	int cnt=0;
	for(int i=1;i<C;i++){
		if(cow[i]-cow[i-1]!=1){
			rng.push_back(cow[i]-cow[i-1]-1);
			cnt++;
		}
	}
		
	int req=cnt+1-M;
//	cout<<req<<' '<<(req<(signed int)(rng.size()+1));
	int cov=C;
	sort(rng.begin(),rng.end());
	for(int i=0;i<MIN(req,(signed int)rng.size());i++){
		cov+=rng[i];
	}
	fout<<cov<<'\n';
	//cin.tie(0);	
	return 0;
}
