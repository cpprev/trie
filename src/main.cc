#include <iostream>
#include <fnmatch.h>

#include "utils.hh"
#include "trie.hh"

int main ()
{
    std::shared_ptr<trie::t_trie> trie = std::make_shared<trie::t_trie>();
    while (true)
    {
        std::string operation;
        std::getline (std::cin, operation);
        if (operation == "q" or operation == "quit" or operation == "stop")
        {
            std::cout << "Quitting\n";
            break;
        }
        if (not fnmatch("add *", operation.c_str(), 0))
        {
            if (operation.size() <= 3)
            {
                std::cout << "[Input Error] You have to give a word to add.\n";
                continue;
            }
            std::string word_to_add = operation.substr(4);
            if (not utils::is_word_valid(word_to_add))
            {
                std::cout << "[Input Error] Word is not valid, it has to consits of letters from the alphabet.\n";
                continue;
            }
            /// Adding word to the trie
            trie::add_word(trie, word_to_add);
            std::cout << "Word : \'" << word_to_add << "\' has been added to the Trie." << "\n";
        }
        else if (not fnmatch("rm *", operation.c_str(), 0))
        {
            if (operation.size() <= 2)
            {
                std::cout << "[Input Error] You have to give a word to remove.\n";
                continue;
            }
            std::string word_to_rm = operation.substr(3);
            if (not utils::is_word_valid(word_to_rm))
            {
                std::cout << "[Input Error] Word is not valid, it has to consits of letters from the alphabet.\n";
                continue;
            }
            if (not trie::is_word_in_trie(trie, word_to_rm))
            {
                std::cout << "[Runtime Error] Word : \'" << word_to_rm << "\' was not found in the Trie." << "\n";
                continue;
            }
            /// Removing word from the trie
            trie::remove_word(trie, word_to_rm);
            std::cout << "Word : \'" << word_to_rm << "\' has been removed from the Trie." << "\n";
        }
        else if (operation == "list")
        {
            std::cout << "The current words stored in the tree are :\n";
            int i = 1;
            for (auto word : trie::list_words_in_trie(trie))
            {
                std::cout << "[" << i << "] " << word << std::endl;
                ++i;
            }
        }
        else if (not fnmatch("auto *", operation.c_str(), 0))
        {
            if (operation.size() <= 4)
            {
                std::cout << "[Input Error] You have to give a word to remove.\n";
                continue;
            }
            std::string word_to_complete = operation.substr(5);
            std::cout << "The current words resulting from the autocompletion of \'" << word_to_complete << "\' are :\n";
            int i = 1;
            for (auto word : trie::autocomplete(trie, word_to_complete))
            {
                std::cout << "[" << i << "] " << word << std::endl;
                ++i;
            }
        }
    }

    return 0;
}