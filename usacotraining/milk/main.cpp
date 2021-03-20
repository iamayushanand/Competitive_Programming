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
TASK: milk
LANG: C++                 
*/

bool farComp(pair<int,int> a, pair<int,int> b){
	return (a.first<b.first);
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("milk.out");
    	ifstream fin ("milk.in");
	int N,M;
	fin>>N>>M;
	vector< pair<int,int> > far;
	for(int i=0;i<M;i++){
		pair<int,int> cur;
		fin>>cur.first>>cur.second;
		far.push_back(cur);
	}
	sort(far.begin(),far.begin()+M,farComp);
	int cost=0;
	for(int i=0;i<M;i++){
		N-=far[i].second;
		if(N<0){
			fout<<cost+((N+far[i].second)*far[i].first)<<'\n';
			return 0;
		}
		cost+=(far[i].second*far[i].first);
	}
	fout<<cost<<'\n';
	//cin.tie(0);	
	return 0;
}
