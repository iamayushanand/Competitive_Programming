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
TASK: numtri
LANG: C++                 
*/
int N;
int store[1001][1001];
int ansst[1001][1001];
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("numtri.out");
    	ifstream fin ("numtri.in");
	fin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<i+1;j++){
			fin>>store[j][i];
		}
	}
	for(int i=0;i<N;i++){
		ansst[i][N-1]=store[i][N-1];
	}
	for(int y=N-2;y>=0;y--){
		for(int x=0;x<y+1;x++){
			ansst[x][y]=MAX(store[x][y]+ansst[x][y+1],store[x][y]+ansst[x+1][y+1]);
		}
	}
	fout<<ansst[0][0]<<'\n';
	//cin.tie(0);	
	return 0;
}
