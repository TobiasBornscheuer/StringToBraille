#include "Printing.h"
#include "Mapping.h"

/*
----------------------------------------------------------------------------------------------------
    ### Constructor and Destructor ###
----------------------------------------------------------------------------------------------------
*/

// custom default constructor. Executes the function for getting user input
// and the functions for processing the user input in preparation for the print function.
BraillePrinting::BraillePrinting()
{
    get_raw_userinput();
    get_wide_userinput(raw_userinput);
    get_wordsizes(wide_userinput);
    get_sorted_wide_userinput(wide_userinput);
}

// regular destructor
BraillePrinting::~BraillePrinting()
{

}

/*
----------------------------------------------------------------------------------------------------
    ### Functions for getting the raw user input and refining that input ###
    ### into a data structure usable by the print functions              ###
----------------------------------------------------------------------------------------------------
*/

// prompts the user for input and splits that input into individual words.
// the resulting vector of strings is an attribute of the BraillePrinting class.
void BraillePrinting::get_raw_userinput()
{
    std::string user_input;
    char delimiter = ' ';
    std::cout << "Enter a sentence: " << std::endl;
    std::cout << ">> ";
    std::getline(std::cin >> std::ws, user_input);
    std::string word;
    std::stringstream sstream(user_input);
    while (std::getline(sstream, word, delimiter))
    {
        raw_userinput.push_back(word);
    }
    rawest_userinput = user_input;
}

// getter function for the raw user input
std::string BraillePrinting::read_rawest_userinput()
{
    return rawest_userinput;
}

// takes the stringvector with the raw user input and converts it into wide strings,
// so every character takes up the same amount memory.
// the resulting vector of wstrings is an attribute of the BraillePrinting class.
void BraillePrinting::get_wide_userinput(const stringvector& raw_input)
{
    for (auto word : raw_input)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        wide_userinput.push_back(converter.from_bytes(word));
    }
}

// takes the wstringvector and creates an int vector containing it's actual word sizes.
// depending on the type of char and the composition of the word,
// more than one braille char gets printed for a regular char.
// the resulting vector of integers is an attribute of the BraillePrinting class.
void BraillePrinting::get_wordsizes(const wstringvector& wide_input)
{
    int counter = 0;
    bool number_streak = false;

    for (auto word : wide_input)
    {
        int i = 0;
        for (auto it = word.begin(); it < word.end(); it++)
        {
            if (is_small_char.count(word.substr(i, 1)))
            {
                counter += 1;
                i += 1;
                number_streak = false;
            }
            else if (is_big_char.count(word.substr(i, 1)))
            {
                counter += 2;
                i += 1;
                number_streak = false;
            }
            else if (is_number.count(word.substr(i, 1)) && number_streak == false)
            {
                counter += 2;
                i += 1;
                number_streak = true;
            }
            else if (is_numberspace_member.count(word.substr(i, 1)) && number_streak == true)
            {
                counter += 1;
                i += 1;
            }
        }
        wordsizes.push_back(counter);
        counter = 0;
    }
}

// takes the wstringvector and creates a 2d wstringvector,
// where every wstringvector contains words with a combined actual word size of less than 30.
// that way each wstringvector's braille equivalent can get printed out in one line.
// the resulting 2d wstringvector is an attribute of the BraillePrinting class.
void BraillePrinting::get_sorted_wide_userinput(const wstringvector& wide_input)
{
    wstringvector temp;
    unsigned int charcount_line = 0;
    int i = 0;
    for (auto word : wide_input)
    {
        if (charcount_line + wordsizes[i] < 30)
        {
            temp.push_back(word);
            charcount_line += wordsizes[i];
        }
        if (charcount_line + wordsizes[i] >= 30 || word == wide_input.back())
        {
            sorted_wide_userinput.push_back(temp);
            temp.clear();
            charcount_line = 0;
        }
        i += 1;
    }
}

/*
----------------------------------------------------------------------------------------------------
    ### Functions that take the refined user input and ###
    ### print the braille equivalent to the console    ###
----------------------------------------------------------------------------------------------------
*/

// prints the braille equivalent of a wstringvector to the console.
// the charset determines which row of the braille character gets printed
void BraillePrinting::print_brailleline(const wstringvector& sorted_stringvector, std::vector<wcharset> charset)
{
    for (auto word : sorted_stringvector)
    {
        int i = 0;
        bool number_streak = false;
        for (auto it = word.begin(); it < word.end(); it++)
        {
            if (charset[0].count(word.substr(i, 1))) // left
            {
                std::cout << "* "
                    << "   ";
                i++;
            }
            else if (charset[1].count(word.substr(i, 1))) // right
            {
                std::cout << " *"
                    << "   ";
                i++;
            }
            else if (charset[2].count(word.substr(i, 1))) // both
            {
                std::cout << "**"
                    << "   ";
                i++;
            }
            else if (charset[3].count(word.substr(i, 1))) // none
            {
                std::cout << "  "
                    << "   ";
                i++;
            }
            else if (charset[4].count(word.substr(i, 1))) // left_capital
            {
                if (charset == charset_l2)
                {
                    std::cout << "  "
                        << "   ";
                }
                else
                {
                    std::cout << " *"
                        << "   ";
                }
                std::cout << "* "
                    << "   ";
                i++;
            }
            else if (charset[5].count(word.substr(i, 1))) // right_capital
            {
                if (charset == charset_l2)
                {
                    std::cout << "  "
                        << "   ";
                }
                else
                {
                    std::cout << " *"
                        << "   ";
                }
                std::cout << " *"
                    << "   ";
                i++;
            }
            else if (charset[6].count(word.substr(i, 1))) // both_capital
            {
                if (charset == charset_l2)
                {
                    std::cout << "  "
                        << "   ";
                }
                else
                {
                    std::cout << " *"
                        << "   ";
                }
                std::cout << "**"
                    << "   ";
                i++;
            }
            else if (charset[7].count(word.substr(i, 1))) // none_capital
            {
                if (charset == charset_l2)
                {
                    std::cout << "  "
                        << "   ";
                }
                else
                {
                    std::cout << " *"
                        << "   ";
                }
                std::cout << "  "
                    << "   ";
                i++;
            }
            else if (is_number.count(word.substr(i, 1)) && number_streak == false)
            {
                if (charset == charset_l3)
                {
                    std::cout << "**"
                        << "   ";
                }
                else
                {
                    std::cout << " *"
                        << "   ";
                }
                number_streak = true;
                if (charset[8].count(word.substr(i, 1))) // numberspace_left
                {
                    std::cout << "* " << "   ";
                }
                else if (charset[9].count(word.substr(i, 1))) // numberspace_right
                {
                    std::cout << " *" << "   ";
                }
                else if (charset[10].count(word.substr(i, 1))) // numberspace_both
                {
                    std::cout << "**" << "   ";
                }
                else if (charset[11].count(word.substr(i, 1))) // numberspace_none
                {
                    std::cout << "  " << "   ";
                }
                i++;
            }
            else if (is_numberspace_member.count(word.substr(i, 1)) && number_streak == true)
            {
                if (charset[8].count(word.substr(i, 1))) // numberspace_left
                {
                    std::cout << "* " << "   ";
                }
                else if (charset[9].count(word.substr(i, 1))) // numberspace_right
                {
                    std::cout << " *" << "   ";
                }
                else if (charset[10].count(word.substr(i, 1))) // numberspace_both
                {
                    std::cout << "**" << "   ";
                }
                else if (charset[11].count(word.substr(i, 1))) // numberspace_none
                {
                    std::cout << "  " << "   ";
                }
                i++;
                if (!word.back() && !is_numberspace_member.count(word.substr(i + 1, 1)))
                {
                    number_streak = false;
                }
            }
        }
        std::cout << "   ";
    }
    std::cout << std::endl;
}

// same as print_brailleline but stores the result in a string.
std::string BraillePrinting::print_brailleline_string(const wstringvector& sorted_stringvector, std::vector<wcharset> charset)
{
    std::string returnstring;
    for (auto word : sorted_stringvector)
    {
        int i = 0;
        bool number_streak = false;
        for (auto it = word.begin(); it < word.end(); it++)
        {
            if (charset[0].count(word.substr(i, 1))) // left
            {
                returnstring.append("* ");
                returnstring.append("   ");
                i++;
            }
            else if (charset[1].count(word.substr(i, 1))) // right
            {
                returnstring.append(" *");
                returnstring.append("   ");
                i++;
            }
            else if (charset[2].count(word.substr(i, 1))) // both
            {
                returnstring.append("**");
                returnstring.append("   ");
                i++;
            }
            else if (charset[3].count(word.substr(i, 1))) // none
            {
                returnstring.append("  ");
                returnstring.append("   ");
                i++;
            }
            else if (charset[4].count(word.substr(i, 1))) // left_capital
            {
                if (charset == charset_l2)
                {
                    returnstring.append("  ");
                    returnstring.append("   ");
                }
                else
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                returnstring.append("* ");
                returnstring.append("   ");
                i++;
            }
            else if (charset[5].count(word.substr(i, 1))) // right_capital
            {
                if (charset == charset_l2)
                {
                    returnstring.append("  ");
                    returnstring.append("   ");
                }
                else
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                returnstring.append(" *");
                returnstring.append("   ");
                i++;
            }
            else if (charset[6].count(word.substr(i, 1))) // both_capital
            {
                if (charset == charset_l2)
                {
                    returnstring.append("  ");
                    returnstring.append("   ");
                }
                else
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                returnstring.append("**");
                returnstring.append("   ");
                i++;
            }
            else if (charset[7].count(word.substr(i, 1))) // none_capital
            {
                if (charset == charset_l2)
                {
                    returnstring.append("  ");
                    returnstring.append("   ");
                }
                else
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                returnstring.append("  ");
                returnstring.append("   ");
                i++;
            }
            else if (is_number.count(word.substr(i, 1)) && number_streak == false)
            {
                if (charset == charset_l3)
                {
                    returnstring.append("**");
                    returnstring.append("   ");
                }
                else
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                number_streak = true;
                if (charset[8].count(word.substr(i, 1))) // numberspace_left
                {
                    returnstring.append("* ");
                    returnstring.append("   ");
                }
                else if (charset[9].count(word.substr(i, 1))) // numberspace_right
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                else if (charset[10].count(word.substr(i, 1))) // numberspace_both
                {
                    returnstring.append("**");
                    returnstring.append("   ");
                }
                else if (charset[11].count(word.substr(i, 1))) // numberspace_none
                {
                    returnstring.append("  ");
                    returnstring.append("   ");
                }
                i++;
            }
            else if (is_numberspace_member.count(word.substr(i, 1)) && number_streak == true)
            {
                if (charset[8].count(word.substr(i, 1))) // numberspace_left
                {
                    returnstring.append("* ");
                    returnstring.append("   ");
                }
                else if (charset[9].count(word.substr(i, 1))) // numberspace_right
                {
                    returnstring.append(" *");
                    returnstring.append("   ");
                }
                else if (charset[10].count(word.substr(i, 1))) // numberspace_both
                {
                    returnstring.append("**");
                    returnstring.append("   ");
                }
                else if (charset[11].count(word.substr(i, 1))) // numberspace_none
                {
                    returnstring.append("  ");
                    returnstring.append("   ");
                }
                i++;
                if (!word.back() && !is_numberspace_member.count(word.substr(i + 1, 1)))
                {
                    number_streak = false;
                }
            }
        }
        returnstring.append("   ");
    }
    returnstring.append("\n");
    return returnstring;
}

// prints the braille characters for every wstringvector of the 2d wstringvector.
// after each vector (==> line of braille output) 2 line breaks are performed, for readability.
void BraillePrinting::print_braille()
{
    for (auto stringvector_w : sorted_wide_userinput)
    {
        print_brailleline(stringvector_w, charset_l1);
        print_brailleline(stringvector_w, charset_l2);
        print_brailleline(stringvector_w, charset_l3);
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

//same as print_braille(), but stores the result in a string
std::string BraillePrinting::print_braille_to_string()
{
    std::string braillestring;
    for (auto stringvector_w : sorted_wide_userinput)
    {
        braillestring.append(print_brailleline_string(stringvector_w, charset_l1));
        braillestring.append(print_brailleline_string(stringvector_w, charset_l2));
        braillestring.append(print_brailleline_string(stringvector_w, charset_l3));
        braillestring.append("\n");
        braillestring.append("\n");
    }
    return braillestring;
}
