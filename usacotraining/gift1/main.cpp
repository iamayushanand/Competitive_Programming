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
TASK: gift1
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("gift1.out");
    	ifstream fin ("gift1.in");
	int NP;
	fin>>NP;
	int temp=NP;
	map<string,int> accounts;
	vector<string> order;
	while(temp--){
		string name;
		fin>>name;
		accounts[name]=0;
		order.push_back(name);
	}
	for(int i=0;i<NP;i++){
		string curP;
		fin>>curP;
		int amt,dis;
		fin>>amt>>dis;
		accounts[curP]-=amt;
		if(dis==0)continue;
		int amtE=amt/dis;
		int carry=amt-dis*amtE;
		accounts[curP]+=carry;
		while(dis--){
			string givP;
			fin>>givP;
			accounts[givP]+=amtE;
		}
	}

	for(int i=0;i<NP;i++){
		fout<<order[i]<<' '<<accounts[order[i]]<<'\n';
	}
	//cin.tie(0);	
	return 0;
}
