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
TASK: ariprog
LANG: C++                 
*/
int M;
int N;
bool lookup[125001];
set<int> bisq;
int generate(){
	for(int p=0;p<=M;p++){
		for(int q=p;q<=M;q++){
			lookup[p*p+q*q]=1;
			bisq.insert(p*p+q*q);
		}
	}
	return 0;
}
int check(int a,int d){
	int t=N;
	while(--t){
		a+=d;
		if(a>125000){return 0;}
		if(!lookup[a]){
			return 0;	
		}
	}
	return 1;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("ariprog.out");
    	ifstream fin ("ariprog.in");
	fin.tie(0);
	fin>>N>>M;
	generate();
	bool none=1;
	int bisql=bisq.size();
//	cout<<bisql<<' '<<'\n';
	set<int>::iterator bisqt;
	vector< pair<int,int> > ans;
	for(bisqt=bisq.begin();bisqt!=bisq.end();bisqt++){
//		set<int> order;
		for(int d=1;d<=bisql;d++){
//			for(int q=p;q<=M;q++){
			//if(!lookup[i]){continue;}
			
				if(check(*bisqt,d)){
					pair<int,int> p;
					p.first=d;
					p.second=*bisqt;
					ans.push_back(p);
					none=0;
//					order.insert(*bisqt);
				}
//			}
		}
//		int sz=order.size();
//		set<int>::iterator itr;
//		for(itr=order.begin();itr!=order.end();itr++){
//			fout<<*itr<<' '<<d<<'\n';
//		}
//		order.clear();
	}
	if(none){fout<<"NONE"<<'\n';}
	sort(ans.begin(),ans.end());
	int sz=ans.size();
	for(int i=0;i<sz;i++){
		fout<<ans[i].second<<' '<<ans[i].first<<'\n';
	}
//	fin.tie(0);	
	return 0;
}
