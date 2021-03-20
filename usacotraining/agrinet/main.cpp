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
TASK: agrinet
LANG: C++                 
*/

int weight[101][101];
int dist[101];
int ans;
int treesz;
int N;
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("agrinet.out");
    	ifstream fin ("agrinet.in");
	fin>>N;
	for(int y=0;y<N;y++){
		for(int x=0;x<N;x++){
			fin>>weight[x][y];
		}
		dist[y]=weight[0][y];
	}
	dist[0]=0;
	for(int x=0;x<N;x++){
		dist[x]=weight[0][x];
	}
	treesz=1;
	while(N>treesz){
		int clst=0;
		int midis=INF;
		for(int i=0;i<N;i++){
			if(dist[i]<midis && dist[i]!=0){
				clst=i;
				midis=dist[i];
			}
		}
		ans+=midis;
		treesz++;
		dist[clst]=0;
		for(int i=0;i<N;i++){
			if(dist[i]>weight[i][clst]){
				dist[i]=weight[i][clst];
			}
		}
	}
	fout<<ans<<'\n';

	//cin.tie(0);	
	return 0;
}
