class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int r = grid.size();
        int c = grid[0].size();
        
        list<vector<int>> queue;
        vector<int> node; int r1, c1;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                
                if(grid[i][j] == '1') {
                    
                    
                    queue.push_back({i, j});
                    
                    while(!queue.empty())
                    {
                        node = queue.front();
                        queue.pop_front();
                        
                        r1=node[0];
                        c1=node[1];
                        grid[r1][c1]='2';
                        
                        if(r1>0 && grid[r1-1][c1]=='1' )
                           
                        {
                            queue.push_back({r1-1, c1});
                            grid[r1-1][c1]='2';
                            

                        }
                        if(r1<r-1 && grid[r1+1][c1]=='1')
                           
                        {
                            queue.push_back({r1+1, c1});
                            grid[r1+1][c1]='2';
                           
                        }
                        if(c1>0 && grid[r1][c1-1]=='1' )
                           
                        {
                            queue.push_back({r1, c1-1});
                            grid[r1][c1-1]='2';
                           

                        }
                        if(c1<c-1 && grid[r1][c1+1]=='1' )
                           
                        {
                            queue.push_back({r1, c1+1});
                            grid[r1][c1+1]='2';
                            
                        }
                    }
                    islands+=1;
                } 
            }
        }
        return islands;
    }
};