class Solution {
private:
    int const MAX_N = 10;
    unordered_map< int , vector<string> > happyStrings;
    char c = [&](){

        function<void(string&&)> generateHappyStrings = [&](string &&curr){

            if(!curr.empty()) happyStrings[curr.size()].push_back(curr);

            if(curr.size() >= MAX_N)
                return;
            
            for(auto &ch : {'a', 'b', 'c'}){
                if(curr.empty() or curr.back() != ch){
                    curr.push_back(ch);
                    generateHappyStrings(move(curr));
                    curr.pop_back();
                }
            }
        };

        generateHappyStrings(string(""));
        return char('_');
    }();
public:
    string getHappyString(int n, int k) {
        if( k > happyStrings[n].size() )
            return ""s;
        return happyStrings[n][k - 1];
    }
};