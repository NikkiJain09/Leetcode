/*
* Problem: 720. Longest Word in Dictionary
* Link: https://leetcode.com/problems/longest-word-in-dictionary/
*/
class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
    ~TrieNode()
    {
        for(auto &c : children)
            delete c.second;
    }
    
    void insert(string s)
    {
        TrieNode *curr = this;
        for(int i=0; i<s.length(); i++)
        {
            if(curr && curr->children.find(s[i]) == curr->children.end())
                curr->children[s[i]] = new TrieNode();
            curr = curr->children[s[i]];
        }
        if(curr)
            curr->isEnd = true;
    }
    
    bool search(string s)
    {
        int count = 0;
        TrieNode *curr = this;

        for(int i=0; i<s.length(); i++)
        {
            if(curr && curr->children.find(s[i]) != curr->children.end())
            {
                if(!curr->children[s[i]]->isEnd)
                    break;    
                count++;
                curr = curr->children[s[i]];
            }
            else
                return false;
        }
        
        if(curr && curr->isEnd && (count == s.length()))
            return true;
        else
            return false;
    }
};

class Solution {
private:
    TrieNode * root;
public:
    string longestWord(vector<string>& words) {
        if(words.size() == 0)
            return "";
        
        TrieNode *root = new TrieNode();
        for(auto &w :  words)
            root->insert(w);
        
        vector<string> res;
        for(auto &w: words)
        {
            if(root->search(w))
                res.push_back(w);
        }
        
        if(res.size() < 2)
            return words[0];
        
        string maxS="";
        int maxLen = 0;
        
        for(auto &w: res)
        {
            if(maxLen < w.length())
            {
                maxLen = w.length();
                maxS = w;
            }
            else if(maxLen == w.length())
                maxS = maxS < w ? maxS : w;
        }
        
        return maxS;
    }
};