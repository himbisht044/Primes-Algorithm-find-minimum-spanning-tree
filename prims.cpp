#include <bits/stdc++.h>
using namespace std;

#define pii pair <int ,int>

const int MAX = 1e5;
const int INF = 1e9;
vector <vector< pii > > graph(MAX);

vector < bool > seen(MAX);
vector < int > dist(MAX, INF);
vector < int > parent(MAX,-1);
int V,E,x,y,wt;

void MST(int id){
	priority_queue < pii, vector < pii>, greater <pii> > pq;
	dist[id] = 0;
	pq.push(make_pair(dist[id],id));

	while(!pq.empty()){
		pii top = pq.top();
		int pid = top.second, pcost = top.first;
		pq.pop();
		if(seen[pid]) continue; 
		seen[pid] = true;
		for(auto it: graph[pid]){
			int cid = it.first, ccost = it.second;
			if(seen[cid]==true) continue;
			if(dist[cid]>ccost){
				dist[cid] = ccost;
				parent[cid]=pid;
				pq.push(make_pair(dist[cid],cid));
			}
		}

	}
	for(int i=0;i<V;i++){
		cout<<i<<" "<<dist[i]<<" "<<parent[i]<<endl;
	}
}


int main(){

	freopen("inp.txt","r",stdin);
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>x>>y>>wt;
		graph[x].push_back(make_pair(y,wt));
		graph[y].push_back(make_pair(x,wt));
	}
	MST(0);


}