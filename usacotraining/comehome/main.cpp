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
TASK: comehome
LANG: C++                 
*/
long long dist[200][200];
long long parent[200];
bool isnode[200];
int visitedN;
bool visited[200];
long long shrt[200];
int total;
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("comehome.out");
    	ifstream fin ("comehome.in");
	int P;
	fin>>P;
	for(int i=0;i<200;i++){
		for(int j=0;j<200;j++){
			if(i==j){dist[i][j]=0;continue;}
			dist[i][j]=(long long)(INF);
		}
		shrt[i]=(long long)(INF);
		parent[i]=-1;
	}
	for(int i=0;i<P;i++){
		char st,en;
		long long di;
		fin>>st>>en>>di;
		if(st!=en){
			if(dist[st-'A'][en-'A']>di){
			dist[st-'A'][en-'A']=di;
			dist[en-'A'][st-'A']=di;
			}
		}
		if(!isnode[st-'A'])total++;
		if(!isnode[en-'A'])total++;
		isnode[st-'A']=1;
		isnode[en-'A']=1;
	}
	int curr='Z'-'A';
	int src='Z'-'A';
	shrt[src]=0;
	while(visitedN<=total){
		visitedN++;
		int temp=0;
		for(int i=0;i<200;i++){
			if(!visited[i] && shrt[i]<shrt[temp]){
				temp=i;
			}
		}
		if(temp==0 && visited[0])break;
		curr=temp;
		visited[curr]=1;
		for(int i=0;i<200;i++){
			if(dist[curr][i]<(long long)(INF) && shrt[curr]+dist[curr][i]<shrt[i]){
				shrt[i]=shrt[curr]+dist[curr][i];
				parent[i]=curr;
			}
		}
	}
	long long mindis=INF;
	char minval='A';
	for(char i='A';i<'Z';i++){
//		cout<<shrt[i-'A']<<' ';
		if(shrt[i-'A']<mindis){
			mindis=shrt[i-'A'];
			minval=i;
		}

	}
	fout<<minval<<' '<<mindis<<'\n';
	//cin.tie(0);	
	return 0;
}
