#include <bits/stdc++.h>
using namespace std;


struct pset{
	int rank,par;
};

int top_par(int p,pset parent[]){
	if(p==parent[p].par)
		return p;
	return parent[p].par=top_par(parent[p].par,parent);// path compression
}

void form_cluster(int a,int b,pset parent[]){
	int par_a=top_par(a,parent);
	int par_b=top_par(b,parent);

	if(par_a==par_b){// they are in same cluster
		return;
	}

	if(parent[a].rank < parent[b].rank){
		parent[b].par=parent[a].par;	
	}
	else{
		parent[a].par=parent[b].par;
		if(parent[a].rank == parent[b].rank){
			parent[b].rank++;
		}
	}
}



int dsu(int n,vector<vector<int> > v ){
	
	pset parent[n];
	for(int i=0;i<n;i++){
		parent[i].par=i;
		parent[i].rank=0;
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			form_cluster(i,v[i][j],parent);
		}
	}
	int hash[n];
	fill(hash,hash+n,0);
	
	for(int i=0;i<n;i++){
		hash[parent[i].par]++;
	}
	
	for(int i=0;i<n;i++){
		cout<<hash[parent[i].par]<<" ";
	}
	cout<<endl;
}

void fun(){
	int n;
	cin>>n;
	int vertices=n;
	vector<vector<int> > v(vertices);
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);	
		v[b].push_back(a);
	}
	
	dsu(vertices,v);
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		fun();
	}
	return 0;
}
