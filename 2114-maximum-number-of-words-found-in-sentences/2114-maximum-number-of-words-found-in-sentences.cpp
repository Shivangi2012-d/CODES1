class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
     int n= sentences.size();
        int space=0;
    
        for (int i=0;i<n;i++)
        {                                     
		            
            int count=1;
           
            for(int j=0;j<sentences[i].size();j++)                             
            {                  
			     
            if (sentences[i][j]==' ')
                count++;
            }
			
			
            if(space<count)
                space=count;
        }
        
        return space;
    }
};