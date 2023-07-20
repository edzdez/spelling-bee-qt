#include "testtrie.h"

#include "trie.h"

void TestTrie::addAndContains()
{
    lib::Trie trie;
    QVERIFY(trie.containsWord("fire") == false);
    trie.addWord("fire");
    QVERIFY(trie.containsWord("fire") == true);
}

QTEST_MAIN(TestTrie)