#pragma once
#include <algorithm>
#include <codecvt>
#include <iostream>
#include <locale>
#include <sstream>
#include <set>
#include <vector>

using stringvector = std::vector<std::string>;
using wstringvector = std::vector<std::wstring>;
using wcharset = std::set<std::wstring>;

class BraillePrinting
{
public:
    // constructor and destructor
    BraillePrinting();
    ~BraillePrinting();

    // function has to be public so it can be called from an object inside main()
    void print_braille();
    std::string print_braille_to_string();

    std::string read_rawest_userinput();

private:
    // containers holding the user input in ascending order of processing levels
    // only the 2d vector has to be permanently stored, the other attributes are there for expansion/continuation purposes.
    std::string rawest_userinput;
    stringvector raw_userinput;
    wstringvector wide_userinput;
    std::vector<int> wordsizes;
    std::vector<wstringvector> sorted_wide_userinput;

    // functions for getting the user input and processing it.
    void get_raw_userinput();
    void get_wide_userinput(const stringvector& raw_input);
    void get_wordsizes(const wstringvector& wide_input);
    void get_sorted_wide_userinput(const wstringvector& wide_input);

    // helper function of the print_braille() function. prints one row of the braille output.
    void print_brailleline(const wstringvector& sorted_stringvector, std::vector<wcharset> charset);
    std::string print_brailleline_string(const wstringvector& sorted_stringvector, std::vector<wcharset> charset);
};


#pragma once
