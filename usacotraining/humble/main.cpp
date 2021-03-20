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
TASK: humble
LANG: C++                 
*/
long long primes[102];
long long ans[100001];
int lstind[105];
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("humble.out");
    	ifstream fin ("humble.in");
	fin.tie(0);
	int K,N;
	fin>>K>>N;
	int Ns=N;
	for(int i=0;i<K;i++){
		long long cur;
		fin>>cur;
		primes[i]=cur;
	}
	ans[0]=1;
	int sz=1;
	N++;
	long long cur;
	while(N--){
		cur=INF;
		for(int i=0;i<K;i++){
			while(ans[lstind[i]]*primes[i]<=ans[sz-1] && ans[lstind[i]]*primes[i]<=cur){
				lstind[i]++;
			}
			cur=MIN(cur,ans[lstind[i]]*primes[i]);
		}
		ans[sz]=cur;
		sz++;
	}
	fout<<ans[Ns]<<'\n';
	//cin.tie(0);	
	return 0;
}
