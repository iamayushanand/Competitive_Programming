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
TASK: prefix
LANG: C++                 
*/
vector<string> primitives;
string inp="";
bool dp[200000];
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("prefix.out");
    	ifstream fin ("prefix.in");
	fin.tie(0);
	string cur;
	while(fin>>cur){
		if(cur=="."){
			break;
		}
		primitives.push_back(cur);
	}
	while(fin>>cur){
		inp+=cur;	

	}
	int primsz=primitives.size();
	int len=inp.size();
	int ans=-1;
	for(int i=0;i<len;i++){
		for(int j=0;j<primsz;j++){
			int sz=primitives[j].size();
			bool flag=true;	
			if(sz>i+1)continue;
			if(i+1!=sz && !dp[i-sz])continue;
			for(int k=i;k>=0;k--){
				
				if(primitives[j][--sz]!=inp[k]){flag=false;break;}
				if(sz==0){break;}
			}
			if(sz!=0 || !flag){dp[i]=false;}else{dp[i]=true;break;}
		}
		if(dp[i]){	
			ans=i;
		}
	}
	fout<<ans+1<<'\n';
//	fout<<dp[0];
	//cin.tie(0);	
	return 0;
}
