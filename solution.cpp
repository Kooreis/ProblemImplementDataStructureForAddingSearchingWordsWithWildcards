```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    return node;
}

void insert(TrieNode* root, string key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        if (pCrawl->children.find(key[i]) == pCrawl->children.end())
            pCrawl->children[key[i]] = getNode();
        pCrawl = pCrawl->children[key[i]];
    }
    pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        if (pCrawl->children.find(key[i]) == pCrawl->children.end())
            return false;
        pCrawl = pCrawl->children[key[i]];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

bool wildcardSearch(TrieNode* root, string key, int index = 0) {
    if (index == key.size())
        return (root != NULL && root->isEndOfWord);
    if (key[index] != '*')
        return (root != NULL && root->children.find(key[index]) != root->children.end() && wildcardSearch(root->children[key[index]], key, index + 1));
    for (auto it : root->children)
        if (wildcardSearch(it.second, key, index + 1))
            return true;
    return false;
}

int main() {
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);
    TrieNode* root = getNode();
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    cout << wildcardSearch(root, "the") << "\n";
    cout << wildcardSearch(root, "a") << "\n";
    cout << wildcardSearch(root, "there") << "\n";
    cout << wildcardSearch(root, "ans*er") << "\n";
    cout << wildcardSearch(root, "any") << "\n";
    cout << wildcardSearch(root, "by") << "\n";
    cout << wildcardSearch(root, "bye") << "\n";
    cout << wildcardSearch(root, "their") << "\n";
    cout << wildcardSearch(root, "*e") << "\n";
    return 0;
}
```