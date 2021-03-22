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
 
using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007
vector< pair<int,int> > dirx;
bool visited[301][301];
long long dfs(int stx,int sty,int R,int C,long long grid[301][301]){
	if(stx<0 || stx>=R || sty<0 || sty>=C)return 0;
	visited[stx][sty]=1;
	int ans=0;
	for(int i=0;i<4;i++){
		int x=dirx[i].first+stx;
		int y=dirx[i].second+sty;
//		cout<<x<<' '<<y<<'\n';
		if(x<0 || x>=R || y<0 || y>=C)continue;
		if(grid[stx][sty]-grid[x][y]>1){
			ans+=grid[stx][sty]-grid[x][y]-1;
			grid[x][y]=grid[stx][sty]-1;
//			ans+=dfs(x,y,R,C,grid);
		}
		if(!visited[x][y]){
			ans+=dfs(x,y,R,C,grid);
		}
	}
	return ans;
}
long long solve(){
	int R,C;
	cin>>R>>C;
	long long grid[301][301];
	int mx=-1;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>grid[i][j];
			mx=MAX(mx,grid[i][j]);
		}
	}
	vector< pair<int,int> > sth;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(mx==grid[i][j]){
				sth.push_back(make_pair(i,j));	
			}
		}
	}
	long long ans=0;
	int sz=sth.size();
	//for(int i=0;i<sz;i++){
	//	ans+=dfs(sth[i].first,sth[i].second,R,C,grid);
	//}
	ans=dfs(0,0,R,C,grid);
	return ans;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int T;
	cin>>T;
	dirx.push_back(make_pair(1,0));
	dirx.push_back(make_pair(0,1));
	dirx.push_back(make_pair(-1,0));
	dirx.push_back(make_pair(0,-1));
	for(int i=1;i<=T;i++){
		for(int x=0;x<=300;x++){
			for(int y=0;y<=300;y++){
				visited[x][y]=0;
			}
		}
		cout<<"Case #"<<i<<": "<<solve()<<'\n';
	}

	return 0;
}
