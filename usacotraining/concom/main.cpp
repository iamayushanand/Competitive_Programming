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
TASK: concom
LANG: C++                 
*/
int shr[101][101];
int N;
bool v[101];
int con[101];
void dfs(int st){
	v[st]=1;
	for(int i=1;i<101;i++){
		con[i]+=shr[st][i];
	}
	for(int i=1;i<101;i++){
		if(con[i]>50 && i!=st && !v[i]){
			dfs(i);
		}
	}
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("concom.out");
    	ifstream fin ("concom.in");

	//cin.tie(0);	
	fin>>N;
	for(int i=0;i<N;i++){
		int a,b;
		fin>>a>>b;
		fin>>shr[a][b];
	}	
	for(int i=1;i<101;i++){
		for(int i=1;i<=100;i++){
			v[i]=0;
			con[i]=0;
		}
		dfs(i);
		for(int j=1;j<101;j++){
			if(con[j]>50 && i!=j){
				fout<<i<<' '<<j<<'\n';
			}
		}
	}
	return 0;
}
