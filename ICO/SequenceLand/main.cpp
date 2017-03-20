#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int ids[301][301];
int graph[301][301];
int M[301];
bool mrkd[301];
int N,K;
bool isconnected(int i,int j){
	vector<int> v(302);
	vector<int>::iterator it=set_intersection(ids[i],ids[i]+M[i],ids[j],ids[j]+M[j],v.begin());

	v.resize(it-v.begin());
//	for(int i=0;i<v.size();i++){
//		cout<<v[i];
//	}
//	cout<<endl;
	return v.size()>=K;
	
	
}
int dfs(int i,int cnt){
//	cout<<i<<endl;
	mrkd[i]=1;

	for(int j=0;j<N;j++){
		if(graph[i][j] && !mrkd[j]){
			cnt=dfs(j,cnt+1);
		}
	}
	return cnt;
}
int main(){
	
	cin>>N>>K;
	for(int i=0;i<N;i++){
		int cnt=0;
		cin>>cnt;
		M[i]=cnt;
		for(int j=0;j<cnt;j++){
			cin>>ids[i][j];
			
		}
		sort(ids[i],ids[i]+cnt);
	}
//	cout<<isconnected(0,1)<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)continue;
			if(isconnected(i,j)){
				graph[i][j]=1;			
			}else{
				graph[i][j]=0;
			}
		}
	}


	cout<<dfs(0,1);
}
