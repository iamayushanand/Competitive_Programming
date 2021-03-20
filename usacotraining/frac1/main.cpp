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
TASK: frac1
LANG: C++                 
*/
vector<string> ans;
vector< pair<double,int> > order;
bool iscoprime(int num,int den){
	if(num%2==0 && den%2==0){return 0;}
	for(int i=3;i<=num;i+=2){
		if(num%i==0 && den%i==0){
			return 0;
		}
	}
	if(den%num==0 && num!=1){return 0;}
	return 1;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("frac1.out");
    	ifstream fin ("frac1.in");
	int N;
	fin>>N;
	int cnt=0;
	for(int den=N;den>0;den--){
		for(int num=1;den>num;num++){
			if(iscoprime(num,den)){
				pair<double,int> p ((double)num/(double)den,cnt++);
				ans.push_back(to_string(num)+'/'+to_string(den));
				order.push_back(p);
			}
		}
	}
	sort(order.begin(),order.end());
	fout<<0<<'/'<<1<<'\n';
	for(int i=0;i<cnt;i++){
		fout<<ans[order[i].second]<<'\n';
	}
	fout<<1<<'/'<<1<<'\n';
	//cin.tie(0);	
	return 0;
}
