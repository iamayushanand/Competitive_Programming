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
TASK: castle
LANG: C++                 
*/
int M,N;
vector< pair<int,int> > adj[51][51];
int comp[51][51];
int mxrm=0;
int xl=-1;
int yl=-1;
char dir;
vector<int> cntcom;
int dfs(int cur,int x,int y){
	int cnt=0;
	if(comp[x][y]==0){
		comp[x][y]=cur;
	}else{
		return 0;
	}
	cnt++;
	int sz=adj[x][y].size();
	for(int i=0;i<sz;i++){
//		cout<<adj[x][y][i].first<<' '<<adj[x][y][i].second<<'\n';
		cnt+=dfs(cur,adj[x][y][i].first,adj[x][y][i].second);
	}
	return cnt;
}
int rooms(){
	int tot=0;
	for(int x=0;x<M;x++){
		for(int y=0;y<N;y++){
			if(comp[x][y]==0){
				int tmp=dfs(++tot,x,y);
				cntcom.push_back(tmp);
				mxrm=MAX(tmp,mxrm);
			}	
		}
	}
	return tot;
}
int rmblock(){
	int mx=0;
	for(int x=0;x<M;x++){
		for(int y=(N-1);y>=0;y--){
			int tmp=0;
			if(y!=0 && comp[x][y]!=comp[x][y-1]){
				tmp=cntcom[comp[x][y]-1]+cntcom[comp[x][y-1]-1];
				if (tmp>mx) {
					xl=x;
					yl=y;
					dir='N';
					mx=tmp;
				}
			}
			if(x!=(M-1) && comp[x][y]!=comp[x+1][y]){
				tmp=cntcom[comp[x][y]-1]+cntcom[comp[x+1][y]-1];
				if (tmp>mx) {
					
					xl=x;
					yl=y;
					dir='E';
					mx=tmp;
				}
			}
		}
	}
	return mx;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("castle.out");
    	ifstream fin ("castle.in");
	fin>>M>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int x;
			fin>>x;
			if((x/8)==0){
				pair<int,int> p (j,i+1);
				adj[j][i].push_back(p);
			
			}else{x-=8;}
			if((x/4)==0){
				pair<int,int> p (j+1,i);
				adj[j][i].push_back(p);
				
			}else{x-=4;}
			if((x/2)==0){
				pair<int,int> p(j,i-1);
				adj[j][i].push_back(p);
				
			}else{x-=2;}
			if(x==0){
				pair<int,int> p(j-1,i);
				adj[j][i].push_back(p);
			
			}
			
		}
	}
	fout<<rooms()<<'\n'<<mxrm<<'\n'<<rmblock()<<'\n'<<yl+1<<' '<<xl+1<<' '<<dir<<'\n';
//	print();
	//cin.tie(0);	
	return 0;
}
