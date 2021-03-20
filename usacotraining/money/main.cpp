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
TASK: money
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("money.out");
    	ifstream fin ("money.in");
	int V,N;
	fin>>V>>N;
	long long cns[V];
	long long ans[N+1][V+1];//ans[n][k]=ans for n value using first k coins
	for(int i=0;i<V;i++){
		fin>>cns[i];
	}
	//ans[n][k]=ans[n][k-1]+ans[n-cns[k]][k]
	//ans[0][k]=1;
	//ans[k][0]=0
	//ans[-k][j]=0
	fill_n(ans[0],V+1,1);
	for(int i=0;i<N+1;i++){
		ans[i][0]=0;
	}
	for(int n=1;n<N+1;n++){
		for(int k=1;k<V+1;k++){
			ans[n][k]=ans[n][k-1];
			if(n-cns[k-1]>=0){
				ans[n][k]+=ans[n-cns[k-1]][k];
			}
		}
	}
	fout<<ans[N][V]<<'\n';
	//cin.tie(0);	
	return 0;
}
