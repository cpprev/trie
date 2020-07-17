### Implementation of the data structure "Trie"

    The following features are implemented :
    - Addition of a word in the trie
    - Deletion of a word from the trie
    - Checking if a word is in the trie
    - Listing of all the words stored in the trie
    - Autocompletion of a word
    
### How to build it ?

    mkdir build && cd build && cmake .. && make -j10  
  
### How to use it ?

    To launch the interactive mode :
    ./trie
    
###
    
    Once the interactive mode is launched, the following commands are available :
    
    "add WORD(S)_TO_ADD"                   [Adds a word to the trie]
    Example : "add word", "add word1, word2, word3"
    
    "check WORD(S)_TO_CHECK"               [Checks if a word is present in the trie]
    Example : "check word", "check word1, word2, word3"

    "rm WORD(S)_TO_REMOVE"                 [Deletes a word from the trie]
    Example : "rm word", "rm word1, word2, word3"

    "auto WORD_TO_AUTOCOMPLETE"         [Autocompletes a word and lists the results]
    Example : "auto word"

    "list"                              [Lists the words currently stored in the trie]