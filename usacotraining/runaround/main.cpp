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
TASK: runround
LANG: C++                 
*/
int isrunaround(unsigned long long M){
	string s=to_string(M);
	int sz=s.size();
	bool visited[sz];
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			if(i!=j && s[i]==s[j]){return 0;}
		}
		if(s[i]=='0'){return 0;}
		visited[i]=0;
	}
	int i=0;
	do{
		visited[i]=1;
		i=i+(s[i]-'0');
		i%=sz;
	}while(!visited[i]);
	for(int j=0;j<sz;j++){
		if(visited[j]==0){
			return 0;
		}
	}
	if(i==0){
		return 1;
	}
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("runround.out");
    	ifstream fin ("runround.in");
	unsigned long long M;
	fin>>M;
	M++;
	while(!isrunaround(M)){
		M++;
	}
	fout<<M<<'\n';
	//cin.tie(0);	
	return 0;
}
