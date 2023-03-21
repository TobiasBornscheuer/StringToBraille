// Project1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "Printing.h"
#include "Menu.h"

int main()
{
    bool keep_running = true; // controls continuation of the programm

    system("clear"); // clearing the console once after the programm is startet
    while (keep_running == true)
    {
        system("clear"); // clearing the console at start of each iteration of the program loop
        Menu menu;
        menu.display(menu.main_menu);
        BraillePrinting userinput; // gets initialized with raw user input and sorts it through the custom default constructor
        if (menu.map_user_input(userinput.read_rawest_userinput()) == MenuAccess::INVALID) // if menu key is not entered
        {
            userinput.print_braille(); // prints the braille equivalent of the sorted user input
            std::cout << "Keep running? (1=yes 0=no): ";
            std::cout << ">> ";
            std::cin >> keep_running;
            system("clear"); // clearing the console contents before next execution
        }
        else // if menu key is entered
        {
            switch (menu.map_user_input(userinput.read_rawest_userinput())) // get menu key
            {
            case MenuAccess::FILES: // this case builds and controls the file menu
            {
                menu.menu_state = MenuAccess::FILES;
                system("clear"); // clearing the console contents to cleanly display appropriate sub menu
                menu.display(menu.file_menu);
                menu.menu_state = menu.get_navigation_action();
                while (menu.menu_state != MenuAccess::BACK)
                {
                    system("clear");
                    menu.display(menu.file_menu);
                    switch (menu.menu_state)
                    {
                    case MenuAccess::WRITETOFILE:
                        menu.write_to_file();
                        break;
                    }
                    menu.menu_state = menu.get_navigation_action();
                }
                break;
            }
            case MenuAccess::OPTIONS: // this case builds and controls the options menu
            {
                menu.menu_state = MenuAccess::OPTIONS;
                system("clear"); // clearing the console contents to cleanly display appropriate sub menu
                menu.display(menu.options_menu);
                menu.menu_state = menu.get_navigation_action();
                while (menu.menu_state != MenuAccess::BACK)
                {
                    system("clear");
                    menu.display(menu.options_menu);
                    switch (menu.menu_state)
                    {
                    case MenuAccess::SETFILEPATH:
                        menu.set_default_filepath();
                        break;
                    }
                    menu.menu_state = menu.get_navigation_action();
                }
                break;
            }
            case MenuAccess::BRAILLEINFO: // this case builds and controls the braille info menu
            {
                menu.menu_state = MenuAccess::BRAILLEINFO;
                system("clear"); // clearing the console contents to cleanly display appropriate sub menu
                menu.display(menu.brailleinfo_menu);
                menu.menu_state = menu.get_navigation_action();
                while (menu.menu_state != MenuAccess::BACK)
                {
                    system("clear");
                    menu.display(menu.brailleinfo_menu);
                    switch (menu.menu_state)
                    {
                    case MenuAccess::GRAMMAR:
                        menu.display(menu.brailleinfo_menu_grammar);
                        break;
                    case MenuAccess::LETTERS:
                        menu.display(menu.brailleinfo_menu_letters);
                    default:
                        break;
                    }
                    menu.menu_state = menu.get_navigation_action();
                }
                break;
            }
            default: // when no case meets the switch condition
            {
                menu.menu_state = MenuAccess::INVALID;
                system("clear"); // clearing the console contents to cleanly display error message
                break;
            }
            }
        }
    }

    return 0; // when programm ran without errors
}


// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
