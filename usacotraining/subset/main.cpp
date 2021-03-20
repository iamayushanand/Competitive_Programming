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
TASK: subset
LANG: C++                 
*/
int dp[40][1600];//dp[x][y]: x is index from left and y is the sum
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("subset.out");
    	ifstream fin ("subset.in");
	int N;
	fin>>N;
	if((N*(N+1))%4!=0){
		fout<<0<<'\n';
		return 0;
	}
	int sum=N*(N+1)/4;
	dp[1][1]=1;
	for(int s=1;s<=sum;s++){
		for(int i=2;i<=N;i++){
			dp[i][s]=dp[i-1][s];
			if(s-i>0){
				dp[i][s]+=dp[i-1][s-i];
			}
		}
	}
	fout<<dp[N][sum]<<'\n';
	//cin.tie(0);		
	return 0;
}
