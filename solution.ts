Here is a TypeScript solution using a Trie data structure:

```typescript
class TrieNode {
    children: { [key: string]: TrieNode };
    isEndOfWord: boolean;

    constructor() {
        this.children = {};
        this.isEndOfWord = false;
    }
}

class WordDictionary {
    root: TrieNode;

    constructor() {
        this.root = new TrieNode();
    }

    addWord(word: string): void {
        let node = this.root;
        for (let i = 0; i < word.length; i++) {
            if (!node.children[word[i]]) {
                node.children[word[i]] = new TrieNode();
            }
            node = node.children[word[i]];
        }
        node.isEndOfWord = true;
    }

    search(word: string): boolean {
        return this.searchFromNode(word, 0, this.root);
    }

    private searchFromNode(word: string, index: number, node: TrieNode): boolean {
        if (index === word.length) {
            return node.isEndOfWord;
        }

        if (word[index] === '.') {
            for (let key in node.children) {
                if (this.searchFromNode(word, index + 1, node.children[key])) {
                    return true;
                }
            }
            return false;
        } else if (node.children[word[index]]) {
            return this.searchFromNode(word, index + 1, node.children[word[index]]);
        } else {
            return false;
        }
    }
}

let wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
console.log(wordDictionary.search("pad")); // false
console.log(wordDictionary.search("bad")); // true
console.log(wordDictionary.search(".ad")); // true
console.log(wordDictionary.search("b..")); // true
```

This solution uses a Trie data structure to store the words. Each node in the Trie represents a character in a word. The `addWord` method adds a word to the Trie. The `search` method searches for a word in the Trie, including words with wildcard characters. The `searchFromNode` method is a helper method that performs a depth-first search from a given node.