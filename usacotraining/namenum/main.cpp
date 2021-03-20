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
TASK: namenum
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("namenum.out");
    	ifstream fin ("namenum.in");
	map<int, vector<char> > keymap;
	int cur=0;
	for(int i=0;i<9;i++){
		vector<char> ins;
		for(int j=0;j<3;j++){
			if('A'+cur=='Q'){cur++;}
			ins.push_back('A'+cur);
			cur++;
		}
		keymap[i]=ins;
	}
	ifstream dict("dict.txt");
	string key;
	fin>>key;
	int sz=key.size();
	bool non=1;
	while(dict){
		string current;
		dict>>current;
	//	fout<<current<<'\n';
		bool valid=1;
		if(sz!=current.size()){continue;}
		for(int i=0;i<sz;i++){
			if(!(keymap[key[i]-'2'][0]==current[i] || keymap[key[i]-'2'][1]==current[i] || keymap[key[i]-'2'][2]==current[i])){
				valid=0;
			}
		}
		if(valid){fout<<current<<'\n';non=0;}
	}
	if(non){fout<<"NONE"<<'\n';}
	//cin.tie(0);	
	return 0;
}
