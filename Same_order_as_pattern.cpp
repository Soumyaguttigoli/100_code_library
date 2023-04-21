#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
 
// Function to print all words that follows the same order of
// characters as the given pattern
void patternMatch(vector<string> const &words, string pattern)
{
    // invalid input
    int n = words.size();
    if (n == 0) {
        return;
    }
 
    // `len` stores the length of the pattern
    int len = pattern.length();
 
    // check each word in the input list
    for (string word: words)
    {
        // `map1` stores the mapping from word to the pattern
        // `map2` stores the mapping from pattern to word
        unordered_map<char, char> map1, map2;
 
        // proceed only when the length of the pattern and word is the same
        if (word.length() == len)
        {
            int i;
 
            // process each character in both word and pattern
            for (i = 0; i < len; i++)
            {
                // `w` stores the current character of the current word
                char w = word[i];
 
                // `p` stores the current character of the pattern
                char p = pattern[i];
 
                /* Check mapping from the current word to the given pattern */
 
                // if `w` is seen for the first time, store its mapping
                // to `p` in `map1`
                if (map1.find(w) == map1.end()) {
                    map1[w] = p;
                }
 
                // if `w` is seen before, its mapped character should be `p`
                else if (map1[w] != p) {
                    break;
                }
 
                /* Check mapping from the given pattern to the current word */
 
                // if `p` is seen for the first time, store its mapping to
                // `w` in `map2`
                if (map2.find(p) == map2.end()) {
                    map2[p] = w;
                }
 
                // if `p` is seen before, its mapped character should be `w`
                else if (map2[p] != w) {
                    break;
                }
            }
 
            // if the current word matches the pattern, print it
            if (i == len) {
                cout << word << " ";
            }
        }
    }
}
 
int main()
{
    // list of words
    vector<string> list =
    {
        "leet", "abcd", "loot", "geek", "cool", "for", "peer",
        "dear", "seed", "meet", "noon", "otto", "mess", "loss"
    };
 
    // given pattern
    string pattern = "moon";
 
    patternMatch(list, pattern);
 
    return 0;
}