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
TASK: transform
LANG: C++                 
*/
int N;
vector< vector<char> > rota90(vector< vector<char> > a){
	vector< vector<char> > b;
	for(int i=0;i<N;i++){
		vector<char> ins;
		for(int j=0;j<N;j++){
			ins.push_back(a[j][i]);
			
		}
		reverse(ins.begin(),ins.begin()+N);
		b.push_back(ins);
	}
	return b;
}

vector< vector<char> > refl(vector< vector<char> > a){
	for(int i=0;i<N;i++){
		reverse(a[i].begin(),a[i].begin()+N);
	}
	return a;
}
bool isEqual(vector< vector<char> > a, vector< vector<char> > b){
	bool flag=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]!=b[i][j]){
				flag=0;
			}
		}
	}
	return flag;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("transform.out");
    	ifstream fin ("transform.in");
	fin>>N;
	vector< vector<char> > init;
	vector< vector<char> >  fina;
	for(int i=0;i<N;i++){
		vector<char> ins;
		for(int j=0;j<N;j++){
			char a;
			fin>>a;
			ins.push_back(a);
		}
		init.push_back(ins);
	}
	
	for(int i=0;i<N;i++){
		vector<char> ins;
		for(int j=0;j<N;j++){
			char a;
			fin>>a;
			ins.push_back(a);
		}
		fina.push_back(ins);
	}
	if(isEqual(rota90(init),fina)){fout<<'1'<<'\n';return 0;}
	if(isEqual(rota90(rota90(init)),fina)){fout<<'2'<<'\n';return 0;}
	if(isEqual(rota90(rota90(rota90(init))),fina)){fout<<'3'<<'\n';return 0;}
	if(isEqual(refl(init),fina)){fout<<'4'<<'\n';return 0;}
	if(isEqual(rota90(refl(init)),fina) || isEqual(rota90(rota90(refl(init))),fina) || isEqual(rota90(rota90(rota90(refl(init)))),fina)){fout<<'5'<<'\n';return 0;}  
	if(isEqual(init,fina)){fout<<'6'<<'\n';return 0;}
	fout<<'7'<<'\n';
	//cin.tie(0);	
	return 0;
}
