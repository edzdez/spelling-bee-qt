#ifndef SPELLING_BEE_QT_WORDVALIDATOR_H
#define SPELLING_BEE_QT_WORDVALIDATOR_H

#include "trie.h"
#include <QObject>

namespace lib
{

class WordValidator : public QObject
{
    Q_OBJECT
  public:
    explicit WordValidator(int minLength = 4);
    bool isValid(const QString &word);
    bool inWordList(const QString &word, const Trie &wordlist);

    int minLength = 4;
};

} // namespace lib

#endif // SPELLING_BEE_QT_WORDVALIDATOR_H
