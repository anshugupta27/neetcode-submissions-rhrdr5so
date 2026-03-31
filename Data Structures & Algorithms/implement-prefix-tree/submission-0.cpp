struct Node {
    Node* link[26];
    bool flag = false;

    Node() {
        for (int i = 0 ; i < 26 ; i++) link[i] = nullptr;
    }
};

class PrefixTree {
    Node *root;

public:

    PrefixTree() {
    root = new Node();
    }
    
    void insert(string word) {
        Node *tempPtr = root;
        for (int i = 0 ; i < word.length() ; i++) {
            if (tempPtr -> link[word[i]-'a'] != nullptr) 
              tempPtr = tempPtr -> link[word[i]-'a'];
            else {
                Node *newNode = new Node();
                tempPtr -> link[word[i]-'a'] = newNode;
                tempPtr = newNode;
            }
        }
        tempPtr -> flag = true;
        
    }
    
    bool search(string word) {
        Node *tempPtr = root;
        for (int i = 0 ; i < word.length() ; i++) {
            if (tempPtr -> link [word[i]-'a'] == nullptr) return false;
            tempPtr = tempPtr -> link[word[i]-'a'];
        }
        return tempPtr -> flag;
        
    }
    
    bool startsWith(string prefix) {
        Node *tempPtr = root;
        for (int i = 0 ; i < prefix.size() ; i++) {
            if (tempPtr -> link[prefix[i]-'a'] == nullptr) return false;
            tempPtr = tempPtr -> link[prefix[i]-'a'];
        }
        return true;
        
    }
};
