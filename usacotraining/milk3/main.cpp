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
TASK: milk3
LANG: C++                 
*/
int c1,c2,c3;
bool visited[21][21][21];
vector<int> ans;
int solve(int a,int b,int c){
//	cout<<a<<' '<<b<<' '<<c<<'\n';
	if(visited[a][b][c]){return 0;}
	visited[a][b][c]=1;
	if(a==0){ans.push_back(c);}
	int to,frm;
	to=MIN(b+c,c2);
	frm=b+c-to;
	solve(a,to,frm);
	to=MIN(b+c,c3);
	frm=b+c-to;
	solve(a,frm,to);
	to=MIN(a+c,c1);
	frm=a+c-to;
	solve(to,b,frm);
	to=MIN(a+c,c3);
	frm=a+c-to;
	solve(frm,b,to);
	to=MIN(a+b,c2);
	frm=b+a-to;
	solve(frm,to,c);
	to=MIN(b+a,c1);
	frm=b+a-to;
	solve(to,frm,c);
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("milk3.out");
    	ifstream fin ("milk3.in");
	fin>>c1>>c2>>c3;
	solve(0,0,c3);
	sort(ans.begin(),ans.end());
	int sz=ans.size();
	for(int i=0;i<sz;i++){
		if(i!=(sz-1)){
			fout<<ans[i]<<' ';
		}else{
			fout<<ans[i];
		}
	}
	fout<<'\n';
	//cin.tie(0);	
	return 0;
}
