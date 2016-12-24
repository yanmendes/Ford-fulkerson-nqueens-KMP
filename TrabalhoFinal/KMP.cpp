#include "KMP.h"

int KMP_search(std::string const& text, std::string const& pattern)
{
    unsigned int n = text.size(),
        m = pattern.size(),
        count = 0,
        i = 0,
        j = 0;
    int *lps;

    lps = new int[m];

    process_LPS(pattern, lps);

    while (i < n)
    {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;

            if (m == j)
            {
                j = lps[j - 1];
                ++count;
            }
        }
        else if (j != 0)
            j = lps[j - 1];
        else
            ++i;
    }

    return count;
}

void process_LPS(std::string const& pattern, int *lps)
{
    unsigned int m = pattern.size();
    unsigned int i = 1,
        prev_lps_len = 0;
    lps[0] = 0;

    while (i < m)
    {
        if (pattern[prev_lps_len] == pattern[i])
            lps[i++] = ++prev_lps_len;
        else if (prev_lps_len != 0)
            prev_lps_len = lps[prev_lps_len - 1];
        else
            lps[i++] = 0;
    }
}
