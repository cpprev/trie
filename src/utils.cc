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

    bool is_whitespace (char c)
    {
        return c == ' ' or c == '\t';
    }

    void rm_trailing_whitespaces(std::string& str)
    {
        int len = str.size();
        int start;
        for (start = 0; start < len and is_whitespace(str[start]); ++start) {}
        int end;
        for (end = len - 1; end >= 0 and is_whitespace(str[end]); --end) {}

        std::string res;
        for (int s = start; s <= end; ++s)
        {
            res += str[s];
        }
        str = res;
    }

    std::vector<std::string> cut_csv (const std::string& str)
    {
        std::vector<std::string> res;
        std::string temp;
        for (size_t i = 0; i < str.size(); ++i)
        {
            if ((str[i] == ',' or i == str.size() - 1))
            {
                if (not (str[i] == ',' and i == str.size() - 1))
                {
                    if (i == str.size() - 1)
                        temp += str[i];
                }
                rm_trailing_whitespaces(temp);
                res.push_back(temp);
                temp = "";
            }
            else
            {
                temp += str[i];
            }
        }
        return res;
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