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
    trie::add_word(trie, "bonsoirmeme");
    trie::add_word(trie, "bonsoirzeaz");


    bool e = trie::is_word_in_trie(trie, "abcdef");
    trie::remove_word(trie, "bonsoir");
    e = trie::is_word_in_trie(trie, "abc");
    std::cout << (e ? "YES" : "NO") << "\n";

    for (auto word : trie::list_words_in_trie(trie))
        std::cout << "word: " << word << std::endl;
    std::cout << std::endl;
    for (auto word : trie::autocomplete(trie, "bonsoir"))
        std::cout << "auto: " << word << std::endl;
    return 0;
}