#include "trie.h"

lib::Trie::Trie(QObject *parent)
    : QObject(parent)
{
}

/**
 * Adds a word to trie
 * Precondition: word is nonempty and all lowercase
 * @param word
 */
void lib::Trie::addWord(const QString &word)
{
    TrieNode *curr = &m_root;
    for (const auto &c : word)
    {
        TrieNode *next = &(curr->children[c]);
        next->c = c;
        curr = next;
    }

    curr->terminal = true;
}

/**
 * Checks if word is contained in trie
 * Precondition: word is nonempty and all lowercase
 * @param word
 * @return whether word is in trie
 */
bool lib::Trie::contains(const QString &word) const
{
    const TrieNode *curr = &m_root;
    for (const auto &c : word)
    {
        const auto next = curr->children.constFind(c);
        if (next == curr->children.constEnd())
            return false;
        curr = &(*next);
    }

    return curr->terminal;
}
