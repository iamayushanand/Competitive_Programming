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
TASK: nocows
LANG: C++                 
*/
int dp[201][101];
int net[201][101];
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("nocows.out");
    	ifstream fin ("nocows.in");
	int N,K;
	fin>>N>>K;
	dp[1][1]=1;

	for(int n=1;n<N+1;n+=2){
		for(int k=1;k<K+1;k++){
			if(n==1 && k==1)continue;
			//cerr<<"n:"<<n<<"k:"<<k<<'\n';
			for(int j=1;j<n;j++){
				dp[n][k]+=dp[n-j-1][k-1]*net[j][k-1];	
				dp[n][k]%=9901;
				dp[n][k]+=dp[j][k-1]*net[n-j-1][k-1];
				dp[n][k]%=9901;
				dp[n][k]+=dp[n-j-1][k-1]*dp[j][k-1];
				dp[n][k]%=9901;
			}
			dp[n][k]%=9901;
			net[n][k]=dp[n][k-1]+net[n][k-1];
			net[n][k]%=9901;
			//cout<<dp[n][k]<<'\n';
			//cerr<<dp[n][k]<<'\n';
		}
	}
	fout<<dp[N][K]<<'\n';
	//cin.tie(0);	
	return 0;
}
