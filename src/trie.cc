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

    void list_words_in_tree_rec (std::shared_ptr<t_trie> trie, std::vector<std::string>& words, std::string& cur)
    {
        if (trie == nullptr)
            return;
        else if (trie->word)
            words.push_back(cur);

        for (int i = 0; i < 26; ++i)
        {
            if (trie->children[i])
            {
                std::string t(1, i + 'a');
                std::string n = cur + t;
                list_words_in_tree_rec(trie->children[i], words, n);
            }
        }
    }

    std::vector<std::string> list_words_in_trie (std::shared_ptr<t_trie> trie)
    {
        std::vector<std::string> words;
        std::string cur;
        list_words_in_tree_rec(trie, words, cur);
        return words;
    }

    std::vector<std::string> autocomplete (std::shared_ptr<t_trie> trie, const std::string& word)
    {
        /// Put word to lowercase only
        std::string word_to_complete = utils::to_lowercase(word);

        /// This will be the starting position for the call to 'list_words_in_trie'
        /// after having found 'word' beforehand.
        std::shared_ptr<t_trie> start;
        for (int i = 0; word_to_complete[i]; ++i)
        {
            char c = word_to_complete[i];
            if (not trie->children[c - 'a'])
                return {};
            if (not word_to_complete[i + 1])
            {
                start = trie->children[c - 'a'];
                break;
            }
            trie = trie->children[c - 'a'];
        }
        /// Get all the words of the trie (that starts at the end of 'word')
        std::vector<std::string> words = list_words_in_trie(start);
        /// Adds the prefix ('word')
        size_t len = words.size();
        for (size_t i = 0; i < len; ++i)
            words[i] = word + words[i];
        return words;
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