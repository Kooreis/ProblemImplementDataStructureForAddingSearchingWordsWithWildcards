Here is a JavaScript solution using a Trie data structure:

```javascript
class TrieNode {
    constructor() {
        this.children = {};
        this.isEndOfWord = false;
    }
}

class WordDictionary {
    constructor() {
        this.root = new TrieNode();
    }

    addWord(word) {
        let node = this.root;
        for (let char of word) {
            if (!node.children[char]) {
                node.children[char] = new TrieNode();
            }
            node = node.children[char];
        }
        node.isEndOfWord = true;
    }

    search(word) {
        return this.match(word, 0, this.root);
    }

    match(word, index, node) {
        if (index === word.length) {
            return node.isEndOfWord;
        }
        if (word[index] === '.') {
            for (let char in node.children) {
                if (this.match(word, index + 1, node.children[char])) {
                    return true;
                }
            }
            return false;
        } else if (node.children[word[index]]) {
            return this.match(word, index + 1, node.children[word[index]]);
        } else {
            return false;
        }
    }
}

const wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
console.log(wordDictionary.search("pad")); // false
console.log(wordDictionary.search("bad")); // true
console.log(wordDictionary.search(".ad")); // true
console.log(wordDictionary.search("b..")); // true
```

This console application creates a `WordDictionary` object that uses a Trie data structure to store words. The `addWord` method adds a word to the Trie, and the `search` method searches for a word in the Trie, including words with wildcard characters. The `match` method is a helper method used by the `search` method to recursively search for a word in the Trie.