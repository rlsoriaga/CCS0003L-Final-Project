#include <iostream>             // BASIC INPUT/OUTPUT LIBRARY
#include "LibraryProcesses.h"   // CONNECTS THE "LibraryProcesses.h" HEADER FILE TO THIS FILE

using namespace std;            // REMOVES STD::

int main () {                   // MAIN FUNCTION

    int userMove;               // VARIABLE DECLARATION

    do {                        // DO-LOOP SO THE PROGRAM DOESNT END UNLESS THE USER INPUTS '0'
        
        // PRINTS THE MAIN MENU OF THE CATALOGUE
        cout << "=====================================================\n";
        cout << "\t\tLIBRARY CATALOGUE" << endl;
        cout << "=====================================================\n";
        cout << "[1] Fiction" << "\t\t\t  [6] Favorites" << endl;
        cout << "[2] Science Fiction" << "\t\t  [7] Clear Favorites" << endl;
        cout << "[3] Mystery" << "\t\t\t  [8] Credits" << endl;
        cout << "[4] Fantasy" << endl;
        cout << "[5] Computer Science" << "\t\t  [0] EXIT PROGRAM" << endl << endl;
        cout << "=====================================================\n";
        cout << "\t     "; showDateTime();  // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
        cout << "=====================================================\n\n";

        cout << "User Input >>> "; 
        cin >> userMove;

        // CLEARS INVALID USER INPUTS IN ORDER TO AVOID ENDLESS LOOPS
        if (cin.fail()) {     
        cin.clear();          
        cin.ignore(10000, '\n');
        userMove = -1; 
        }

        // A SWITCH TO DETERMINE WHERE THE USER'S INPUT WILL TAKE US
        switch(userMove) {

            // FICTION
            case 1:
                Fiction();
                break;

            // SCIFI
            case 2:
                Scifi();
                break;

            // MYSTERY
            case 3:
                Mystery();
                break;

            // FANTASY
            case 4:
                Fantasy();
                break;

            // COMPSCI
            case 5:
                Compsci();
                break;
            
            // FAVORITES
            case 6:
                DisplayFavorites();
                break;

            // CLEAR FAVORITES
            case 7:
                ClearFavorites();
                break;

            // CREDITS
            case 8:
                Credits();
                break;

            // EXIT
            case 0:
                break;

            // NONE OF THE ABOVE.
            default:
                cout << "Invalid input." << endl;
                break;
        }
    } while (userMove != 0);    // CONDITION FOR THE DO-LOOP 

return 0;                       // MAKES SURE THE PROGRAM ENDS SUCCESSFULLY
}