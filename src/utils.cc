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
}