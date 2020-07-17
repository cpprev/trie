#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <csignal>

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

    /**
     * @param s
     */
    void SIGINT_handler (int s);
}