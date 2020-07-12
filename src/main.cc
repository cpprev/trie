#include <iostream>

#include "trie.hh"

int main ()
{
    std::shared_ptr<trie::t_trie> trie = std::make_shared<trie::t_trie>();

    trie::add_word(trie, "abC");
    trie::add_word(trie, "abcdef");
    bool e = trie::is_word_in_trie(trie, "abcdef");
    trie::remove_word(trie, "abcdef");
    e = trie::is_word_in_trie(trie, "abc");
    std::cout << (e ? "YES" : "NO") << "\n";
    return 0;
}