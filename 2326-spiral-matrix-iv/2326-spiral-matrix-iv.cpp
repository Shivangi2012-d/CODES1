class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        //Creating a vector with all its initial values as -1
        vector<vector<int>> output(m, vector<int>(n, -1));
        
        ListNode* current = head;
        
        int firstRow = 0, lastRow = m - 1;
        int firstCol = 0, lastCol = n - 1;
        
        int i = 0, total = m * n;
        while(i < total){
            
            for(int ind = firstCol; ind <= lastCol && i < total; ind++){
                if(current != NULL){
                    output[firstRow][ind] = current -> val;
                    current = current ->next;
                }
                i++;
            }
            firstRow++;
            
            for(int ind = firstRow; ind <= lastRow && i < total; ind++){
                if(current != NULL){
                    output[ind][lastCol] = current -> val;
                    current = current ->next;
                }
                i++;
            }
            lastCol--;
            
            for(int ind = lastCol; ind >= firstCol&& i < total; ind--){
                if(current != NULL){
                    output[lastRow][ind] = current -> val;
                    current = current ->next;
                }
                i++;
            }
            lastRow--;
            
            for(int ind = lastRow; ind >= firstRow && i < total; ind--){
                if(current != NULL){
                    output[ind][firstCol] = current -> val;
                    current = current ->next;
                }
                i++;
            }
            firstCol++;  
        }
        
        return output;
    }
};