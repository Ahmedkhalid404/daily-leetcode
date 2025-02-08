class NumberContainers {
public:
    unordered_map< int , set< int > > rkm; // each rkm in which index ?
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
        if( rkm[number].empty() ){
            return -1;
        }
        
        return *rkm[number].begin();
    }
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */