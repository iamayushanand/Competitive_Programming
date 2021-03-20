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
#include <iomanip>
#include <limits.h>
using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007

/*
ID: iamayus1
TASK: cowtour
LANG: C++                 
*/
int X[151];
int Y[151];
int gph[151][151];
double dist[151][151];
int N;
double pythg(int x,int y){
	double xdiff=(double)X[x]-(double)X[y];
	double ydiff=(double)Y[x]-(double)Y[y];
	double ans=sqrt((xdiff*xdiff)+(ydiff*ydiff));
	return ans;
}
double shrt[151][151];
int fields[151];
double diam[151];
double fielddiam[151];
int currfield=1;
void dfs(int x){
	if(fields[x]!=0)return;
	fields[x]=currfield;
	for(int y=0;y<N;y++){
		if(gph[x][y]){
			dfs(y);
		}
	}
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("cowtour.out");
    	ifstream fin ("cowtour.in");
	fin>>N;
	for(int i=0;i<N;i++){
		fin>>X[i]>>Y[i];
	}
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			char ch;
			fin>>ch;
			if(x==y){dist[x][y]=0;continue;}
			gph[x][y]=ch-'0';
//			fout<<gph[x][y]<<'\n';
			if(gph[x][y]){
				dist[x][y]=pythg(x,y);
			}else{
				dist[x][y]=(1e40);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			shrt[i][j]=dist[i][j];
		}
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(shrt[i][k]+shrt[k][j]<shrt[i][j]){
					shrt[i][j]=shrt[i][k]+shrt[k][j];
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		dfs(i);
		currfield++;
//		fout<<fields[i]<<'\n';
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(shrt[i][j]>diam[i] && fields[i]==fields[j]){
				diam[i]=shrt[i][j];
			}
		}
	}
	for(int i=0;i<N;i++){
		if(diam[i]>fielddiam[fields[i]]){
			fielddiam[fields[i]]=diam[i];
		}
	}
//	fout<<fielddiam[6]<<'\n';
	double ans=1e40;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(fields[i]==fields[j]){continue;}
			double tmp=diam[i]+diam[j]+pythg(i,j);
			if(fielddiam[fields[i]]>tmp){
				tmp=fielddiam[fields[i]];
			}
			if(fielddiam[fields[j]]>tmp){
				tmp=fielddiam[fields[j]];
			}
			if(tmp<ans){
				ans=tmp;
			}
		}
	}
	fout<<setprecision(6)<<fixed<<ans<<'\n';
	//cin.tie(0);	
	return 0;
}
