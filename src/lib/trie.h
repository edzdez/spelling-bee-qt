#ifndef SPELLING_BEE_QT_TRIE_H
#define SPELLING_BEE_QT_TRIE_H

#include <QMap>
#include <QObject>

namespace lib
{
class Trie : public QObject
{
    Q_OBJECT
  public:
    explicit Trie(QObject *parent = nullptr);
    ~Trie() override = default;

    void addWord(const QString &word);
    [[nodiscard]] bool containsWord(const QString &word) const;

  private:
    struct TrieNode
    {
        QChar c;
        bool terminal{false};
        QMap<QChar, TrieNode> children;
    };

    TrieNode m_root;
};
} // namespace lib

#endif // SPELLING_BEE_QT_TRIE_H
