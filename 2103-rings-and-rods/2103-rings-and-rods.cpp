class Solution {
public:
int countPoints(string rings) {

    int arr[10][3];
    int i = 0;
    
    for(int i=0; i<10; i++){
        for(int j=0; j<3; j++){
            arr[i][j] = 0;
        }
    }
    
    
    while(i < rings.size()-1){
        if(rings[i] == 'R'){
            arr[rings[i+1] - '0'][0] = 1;
        }else if(rings[i] == 'G'){
            arr[rings[i+1] - '0'][1] = 1;
        }else if(rings[i] == 'B'){
            arr[rings[i+1] - '0'][2] = 1;
        }
        
        i = i+2;   
    }
    
    
    int c = 0;
    
    for(int i=0; i<10; i++){
        int s = 0;
        for(int j=0; j<3; j++){
            s = s + arr[i][j];
        }
        if(s == 3){
            c++;
        }
    }
    return c;   
}
};