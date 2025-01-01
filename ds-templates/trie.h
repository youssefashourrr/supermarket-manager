#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Trie {
private:
    struct Node {
        unordered_map<char, Node*> children;
        bool isEndOfWord;

        Node() : isEndOfWord(false) {}
    };

    Node* root;

    // Helper function to recursively collect all words starting from a given node
    void collectWords(Node* node, const string& prefix, vector<string>& results) const {
        if (!node) return;

        // If the node marks the end of a word, add the prefix to results
        if (node->isEndOfWord) {
            results.push_back(prefix);
        }

        // Recur for all children
        for (const auto& pair : node->children) {
            collectWords(pair.second, prefix + pair.first, results);
        }
    }

    // Helper function for deleting a word from the Trie
    bool removeHelper(Node* currentNode, const string& word, int index) {
        if (index == word.size()) {
            if (!currentNode->isEndOfWord) {
                return false;  // Word not found
            }
            currentNode->isEndOfWord = false;
            return currentNode->children.empty();  // Return true if the node can be deleted
        }

        char ch = word[index];
        Node* nextNode = currentNode->children[ch];
        if (!nextNode) {
            return false;  // Word not found
        }

        bool canDeleteCurrentNode = removeHelper(nextNode, word, index + 1);

        // If the child node can be deleted, remove the reference to it
        if (canDeleteCurrentNode) {
            currentNode->children.erase(ch);
            return currentNode->children.empty() && !currentNode->isEndOfWord;
        }

        return false;
    }

public:
    Trie() : root(new Node()) {}

    ~Trie() {
        // Destructor to free memory
        delete root;
    }

    // Insert a word
    void insert(const string& word) {
        Node* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new Node();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    // Search for a word, returns true if found, false otherwise
    bool search(const string& word) const {
        Node* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    // Auto-complete all words starting with a given prefix
    vector<string> autocomplete(const string& prefix) const {
        Node* currentNode = root;
        for (char ch : prefix) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return {};  // No words with the given prefix
            }
            currentNode = currentNode->children[ch];
        }

        // Collect all words with the prefix
        vector<string> results;
        collectWords(currentNode, prefix, results);
        return results;
    }

    // Delete a word from the Trie
    bool remove(const string& word) {
        return removeHelper(root, word, 0);
    }
};