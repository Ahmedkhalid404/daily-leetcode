class Solution {
public:
    bool canBeValid(string s, string locked) {
        int size = int(s.size());
        if( size & 1 ){
            return false;
        }

        stack< int > open, unlocked;
        for (int i = 0; i < size; ++i) {
            char &ch = s[i];
            if( locked[i] == '0' ){
                unlocked.push(i);
            }
            else if(ch == '('){
                open.push(i);
            }
            else if(ch == ')'){

                if( !open.empty() ){
                    open.pop();
                }
                else{
                    if( !unlocked.empty() ){
                        unlocked.pop();
                    }
                    else{
                        return false;
                    }
                }

            }
        }

        while( ( !open.empty() ) && ( !unlocked.empty() ) && (open.top() < unlocked.top()) )
            open.pop(), unlocked.pop();

        return open.empty();
    }
};