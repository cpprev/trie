#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <optional>

#include "utils.hh"

namespace trie
{
    struct t_trie
    {
        /**
        * @brief                    Trie node constructor
        */
        t_trie();

        /// Attributes
        std::shared_ptr<t_trie> children[26];
        bool word;
        int occ;
    };

    /**
     * @param trie                  The trie
     * @param word                  The word to add to the trie
     * @return                      True if 'word' was added in the trie, False else
     */
    bool add_word (std::shared_ptr<t_trie> trie, const std::string& word);

    /**
     * @param trie                  The trie
     * @param word                  The word to remove from the trie
     * @return                      True if 'word' was deleted from the trie, False else
     */
    bool remove_word (std::shared_ptr<t_trie> trie, const std::string& word);

    /**
     * @param trie                  The trie
     * @param word                  The word to check in the trie
     * @return                      True if 'word' is in the trie, False else
     */
    bool is_word_in_trie (std::shared_ptr<t_trie> trie, const std::string& word);

    /**
     * @param trie                  The trie
     * @return                      Vector of words in the trie
     */
    std::vector<std::string> list_words_in_trie (std::shared_ptr<t_trie> trie);
}