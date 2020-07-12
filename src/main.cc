#include <iostream>

#include "trie.hh"

int main ()
{
    std::shared_ptr<trie::t_trie> trie = std::make_shared<trie::t_trie>();

    trie::add_word(trie, "elephant");
    trie::add_word(trie, "thomas");
    trie::add_word(trie, "azza");
    trie::add_word(trie, "zazaz");
    trie::add_word(trie, "xddd");
    trie::add_word(trie, "peruche");
    trie::add_word(trie, "charlmes");
    trie::add_word(trie, "bonsoir");

    bool e = trie::is_word_in_trie(trie, "abcdef");
    //trie::remove_word(trie, "abcdef");
    e = trie::is_word_in_trie(trie, "abc");
    std::cout << (e ? "YES" : "NO") << "\n";

    for (auto word : trie::list_words_in_trie(trie))
        std::cout << word << std::endl;
    return 0;
}