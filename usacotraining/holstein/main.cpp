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
TASK: holstein
LANG: C++                
*/
bool flag[16];
int opts[16][26];
int req[26];
int V,G;
vector< vector<int> > ans;
bool solved(){
	for(int i=0;i<V;i++){
		int available=0;
		for(int j=0;j<G;j++){
			if(flag[j]){
				available+=opts[j][i];
			}
		}
		if(available<req[i]){
			return 0;
		}
	}
	return 1;
}
int check(){

	if(solved()){
		vector<int> localans;
		for(int i=0;i<G;i++){
			if(flag[i]){
				localans.push_back(i);
			}
		}
		ans.push_back(localans);
	}
	return 0;	
}

int solve(int start){
	if(start==G-1){
		flag[start]=1;
		check();
		flag[start]=0;
		check();
//		clr();
		return 0;
	}
	
	if(!flag[start]){
		flag[start]=1;
		solve(start+1);
		flag[start]=0;
		solve(start+1);
	}
	
	
	
	return 0;
}
int compto(vector<int> a,vector<int> b){
	if(a.size()>b.size()){
		return 0;	
	}else if(a.size()<b.size()){
		return 1;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("holstein.out");
    	ifstream fin ("holstein.in");
	fin>>V;
	for(int i=0;i<V;i++){
		fin>>req[i];
	}
	fin>>G;
	for(int i=0;i<G;i++){
		for(int j=0;j<V;j++){
			fin>>opts[i][j];
		}
	}
	solve(0);
	sort(ans.begin(),ans.end(),compto);
	int sz=ans[0].size();
	fout<<sz<<' ';
	for(int i=0;i<sz;i++){
		if(i==sz-1){
			fout<<ans[0][i]+1<<'\n';
		}else{
			fout<<ans[0][i]+1<<' ';
		}
	}
	
	//assert(false);
	//cin.tie(0);	
	return 0;
}
