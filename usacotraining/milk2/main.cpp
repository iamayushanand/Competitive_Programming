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
#include <utility>

using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007

/*
ID: iamayus1
TASK: milk2
LANG: C++                 
*/

bool TimeComp(pair<int,int> p1 , pair<int,int> p2){
	return (p1.first<p2.first);
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("milk2.out");
    	ifstream fin ("milk2.in");
	int N,len;
	fin>>N;
	len=N;
	vector< pair<int,int> > Time;
	while(N--){
		pair<int,int> t;
		fin>>t.first>>t.second;
		Time.push_back(t);
	}
	sort(Time.begin(),Time.begin()+len,TimeComp);
	int prevclose=0;
	int prevstart=0;
	int mxf=0;
	int mnnf=0;
	for(int i=0;i<len;i++){
		pair<int,int> cur=Time.at(i);
		//cout<<prevstart<<' '<<prevclose<<' '<<'\n';
		if(cur.first<=prevclose){
			if(prevclose<=cur.second){
				prevclose=cur.second;
			}
		}else{
			
			if(mxf<(prevclose-prevstart)){
				mxf=prevclose-prevstart;
			}

			prevstart=cur.first;
			if((prevstart-prevclose)>mnnf && prevclose!=0){
				mnnf=prevstart-prevclose;
			}
//			cout<<prevstart-prevclose<<'\n';
			prevclose=cur.second;
		}

	}
	if(mxf<(prevclose-prevstart)){
		mxf=(prevclose-prevstart);
	}
	if(mnnf==1000001){
		mnnf=0;
	}
	fout<<mxf<<' '<<mnnf<<'\n';
	//cin.tie(0);	
	return 0;
}
