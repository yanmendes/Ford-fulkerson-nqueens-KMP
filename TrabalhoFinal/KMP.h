#ifndef KMP_H_INCLUDED
#define KMP_H_INCLUDED

#include<string>

int KMP_search(std::string const& text, std::string const& pattern);
void process_LPS(std::string const& pattern, int *lps);

#endif // KMP_H_INCLUDED
