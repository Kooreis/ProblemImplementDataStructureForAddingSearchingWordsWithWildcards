# Question: How do you implement a data structure to add and search for words, including wildcard characters? JavaScript Summary

The JavaScript code provided implements a data structure called a Trie, which is used to add and search for words, including those with wildcard characters. The code defines two classes: `TrieNode` and `WordDictionary`. The `TrieNode` class represents a node in the Trie, containing a dictionary of its children and a boolean indicating whether it is the end of a word. The `WordDictionary` class represents the Trie itself, with methods to add words and search for words. The `addWord` method iteratively adds each character of a word to the Trie, creating new nodes as necessary. The `search` method uses a helper method, `match`, to recursively search for a word in the Trie. If a wildcard character is encountered, the `match` method will search all child nodes. The code then demonstrates adding words to the Trie and searching for words, including those with wildcard characters. The search results are then logged to the console.

---

# TypeScript Differences

The TypeScript version of the solution is very similar to the JavaScript version, but with the addition of static typing. This means that the TypeScript version provides type safety, which can help prevent certain types of bugs and improve the development experience with features like autocompletion and compile-time error checking.

Here are the differences:

1. Type Annotations: In TypeScript, we can see type annotations for variables and function return types. For example, in the `addWord` method, `word` is annotated as a `string`, and the method is annotated to return `void`. This makes the code more self-documenting and can help catch type-related bugs.

2. Class Properties: In the TypeScript version, the `TrieNode` and `WordDictionary` classes explicitly declare their properties at the top of the class, along with their types. This is not required in JavaScript, but it provides a clear overview of the class's properties and their types.

3. Private Method: The `searchFromNode` method is marked as `private` in the TypeScript version, which means it can't be accessed outside of the `WordDictionary` class. This is a feature not available in JavaScript, and it helps encapsulate the internal workings of the class.

4. For Loop: In the `addWord` method, the TypeScript version uses a traditional for loop with an index, while the JavaScript version uses a for-of loop to iterate over the characters in the word. This is not a TypeScript-specific feature, but a different way to write the loop.

Overall, the TypeScript version provides the same functionality as the JavaScript version, but with the added benefits of static typing and better encapsulation.

---

# C++ Differences

The C++ version of the solution also uses a Trie data structure to solve the problem, similar to the JavaScript version. However, there are some differences in the language features and methods used in the two versions.

1. Object Creation: In JavaScript, objects are created using the `new` keyword. In C++, objects are created using the `new` keyword as well, but they need to be manually deleted to free up memory. In the C++ version, a `getNode` function is used to create a new TrieNode.

2. Data Structures: Both versions use a map-like data structure to store the children of each node in the Trie. JavaScript uses an object for this purpose, while C++ uses an `unordered_map`.

3. String Iteration: In JavaScript, strings can be iterated over using a `for...of` loop. In C++, strings are iterated over using a traditional `for` loop with an index.

4. Map Access: In JavaScript, map elements are accessed using bracket notation. In C++, map elements are accessed using the same bracket notation, but the `find` method is used to check if an element exists in the map.

5. Wildcard Character: The JavaScript version uses the '.' character as the wildcard character, while the C++ version uses the '*' character.

6. Search Function: The JavaScript version uses a recursive `match` function to implement the search functionality, including wildcard search. The C++ version uses a separate `wildcardSearch` function for wildcard search, in addition to the `search` function for normal search.

7. Output: The JavaScript version logs output to the console using `console.log`, while the C++ version prints output to the console using `cout`.

8. Main Function: The C++ version has a `main` function, which is the entry point of the program. The JavaScript version doesn't have a `main` function, as JavaScript code is executed from top to bottom.

---
