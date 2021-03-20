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
TASK: zerosum
LANG: C++                 
*/
int N;
int ans;
char ops[14];
ofstream fout ("zerosum.out");
void solve(){
	stack<int> sstack;
	sstack.push(1);
	int sign=1;
	int sum=0;
	for(int i=1;i<N;i++){
		if(ops[i]=='+'){
			sign=1;
		}
		if(ops[i]=='-'){
			sign=-1;
		}
		if(ops[i]==' '){
			int prev=sstack.top();
			sstack.pop();
			sstack.push(prev*10+(sign*(i+1)));
		}else{
			sstack.push(sign*(i+1));
		}
	}
	int sz=sstack.size();
	for(int i=0;i<sz;i++){
		sum+=sstack.top();
		sstack.pop();
	}
	if(!sum){
		for(int i=1;i<N;i++){
			fout<<i<<ops[i];
		}
		fout<<N;
		fout<<'\n';
	}

		
}

		
void dfs(int d){
	if(d==0){
		solve();
		return;
	}
	ops[N-d]=' ';
	dfs(d-1);
	ops[N-d]='+';
	dfs(d-1);
	ops[N-d]='-';
	dfs(d-1);
}
int main(){
	
	ios::sync_with_stdio(false);
	ifstream fin ("zerosum.in");
	fin>>N;

	dfs(N-1);	
	//cin.tie(0);	
	return 0;
}
