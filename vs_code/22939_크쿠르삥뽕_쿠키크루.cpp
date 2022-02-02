#include<iostream>
#include<vector>

using namespace std;

int n;
vector<string>map;
string s;
vector<pair<int,int>>start,end_,map_j,map_c,map_b,map_w;
int min_cookie[4];

int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='H') start.push_back({i,j});
            if(s[j]=='#') end_.push_back({i,j});
            if(s[j]=='J') map_j.push_back({i,j});
            if(s[j]=='C') map_c.push_back({i,j});
            if(s[j]=='B') map_b.push_back({i,j});
            if(s[j]=='W') map_w.push_back({i,j});
        }
        map.push_back(s);
    }
}

int search_map(vector<pair<int,int>> v,int a,int b,int c){
    int val=0;  
    val+=dist(start[0].first,start[0].second,v[a].first,v[a].second);
    val+=dist(v[a].first,v[a].second,v[b].first,v[b].second);
    val+=dist(v[b].first,v[b].second,v[c].first,v[c].second);
    val+=dist(v[c].first,v[c].second,end_[0].first,end_[0].second);

    return val;
}

int search_maps(vector<pair<int,int>> v){
    int ans = search_map(v,0,1,2);
    ans = min(search_map(v,0,2,1),ans);
    ans = min(search_map(v,1,0,2),ans);
    ans = min(search_map(v,1,2,0),ans);
    ans = min(search_map(v,2,0,1),ans);
    ans = min(search_map(v,2,1,0),ans);
    return ans;
}

string solve(){
    min_cookie[0]=search_maps(map_j);
    min_cookie[1]=search_maps(map_c);
    min_cookie[2]=search_maps(map_b);
    min_cookie[3]=search_maps(map_w);

    int cmp = min_cookie[0],x=0;
    for(int i=1;i<4;i++){
        if(cmp>min_cookie[i]) {
            cmp=min_cookie[i];
            x=i;
        }
    }

    if(x==0) return "Assassin";
    else if(x==1) return "Healer";
    else if(x==2) return "Mage";
    else if(x==3) return "Tanker";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    cout<<solve()<<"\n";
    return 0;
}