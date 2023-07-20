#include "wordvalidator.h"

lib::WordValidator::WordValidator(int minLength)
    : minLength(minLength)
{
}

/**
 * Check if a word is valid.
 * That is, if it is made up of all lowercase letters and if it is longer than the minimum length
 * @param word
 * @return whether word is valid
 */
bool lib::WordValidator::isValid(const QString &word)
{
    for (const auto &c : word)
    {
        if (!(c.isLetter() && c.isLower()))
            return false;
    }
    return minLength <= word.length();
}

/**
 * Check if a word is in the wordlist
 * @param word
 * @param wordlist
 * @return whether word is in wordlist
 */
bool lib::WordValidator::inWordList(const QString &word, const lib::Trie &wordlist)
{
    if (isValid(word))
        return wordlist.contains(word);
    return false;
}
