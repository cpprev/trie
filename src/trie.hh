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
     * @return
     */
    bool add_word (std::shared_ptr<t_trie> trie, const std::string& word);

    /**
     * @param trie                  The trie
     * @param word                  The word to remove from the trie
     * @return
     */
    bool remove_word (std::shared_ptr<t_trie> trie, const std::string& word);

    /**
     * @param trie                  The trie
     * @param word                  The word to check in the trie
     * @return
     */
    bool is_word_in_trie (std::shared_ptr<t_trie> trie, const std::string& word);
}