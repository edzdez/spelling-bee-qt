#include "testtrie.h"

#include "trie.h"

void TestTrie::addAndContains()
{
    lib::Trie trie;
    QVERIFY(trie.contains("fire") == false);
    trie.addWord("fire");
    QVERIFY(trie.contains("fire") == true);
}

QTEST_MAIN(TestTrie)