#include "Menu.h"

Menu::Menu()
{
    std::ifstream iffile;
    iffile.open("filepath.txt");
    if (iffile.is_open())
    {
        std::getline(iffile, default_path);
    }
    iffile.close();

}

Menu::~Menu()
{

}

void Menu::display(std::string my_string)
{
    std::cout << my_string;
}

MenuAccess Menu::map_user_input(std::string user_input)
{
    if (user_input == "-f")
    {
        return MenuAccess::FILES;
    }
    else if (user_input == "-o")
    {
        return MenuAccess::OPTIONS;
    }
    else if (user_input == "-b")
    {
        return MenuAccess::BRAILLEINFO;
    }
    else if (user_input == "-n")
    {
        return MenuAccess::BACK;
    }
    else if (user_input == "-g")
    {
        return MenuAccess::GRAMMAR;
    }
    else if (user_input == "-l")
    {
        return MenuAccess::LETTERS;
    }
    else if (user_input == "-w")
    {
        return MenuAccess::WRITETOFILE;
    }
    else if (user_input == "-d")
    {
        return MenuAccess::SETFILEPATH;
    }
    else if (user_input == "-1")
    {
        return MenuAccess::YES;
    }
    else if (user_input == "-0")
    {
        return MenuAccess::NO;
    }
    else
    {
        return MenuAccess::INVALID;
    }
}

MenuAccess Menu::get_navigation_action()
{
    std::string userinput;
    std::cout << ">> ";
    std::cin >> userinput;
    return map_user_input(userinput);
}

void Menu::write_to_file()
{
    BraillePrinting input;
    std::string filepathandorname;
    std::cout << std::endl;
    std::cout << "Specify filepath and/or filename\n(filenamextension is added automaticly): ";
    std::cin >> filepathandorname;
    std::cout << std::endl;
    std::ofstream offile;
    offile.open(default_path + filepathandorname + ".txt");
    if (offile.is_open())
    {
        std::cout << "File opening and writing proccess successfull. You can now open the file. " << std::endl;;
        offile << input.print_braille_to_string();
    }
    else
    {
        std::cout << "Invalid path and/or filename!" << std::endl;
    }
    offile.close();
}

void Menu::set_default_filepath()
{
    std::string default_filepath_input;
    std::cout << "Current default filepath is: " + default_path << std::endl;
    std::cout << "Set new default file path? (-1 = yes / -0 = no): ";
    menu_state = get_navigation_action();
    if (menu_state == MenuAccess::YES)
    {
        std::cout << std::endl;
        std::cout << "Enter new default file path: ";
        std::cin >> default_filepath_input;
        std::ofstream offile;
        offile.open("filepath.txt");
        offile << default_filepath_input;
        offile.close();
        default_path = default_filepath_input;

        system("clear");
        display(options_menu);
        std::cout << "Current default filepath is: " + default_path << std::endl;
        std::cout << "Set new default file path? (-1 = yes / -0 = no): " << std::endl;
        std::cout << std::endl;
        std::cout << "Enter new default file path: " << default_path << std::endl;
    }

}
