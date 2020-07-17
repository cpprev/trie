#include "utils.hh"

namespace utils
{
    std::string to_lowercase (const std::string& str)
    {
        std::string word = str;
        std::for_each(word.begin(), word.end(), [](char & c){
            c = std::tolower(c);
        });
        return word;
    }

    bool is_word_valid (const std::string& word)
    {
        for (int i = 0; word[i]; ++i)
        {
            if ((word[i] < 'A' or word[i] > 'Z') and (word[i] < 'a' or word[i] > 'z'))
                return false;
        }
        return true;
    }


    void SIGINT_handler (int s)
    {
        if (s == SIGINT)
        {
            std::cout << "\n" << "\033[1;34m" << "Quitting ..." << "\033[0m" << "\n";
            exit(0);
        }
    }
}