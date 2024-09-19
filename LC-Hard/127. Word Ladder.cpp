// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end()),vis;
        if(st.find(endWord)==st.end())    return 0;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int cnt = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0;k<sz;k++){
                string rt = q.front();q.pop();
                if(rt==endWord) return cnt;
                for(int i=0;i<rt.size();i++){
                    for(char ch='a';ch<='z';ch++){
                        string cp = rt;
                        cp[i] = ch;
                        if(st.find(cp)!=st.end() && vis.find(cp)==vis.end()){
                            q.push(cp);
                            vis.insert(cp);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};