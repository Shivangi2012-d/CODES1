class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    
    
    {
        
        int N=matrix.size();
    int M=matrix[0].size();
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==target)
                {
                    
                    return true;
                    break;
                    
                }
                    
            }
            
        }
                
                
       return false; 
        
    }
};