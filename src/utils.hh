#pragma once

#include <string>
#include <algorithm>

namespace utils
{
    /**
     * @param str
     * @return
     */
    std::string to_lowercase (const std::string& str);

    /**
     * @param word
     * @return
     */
    bool is_word_valid (const std::string& word);
}