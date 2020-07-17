#include <iostream>
#include <fnmatch.h>
#include <csignal>

#include "utils.hh"
#include "trie.hh"

int main ()
{
    std::cout << "\033[1;34m" << "Launching ..." << "\033[0m" << "\n";

    // Handle SIGINTs (Ctrl+C)
    struct sigaction si;
    si.sa_handler = utils::SIGINT_handler;
    si.sa_flags = SA_NODEFER;
    sigaction(SIGINT, &si, 0);

    std::shared_ptr<trie::t_trie> trie = std::make_shared<trie::t_trie>();
    while (true)
    {
        std::string operation;
        std::getline (std::cin, operation);
        if (operation == "q" or operation == "quit" or operation == "stop")
        {
            std::cout << "\033[1;34m" << "Quitting ..." << "\033[0m" << "\n";
            break;
        }
        if (not fnmatch("add*", operation.c_str(), 0))
        {
            if (operation.size() <= 3 or operation[3] != ' ')
            {
                std::cout << "\033[1;31m" << "[Input Error] You have to give a word to add." << "\033[0m" << "\n";
                continue;
            }
            std::string input_words = operation.substr(4);
            std::vector<std::string> words = utils::cut_csv(input_words);
            for (const auto& word_to_add : words)
            {
                if (not utils::is_word_valid(word_to_add))
                {
                    std::cout << "\033[1;31m"
                              << "[Input Error] Word is not valid, it has to consits of letters from the alphabet."
                              << "\033[0m" << "\n";
                    continue;
                }
                /// Adding word to the trie
                trie::add_word(trie, word_to_add);
                std::cout << "\033[1;32m" << "\'" << word_to_add << "\' has been successfully added to the Trie."
                          << "\033[0m" << "\n";
            }
        }
        else if (not fnmatch("check*", operation.c_str(), 0))
        {
            if (operation.size() <= 5 or operation[5] != ' ')
            {
                std::cout << "\033[1;31m" << "[Input Error] You have to give a word to check." << "\033[0m" << "\n";
                continue;
            }
            std::string input_words = operation.substr(6);
            std::vector<std::string> words = utils::cut_csv(input_words);
            for (const auto& word_to_check : words)
            {
                if (not trie::is_word_in_trie(trie, word_to_check))
                    std::cout << "\033[1;32m" << "\'" << word_to_check << "\' " << "\033[1;31m" << "IS NOT"
                              << "\033[1;32m" << " present in the Trie." << "\033[0m" << "\n";
                else
                    std::cout << "\033[1;32m" << "\'" << word_to_check << "\' IS present in the Trie." << "\033[0m" <<  "\n";
            }
        }
        else if (not fnmatch("rm*", operation.c_str(), 0))
        {
            if (operation.size() <= 2 or operation[2] != ' ')
            {
                std::cout << "\033[1;31m" << "[Input Error] You have to give a word to remove." << "\033[0m" << "\n";
                continue;
            }
            std::string input_words = operation.substr(3);
            std::vector<std::string> words = utils::cut_csv(input_words);
            for (const auto& word_to_rm : words)
            {
                if (not utils::is_word_valid(word_to_rm))
                {
                    std::cout << "\033[1;31m"
                              << "[Input Error] Word is not valid, it has to consits of letters from the alphabet."
                              << "\033[0m" << "\n";
                    continue;
                }
                if (not trie::is_word_in_trie(trie, word_to_rm))
                {
                    std::cout << "\033[1;31m" << "[Runtime Error] Word : \'" << word_to_rm
                              << "\' was not found in the Trie." << "\033[0m" << "\n";
                    continue;
                }
                /// Removing word from the trie
                trie::remove_word(trie, word_to_rm);
                std::cout << "\033[1;32m" << "\'" << word_to_rm << "\' has been successfully removed from the Trie."
                          << "\033[0m" << "\n";
            }
        }
        else if (operation == "list")
        {
            std::cout << "\033[1;33m" << "The current words stored in the tree are :" << "\033[0m" << "\n";
            int i = 1;
            for (const auto& word : trie::list_words_in_trie(trie))
            {
                std::cout << "\033[1;35m" << "[" << i << "] " << word << "\033[0m" << "\n";
                ++i;
            }
        }
        else if (not fnmatch("auto*", operation.c_str(), 0))
        {
            if (operation.size() <= 4 or operation[4] != ' ')
            {
                std::cout << "\033[1;31m" << "[Input Error] You have to give a word to remove." << "\033[0m" << "\n";
                continue;
            }
            std::string word_to_complete = operation.substr(5);
            std::cout << "\033[1;33m" << "The current words resulting from the autocompletion of \'" << word_to_complete << "\' are :" << "\033[0m" << "\n";
            int i = 1;
            for (const auto& word : trie::autocomplete(trie, word_to_complete))
            {
                std::cout << "\033[1;35m" << "[" << i << "] " << word << "\033[0m" << "\n";
                ++i;
            }
        }
        else
        {
            std::cout << "\033[1;31m" << "[Input Error] Unknown command" << "\033[0m" << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}