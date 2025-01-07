class Solution {
private:

class suffix_automaton {
private:
    struct state {
        map<int, int> nxt;
        int link = -1;
        int len{};
    };
    int lst;
    vector<state> tr;
    char cnt = 'z' + 1;

    void add(int c) {
        int curr = int(tr.size());
        tr.emplace_back();
        tr[curr].len = tr[lst].len + 1;
        int p = lst;
        while(~p && !tr[p].nxt.count(c)) {
            tr[p].nxt[c] = curr;
            p = tr[p].link;
        }
        if(p == -1) {
            tr[curr].link = 0;
        }
        else {
            int q = tr[p].nxt[c];
            if(tr[p].len + 1 == tr[q].len) {
                tr[curr].link = q;
            }
            else {
                int clone = int(tr.size());
                tr.emplace_back();
                tr[clone] = tr[q];
                tr[clone].len = tr[p].len + 1;
                while(~p && tr[p].nxt[c] == q) {
                    tr[p].nxt[c] = clone;
                    p = tr[p].link;
                }
                tr[curr].link = tr[q].link = clone;
            }
        }
        lst = curr;
    }
public:
    explicit suffix_automaton() : tr(1), lst(0) { }

    void add(string &s){
        for(auto &ch : s){
            add(ch);
        }
        add(cnt++);
    }

    bool found(string &s) {
        int i = 0;
        for(char c : s) {
            if(!tr[i].nxt.count(c)) return false;
            i = tr[i].nxt[c];
        }
        return true;
    }
};

public:
    vector<string> stringMatching(vector<string>& words) {
        suffix_automaton automaton;
        
        sort(words.begin(), words.end(), [&](auto &a, auto &b){
            return a.size() > b.size();
        });

        vector< string > ans;ans.reserve(words.size());

        for(auto &it : words){
            if(automaton.found(it)){
                ans.push_back(it);
            }
            automaton.add(it);
        }

        return ans;

        return ans;
        
    }
};