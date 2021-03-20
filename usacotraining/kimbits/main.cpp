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
TASK: kimbits
LANG: C++                 
*/
long long ncr[32][32];
string ans;
long long solve(long long N,long long L,long long I){
	long long ldz=0;
	for(int i=0;i<=L;i++){
		if(i>(N-1))continue;
		ldz+=ncr[N-1][i];
	}
//	cerr<<ldz<<' '<<I<<'\n';
	if(N==0){
		return 0;
	}
	if(I<=ldz){
		ans=ans+"0";
		return solve(N-1,L,I);
	}
	ans=ans+"1";
	return solve(N-1,L-1,I-ldz);
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("kimbits.out");
    	ifstream fin ("kimbits.in");
	long long N,L,I;
	fin>>N>>L>>I;
	ncr[1][0]=1;
	ncr[1][1]=1;
	for(int i=0;i<=31;i++){
		ncr[i][0]=1;
	}
	for(int i=2;i<=31;i++){
		for(int j=1;j<=i;j++){
			ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
		}
	}

	solve(N,L,I);
	while(ans.length()<N){
		ans=ans+"0";
	}
	fout<<ans<<'\n';

	//cin.tie(0);	
	return 0;
}
