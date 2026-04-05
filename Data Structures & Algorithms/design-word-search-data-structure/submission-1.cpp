class TrieNode{
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;
        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(TrieNode* child : cur->children){
                    if(child != nullptr && dfs(word, i + 1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                int k = c - 'a';
                if (cur->children[k] == nullptr){
                    return false;
                }
                cur = cur->children[k];
            }
        }
        return cur->word;
    }
};
