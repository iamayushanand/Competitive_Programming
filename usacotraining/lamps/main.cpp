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
TASK: lamps
LANG: C++                 
*/
vector<int> open;
vector<int> closed;
vector< bitset<100> > ans;
int N,C;
bitset<4> ops;
bitset<100> finalstate;//0 for closed 1 for open
bool compare(bitset<100> a,bitset<100> b){
	for(int i=0;i<N;i++){
		//cout<<a[i]<<' '<<b[i]<<' '<<(a[i]>b[i])<<'\n';
		if(a[i]>b[i]){
			return 0;
		}else if(a[i]<b[i]){
			return 1;
		}
	}
	return 1;
}
bool check(){
	int sz=open.size();
	for(int i=0;i<sz;i++){
//		fout<<open[i]<<'\n';
		if(!finalstate[open[i]]){
			return 0;
		}
	}
//	fout<<ops.to_string()<<'\n';
	sz=closed.size();
	for(int i=0;i<sz;i++){
//		fout<<"#"<<closed[i]<<' '<<finalstate[closed[i]]<<'\n';
		if(finalstate[closed[i]]){
			return 0;
		}
	}
	ans.push_back(finalstate);
//	finalstate.reset();
	return 1;
	
}
bool solve(){
	finalstate.set();
	if(C<ops.count() || (C-ops.count())%2!=0){return 0;}
//	cout<<ops.to_string()<<'\n';
	if(ops[0]){
		finalstate.flip();
	}
	if(ops[1]){
		for(int i=0;i<N;i+=2){
			finalstate.flip(i);
		}
	}
//	fout<<ops[2]<<' '<<ops.count()<<'\n';
	if(ops[2]){
		for(int i=1;i<N;i+=2){
			finalstate.flip(i);
		}
		
	}
	if(ops[3]){
		for(int i=0;i<N;i+=3){
			finalstate.flip(i);
		}
	}
//	cout<<finalstate.to_string()<<'\n';
	return check();
}
int generate(int start){
	if(start==3){
		ops.set(start);
		solve();
		ops.reset(start);
		solve();
		return 0;
	}
	ops.set(start);
	generate(start+1);
	ops.reset(start);
	generate(start+1);
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("lamps.out");
    	ifstream fin ("lamps.in");
//	int N;
	fin>>N>>C;
	int cur;
	finalstate.flip();
	while(fin>>cur){
		if(cur==-1)break;
		open.push_back(cur-1);
	}
	cur=0;
	while(fin>>cur){
		if(cur==-1)break;
		closed.push_back(cur-1);
	}
	generate(0);
	
	sort(ans.begin(),ans.end(),compare);
	int sz=ans.size();
	if(sz==0){
		fout<<"IMPOSSIBLE"<<'\n';
		return 0;
	}
	for(int i=0;i<sz;i++){
		for(int j=0;j<N;j++){
			fout<<ans[i][j];
		}
		fout<<'\n';
	}
	//cin.tie(0);	
	return 0;
}
