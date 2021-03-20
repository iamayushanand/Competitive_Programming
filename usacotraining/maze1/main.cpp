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
TASK: maze1
LANG: C++                 
*/
char gridt[78][201];
vector< pair<int,int> > exits;
int dist1[78][201];
int dist2[78][201];
bool visited[78][201];
int w,h;
void bfs(int x,int y){
	queue< pair<int,int> > que;
	pair<int,int> cur(x,y);
	que.push(cur);
	while(!que.empty()){
		cur=que.front();
		que.pop();
		x=cur.first;
		y=cur.second;
		visited[x][y]=1;
		if(gridt[x+1][y]==' ' && x!=w-2 && !visited[x+2][y]){
			pair<int,int> p(x+2,y);
			que.push(p);
			dist1[x+2][y]=dist1[x][y]+1;
			visited[x+2][y]=1;
		}
		if(gridt[x-1][y]==' ' && x!=1 && !visited[x-2][y]){
			pair<int,int> p(x-2,y);
			que.push(p);
			dist1[x-2][y]=dist1[x][y]+1;
			visited[x-2][y]=1;
		}
		if(gridt[x][y+1]==' ' && y!=h-2 && !visited[x][y+2]){
			pair<int,int> p(x,y+2);
			que.push(p);
			dist1[x][y+2]=dist1[x][y]+1;
			visited[x][y+2]=1;
		}
		if(gridt[x][y-1]==' ' && y!=1 && !visited[x][y-2]){
			pair<int,int> p(x,y-2);
			que.push(p);
			dist1[x][y-2]=dist1[x][y]+1;
			visited[x][y-2]=1;
		}
//		cerr<<x<<' '<<y<<'\n';
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("maze1.out");
    	ifstream fin ("maze1.in");
	fin>>w>>h;
	w=2*w+1;
	h=2*h+1;
	
	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			char ch;
			fin.get(ch);
			if(ch=='\n'){
				x--;
				continue;
			}
			if(x==0 && ch==' '){
				pair<int,int> ex(1,y);
				exits.push_back(ex);
			}
			if(y==0 && ch==' '){
				pair<int,int> ex(x,1);
				exits.push_back(ex);
			}
			if(x==(w-1) && ch==' '){
				pair<int,int> ex(w-2,y);
				exits.push_back(ex);
			}
			if(y==(h-1) && ch==' '){
				pair<int,int> ex(x,h-2);
				exits.push_back(ex);
			}
			gridt[x][y]=ch;
		}
	}
	bfs(exits[0].first,exits[0].second);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			dist2[j][i]=dist1[j][i];
			dist1[j][i]=0;
//			cerr<<dist2[j][i]<<' ';
			visited[j][i]=0;
		}
//		cerr<<'\n';
	}
//	cerr<<"reached";
	bfs(exits[1].first,exits[1].second);
	int ans=0;
	for(int i=1;i<h;i+=2){
		for(int j=1;j<w;j+=2){
			ans=MAX(ans,MIN(dist1[j][i],dist2[j][i]));
		}
	}
	fout<<ans+1<<'\n';
	//cin.tie(0);	
	return 0;
}
