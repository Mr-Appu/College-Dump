#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a,b; cin >> a >> b;

    int n = a.length();
    int m = b.length();

    vector <vector <int>> arr(m+1,vector<int>(n+1,0));
    vector <vector<pair<int,int>>> parent(m+1,vector<pair<int,int>> (n+1,{-1,-1}));

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[i-1] == a[j-1])
            {
                arr[i][j] = arr[i-1][j-1] + 2;
                parent[i][j] = {i-1,j-1};
            }
            else
            {
                int x = 0;
                if(x < arr[i-1][j]-1)
                {
                    x = arr[i-1][j] - 1;
                    parent[i][j] = {i-1,j};
                }
                if(x < arr[i][j-1]-1)
                {
                    x = arr[i][j-1] - 1;
                    parent[i][j] = {i,j-1};
                }
                if(x < arr[i-1][j-1]-1)
                {
                    x = arr[i-1][j-1] - 1;
                    parent[i][j] = {i-1,j-1};
                }
                arr[i][j] = x;
            }
        }
    }

    for(auto i : arr)
    {
        for(int j : i) cout << j << ' ';
        cout << '\n';
    }
    
    int max_score = -1;
    for(int i=0;i<=m;i++)
    {
        max_score = max(max_score,*max_element(arr[i].begin(),arr[i].end()));
    }
    
    vector <pair<int,int>> max_pos;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(arr[i][j] == max_score) max_pos.push_back({i,j});
        }
    }
    
    cout << "MAX SCORE : " << max_score << "\n\n";
    
    cout << "Alignment \n";
    for(auto i : max_pos)
    {
        int x = i.first;
        int y = i.second;
        
        vector <pair<int,int>> ans;
        
        string aout = "";
        string bout = "";
    
        while(x != -1 && y != -1)
        {
            ans.push_back({x,y});
            int a = x;
            int b = y;
            x = parent[a][b].first;
            y = parent[a][b].second;
        }
    
        for(int i=0;i<ans.size()-1;i++) 
        {
            int cur_x = ans[i].first;
            int cur_y = ans[i].second;
    
            int next_x = ans[i+1].first;
            int next_y = ans[i+1].second;
    
            if(cur_x != next_x && cur_y != next_y) {
                if(a[cur_y-1] != b[cur_x-1]) aout += "_";
                aout += a[cur_y-1];
                bout += b[cur_x-1];
                if(a[cur_y-1] != b[cur_x-1]) bout += "_";
            } 
            if(cur_x == next_x && cur_y != next_y) {
                aout += a[cur_y-1];
                bout += "_";
            }
            if(cur_x != next_x && cur_y == next_y) {
                aout += "_";
                bout += b[cur_x-1];
            }
    
            x = cur_x - 1;
            y = cur_y - 1;
        }
    
        if(x == -1 && y == -1) return;
    
        reverse(aout.begin(),aout.end());
        reverse(bout.begin(),bout.end());
    
        cout << aout << '\n';
        cout << bout << '\n';
        cout << '\n';
    }
}

int main() 
{
    solve();
	return 0;
}
