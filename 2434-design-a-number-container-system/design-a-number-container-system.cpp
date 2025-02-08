class NumberContainers {
private:
    class FastMin {
        private:
            priority_queue<int, vector<int>, greater<int>> minHeap;
            unordered_map<int, int> count;

        public:
            void insert(int num) {
                count[num]++;
                minHeap.push(num);
            }

            void erase(int num) {
                if (count[num] > 0) {
                    count[num]--;
                }
            }

            int getMin() {
                while (!minHeap.empty() and count[minHeap.top()] == 0) {
                    minHeap.pop();
                }
                return minHeap.empty() ? -1 : minHeap.top();
            }
};
public:
    unordered_map< int , FastMin > rkm; // each rkm in which index ?
    unordered_map< int , int > idx; // each idx have which number ? 
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        if( idx[ index ] != 0 )
            rkm[ idx[ index ] ].erase( index );
            
        rkm[ number ].insert( index );
        idx[ index ] = number;
    }
    
    int find(int number) {
        return rkm[number].getMin();
    }
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */