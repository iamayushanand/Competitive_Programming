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
TASK: preface
LANG: C++                 
*/
int checkpoints[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string corresponding[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
map<char,int> ans;
string convert(int a){
	string converted="";
	int thrice=0;
	for(int i=0;i<13;i++){
		if(a>=checkpoints[i]){
			converted+=corresponding[i];
			a-=checkpoints[i];
			if((i==0 || i==4 || i==8 || i==12) && thrice!=3){
				i--;
				thrice++;
				continue;
			}
		}

		thrice=0;
	}
	return converted;
}
void init(){
	ans['I']=0;
	ans['V']=0;
	ans['X']=0;
	ans['L']=0;
	ans['C']=0;
	ans['D']=0;
	ans['M']=0;

}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("preface.out");
    	ifstream fin ("preface.in");
	int N;
	fin>>N;
	init();
	for(int i=1;i<=N;i++){
		string s;
		s=convert(i);
//		cout<<i<<' '<<s<<'\n';
		int sz=s.size();
		for(int i=0;i<sz;i++){
			ans[s[i]]++;
				
		}
	}
	if(ans['I']!=0){
		fout<<'I'<<' '<<ans['I']<<'\n';
	}
	if(ans['V']!=0){
		fout<<'V'<<' '<<ans['V']<<'\n';
	}
	if(ans['X']!=0){
		fout<<'X'<<' '<<ans['X']<<'\n';
	}
	if(ans['L']!=0){
		fout<<'L'<<' '<<ans['L']<<'\n';
	}
	if(ans['C']!=0){
		fout<<'C'<<' '<<ans['C']<<'\n';
	}
	if(ans['D']!=0){
		fout<<'D'<<' '<<ans['D']<<'\n';
	}
	if(ans['M']!=0){
		fout<<'M'<<' '<<ans['M']<<'\n';
	}
	//cin.tie(0);	
	return 0;
}
