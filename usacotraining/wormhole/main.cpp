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
TASK: wormhole
LANG: C++                 
*/
int N;
vector< pair<long long, long long> > nodes;
long long pairing[12];
int ans=0;
int iscycle(int i){
	

		bool flag=1;
		int twice=0;
		bool visited[12];
		fill_n(visited,12,0);
		int cur=i;
		
		do{
			if(flag){
				visited[cur]=1;
				cur=pairing[cur];
				//cout<<cur;
				flag=!flag;
			}else{
				bool non=1;
				visited[cur]=1;
				for(int j=cur+1;j<N;j++){
			//		cout<<cur<<' '<<j<<'\n';
					if(nodes[j].second==nodes[cur].second){
						cur=j;
						non=0;
						break;
					}
				}
//				cout<<non<<' ';
				if(non){return 0;}
				flag=!flag;

			}
			if(cur==i){twice++;}
//			cout<<cur<<' '<<flag<<'\n';
		}while(twice!=2);
//		if(visited[cur]){return 1;}
		//fill_n(visited,12,0);
	
	return 1;	
}
int solve(){
	int i;
	for(i=0;i<N;i++){
		if(pairing[i]==-1){
			break;
		}
	}
//	cout<<i<<' '<<(i==(N-1))<<'\n';
	if(i==N ||  i==11 ){
		bool temp=0;
		for(int i=0;i<N;i++){
			if(iscycle(i)){temp=1;}
		}
		ans+=temp;
	}
	for(int j=i+1;j<N;j++){
//		cout<<j<<' ';
		if(pairing[j]==-1){
			pairing[i]=j;
			pairing[j]=i;
			solve();
			pairing[i]=-1;
			pairing[j]=-1;
		}
	}
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("wormhole.out");
    	ifstream fin ("wormhole.in");
	fin>>N;

	for(int i=0;i<N;i++){
		pair<long long,long long> p;
		fin>>p.first>>p.second;
		nodes.push_back(p);
	}
	sort(nodes.begin(),nodes.end());
	fill_n(pairing,12,-1);
//	cout<<pairing[11];
	solve();
	fout<<ans<<'\n';
//	cout<<lookup[1].size();
	//cin.tie(0);	
	return 0;
}
