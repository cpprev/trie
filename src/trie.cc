#include "trie.hh"

namespace trie
{
    t_trie::t_trie()
    {
        word = false;
        occ = 0;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }

    bool add_word (std::shared_ptr<t_trie> trie, const std::string& word)
    {
        /// Put word to lowercase only
        std::string word_to_add = utils::to_lowercase(word);

        for (int i = 0; word_to_add[i]; ++i)
        {
            char c = word_to_add[i];
            if (not trie->children[c - 'a'])
                trie->children[c - 'a'] = std::make_shared<t_trie>();
            trie->children[c - 'a']->occ++;

            if (not word_to_add[i + 1])
                trie->children[c - 'a']->word = true;
            trie = trie->children[c - 'a'];
        }
        return true;
    }

    bool remove_word (std::shared_ptr<t_trie> trie, const std::string& word)
    {
        /// Put word to lowercase only
        std::string word_to_remove = utils::to_lowercase(word);

        if (not is_word_in_trie(trie, word_to_remove))
            return false;
        for (int i = 0; word_to_remove[i]; ++i)
        {
            char c = word_to_remove[i];
            trie->children[c - 'a']->occ--;
            if (trie->children[c - 'a']->occ == 0)
            {
                trie->children[c - 'a'] = nullptr;
                return true;
            }
            if (not word_to_remove[i + 1] and trie->children[c - 'a']->word)
                trie->children[c - 'a']->word = false;
            trie = trie->children[c - 'a'];
        }
        return true;
    }

    bool is_word_in_trie (std::shared_ptr<t_trie> trie, const std::string& word)
    {
        /// Put word to lowercase only
        std::string word_to_check = utils::to_lowercase(word);

        for (int i = 0; word_to_check[i]; ++i)
        {
            char c = word_to_check[i];
            if (not trie->children[c - 'a'])
                return false;
            if (not word_to_check[i + 1] and trie->children[c - 'a']->word)
                return true;
            trie = trie->children[c - 'a'];
        }
        return false;
    }
}