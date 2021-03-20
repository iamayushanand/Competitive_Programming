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
TASK: ttwo
LANG: C++                 
*/
int gridt[11][11];
int ans;
int mvcw(int &x,int &y,int cd){
	if(cd==0){
		if(y>0 && gridt[x][y-1]==0){
			y--;
		}else{
			cd=1;
		}
		return cd;
	}
	if(cd==1){
		if(x<9 && gridt[x+1][y]==0){
			x++;
		}else{
			cd=2;
		}
		return cd;
	}

	if(cd==2){
		if(y<9 && gridt[x][y+1]==0){
			y++;
		}else{
			cd=3;
		}
		return cd;
	}
	if(cd==3){
		if(x>0 && gridt[x-1][y]==0){
			x--;
		}else{
			cd=0;
		}
		return cd;
	}
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("ttwo.out");
    	ifstream fin ("ttwo.in");
	int xcow,ycow;
	int xf,yf;
	for(int y=0;y<10;y++){
		for(int x=0;x<10;x++){
			char c;
			fin>>c;
			if(c=='*')gridt[x][y]=-1;
			if(c=='C'){xcow=x;ycow=y;}
			if(c=='F'){xf=x;yf=y;}
		}
	}
	int cd=0;
	int fd=0;
	while(true){
		if(ans>(400*400)){fout<<0<<'\n';return 0;}
		if(xf==xcow && yf==ycow)break;
		cd=mvcw(xcow,ycow,cd);	
		fd=mvcw(xf,yf,fd);
		ans++;
	}
	fout<<ans<<'\n';
	//cin.tie(0);	
	return 0;
}
