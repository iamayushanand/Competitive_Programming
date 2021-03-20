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
TASK: contact
LANG: C++                 
*/
struct cnts{
	string val;
	long long cnt;
};
vector<cnts> mapping;
void addcur(string cur){
	int sz=mapping.size();
	for(int i=0;i<sz;i++){
		if(mapping[i].val==cur){
			mapping[i].cnt++;
			return;
		}
	}
	cnts tmp;
	tmp.val=cur;
	tmp.cnt=1;
	mapping.push_back(tmp);
}
int cmpr(cnts A, cnts B){
	if(A.cnt>B.cnt) {return 1;}
	if(A.cnt<B.cnt) {return 0;}
	if(A.val.length()<B.val.length()) {return 1;}
	if(A.val.length()>B.val.length()) {return 0;}
	if(A.val<B.val) {return 1;}
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("contact.out");
    	ifstream fin ("contact.in");
	int A,B,N;
	fin>>A>>B>>N;
	string inp;
	while(fin){
		string tmp;
		fin>>tmp;
		inp=inp+tmp;
	}
	int sz=inp.length();
	for(int len=A;len<=B;len++){
		for(int i=0;i<sz-len+1;i++){
			string cur="";
			for(int j=i;j<i+len;j++){
				cur=cur+inp[j];
			}
			addcur(cur);
		}
	}
	sort(mapping.begin(),mapping.end(),cmpr);
	int cur=0;
	sz=mapping.size();
	while(cur<sz && N>0){
		int curfreq=mapping[cur].cnt;
		if(cur!=0)fout<<'\n';
		N--;
		fout<<curfreq<<'\n';
		int lincnt=0;
		while(curfreq==mapping[cur].cnt){
			if(lincnt==6){fout<<'\n';lincnt=0;}
			fout<<mapping[cur].val;
			if(cur!=sz-1 && curfreq==mapping[cur+1].cnt)fout<<" ";
			cur++;
			lincnt++;
		}
	}
	fout<<'\n';
	//cin.tie(0);	
	
	return 0;
}
