class MedianFinder {
public:
    // Constructor
    MedianFinder(){
        count = 0;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if (count % 2 == 0){
            if (minHeap.empty()){
                 minHeap.push(num);
            }else{
                if (num <= maxHeap.top()){
                    maxHeap.push(num);
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }else {
                    minHeap.push(num);
                }
            }
        }else{
            if (num >= minHeap.top()){
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }else{
                maxHeap.push(num);
            }
        }
        
        count ++;
        
        
        
        // cout << "count = " << count<< endl;
        // cout << "maxHeap: ";
        // print_queue(maxHeap);
        // cout << endl << "minHeap: ";
        // print_queue(minHeap);
        // cout << endl;
    }

    // Returns the median of current data stream
    double findMedian() {
        return count % 2 == 0 ? double(minHeap.top() + maxHeap.top()) / 2 : minHeap.top();
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int> >  minHeap;
    int count;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian()