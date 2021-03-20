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
TASK: stamps
LANG: C++                 
*/
int cents[201];
int minterms[2000001];
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("stamps.out");
    	ifstream fin ("stamps.in");
	int N,K;
	fin>>K>>N;
	int mx=0;
	for(int i=0;i<N;i++){
		fin>>cents[i];
		mx=MAX(cents[i],mx);
	}
	for(int j=0;j<=mx*K;j++){
		minterms[j]=INF;
	}
	minterms[0]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=mx*K;j++){
			if(minterms[j]<K){
				if(minterms[j+cents[i]]>1+minterms[j]){
					minterms[j+cents[i]]=1+minterms[j];
				}
			}
		}
	}
	int ans=0;
	for(ans=0;ans<=mx*K && minterms[ans]<=K;ans++);
	fout<<ans-1<<'\n';
	//cin.tie(0);	
	return 0;
}
