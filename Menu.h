#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Printing.h"

using stringvector = std::vector<std::string>;

enum class MenuAccess : int
{
    MAIN = 0,
    FILES = 1,
    OPTIONS = 2,
    BRAILLEINFO = 3,
    GRAMMAR = 4,
    LETTERS = 5,
    BACK = 6,
    WRITETOFILE = 7,
    SETFILEPATH = 8,
    YES = 9,
    NO = 10,
    INVALID = 11
};

class Menu
{
public:
    Menu();
    ~Menu();

    MenuAccess menu_state;

    void display(std::string my_string);

    MenuAccess map_user_input(std::string user_input);
    MenuAccess get_navigation_action();
    void write_to_file();
    void set_default_filepath();

    //private: // in Zukunft
    std::string default_path;

    std::string main_menu =
        "--------------------------------------------\n"
        "FILE (-f) | OPTIONS (-o) | Braille-Info (-b)\n"
        "--------------------------------------------\n";

    std::string file_menu =
        "--------------------------------------------\n"
        "Write to file (-w) | Back (-n)\n"
        "--------------------------------------------\n";

    std::string options_menu =
        "--------------------------------------------\n"
        "Set default filepath (-d) | Back (-n)\n"
        "--------------------------------------------\n";

    std::string brailleinfo_menu =
        "--------------------------------------------\n"
        "Grammar (-g) | Letters (-l) | Back (-n)\n"
        "--------------------------------------------\n";

    std::string brailleinfo_menu_grammar =
        "\nBraille has the following grammar you should keep in mind:\n"
        "capital letters have their own prefix. This prefix has to stand in front of every capital character.\n"
        "Even if there are multiple capital letters appended to each other, like --LOL--, for example.\n"
        "Numbers have their own prefix aswell. This prefix stands in front of every number space.\n"
        "A number space always starts with a number, but is allowed to contain special characters like --+-- aswell.\n"
        "Spaces or characters that are not number space members, end the number space.\n"
        "A new numberspace has to be preceded by a number with the numberspace prefix.\n\n";

    std::string brailleinfo_menu_letters = "\nBraille has the following letters:\n"
        "*  = a | *  = b | ** = c | ** = d | *  = e | ** = f | ** = g | *  = h |  * = i |  * = j | \n"
        "       | *      |        |  *     |  *     | *      | **     | **     | *      | **     | \n"
        "       |        |        |        |        |        |        |        |        |        | \n"
        "----------------------------------------------------------------------------------------- \n"
        "*  = k | *  = l | ** = m | ** = n | *  = o | ** = p | ** = q | *  = r |  * = s |  * = t | \n"
        "       | *      |        |  *     |  *     | *      | **     | **     | *      | **     | \n"
        "*      | *      |  *     | *      | *      | *      | *      | *      | *      | *      | \n"
        "----------------------------------------------------------------------------------------- \n"
        "*  = u | *  = v |  * = w | ** = x | ** = y | *  = z |  * = ä |  * = ö | *  = ü |  * = ß | \n"
        "       | *      | **     |        |  *     |  *     |  *     | *      | **     | *      | \n"
        "**     | **     |  *     | **     | **     | **     | *      |  *     |  *     | **     | \n"
        "-------------------------------------------------------------------------------------------------------- \n"
        " * = number- | *  = 1 | *  = 2 | ** = 3 | ** = 4 | *  = 5 | ** = 6 | ** = 7 | *  = 8 |  * = 9 |  * = 0 | \n"
        " *   prefix  |        | *      |        |  *     |  *     | *      | **     | **     | *      | **     | \n"
        "**           |        |        |        |        |        |        |        |        |        |        | \n"
        "-------------------------------------------------------------------------------------------------------- \n"
        "   = . |    = , |    = ? |    = ! |    = - |    = : |    = ; |    = * | \n"
        "       | *      | *      | **     |        | **     | *      |  *     | \n"
        "*      |        |  *     | *      | **     |        | *      | *      | \n"
        "----------------------------------------------------------------------- \n\n";
};
#pragma once
