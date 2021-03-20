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
TASK: skidesign
LANG: C++                 
*/
int N;
int fina[1000];
int store[1000];
int cost(int min,int max){
	for(int i=0;i<N;i++){
		if(fina[i]<=min){
			fina[i]=min;
		}
	}
	for(int i=0;i<N;i++){
		if(fina[i]>=max){
			fina[i]=max;
		}
	}
	int cost=0;
	for(int i=0;i<N;i++){
		cost+=(fina[i]-store[i])*(fina[i]-store[i]);
		fina[i]=store[i];
	}

	return cost;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("skidesign.out");
    	ifstream fin ("skidesign.in");
	fin>>N;
	for(int i=0;i<N;i++){
		fin>>store[i];
		fina[i]=store[i];
	}
	sort(store,store+N);
	sort(fina,fina+N);
	int mn=MOD;
//	cout<<store[N-1];
	for(int i=0;i<=store[N-1];i++){
		
		int c=cost(i,i+17);
		//cout<<c<<' ';
		if(c<mn){mn=c;}
	}
	fout<<mn<<'\n';
	//cin.tie(0);	
	return 0;
}
