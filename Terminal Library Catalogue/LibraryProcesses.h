#pragma once            // MAKES SURE THERES NO DUPLICATION OF DEFINED ENTITIES 

#include <iostream>     // BASIC INPUT/OUTPUT LIBRARY
#include <string>       // STRING LIBRARY
#include <vector>       // FOR STORING BOOKS INTO A VECTOR
#include <conio.h>      // FOR _GETCH()
#include <ctime>        // FOR DATE AND TIME

#include "Class.h"      // CONNECTS THE "Class.h" HEADER FILE TO THIS FILE
using namespace std;    // REMOVES STD::


vector<Book> MyFavorites;   // CREATES A VECTOR NAMED "MyFavorites" WITH A BOOK (CLASS) TYPE

void showDateTime() {       // FUNCTION THAT PULLS THE TIME, CONVERTS IT TO STRING, AND PRINTS IT
    time_t oras = time(0);  
    string dateTime = ctime(&oras);
    cout << dateTime;
}

void DisplayFavorites() {   // FUNCTION TO DISPLAY THE FAVORITES SECTION

    cout << "       ===================================================\n";
    cout << "       \t\t       FAVORITES SECTION\n";
    cout << "       ===================================================\n";

    if (MyFavorites.empty()) {  // RUNS IF "MyFavorites" IS EMPTY
        cout << "\n\n     You have no added favorites. Maybe consider adding some?\n\n\n";
    }

    else {      // RUNS IF "MyFavorites" IS NOT EMPTY
        for (int counter = 0; counter < MyFavorites.size(); counter++) {    // THIS FOR-LOOP WILL CHECK EACH OF THE CONTENTS OF "MyFavorites" AND PRINTS IT
            cout << "\t\t\t    [" << counter + 1 << "] " << endl;           
            MyFavorites[counter].printDetails();                            
            cout << "" << endl;
        }
    }

    cout << "       ===================================================\n";
    cout << "                   "; showDateTime();  // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    cout << "\t\t   Press any key to return...";
    _getch();
    cout <<"\n\n\n";

return;
}

void ClearFavorites() {     // FUNCTION TO CLEAR THE FAVORITES SECTION

    char YesOrNo;
    bool loopChecker;

        do {    // LOOPS UNTIL THE USER ENTERS EITHER Y/y OR N/n
            cout << "Are you sure you'd like to clear your favorites list (Y/N): ";
            cin >> YesOrNo;

            if (YesOrNo == 'Y' || YesOrNo == 'y') { // IF USER WANTS TO CLEAR FAVORITES

                if (MyFavorites.size() == 0) {  // RUNS IF THE "MyFavorites" VECTOR HAS NO CONTENTS
                    cout << "Nothing to clear. Your favorites list is empty!" << endl << endl;
                    cout << "Press any key to return...";
                    _getch();
                    cout << "\n\n";
                    break;
                }

                else {  // RUNS IF THE "MyFavorites" VECTOR HAS CONTENTS
                    MyFavorites.clear();  
                    cout << "Favorites list has been successfully cleared!"<< endl << endl;
                    loopChecker = false;
                    cout << "Press any key to return...";
                    _getch();
                    cout << "\n\n";
                    break;
                }
            }

            else if (YesOrNo == 'N' || YesOrNo == 'n') {    // IF THE USER DOESN'T WANT TO CLEAR FAVORITES
                cout << "Clearing cancelled." << endl << endl;
                loopChecker = false;
                cout << "Press any key to return...";
                _getch();
                cout << "\n\n";
                break;
            }

            else { // IF THE USER INPUTS AN INVALID INPUT
                cout << "Please enter a valid input (Y/N)." << endl;
                loopChecker = true;
            }
        }  while (loopChecker);

return;
}

void bookProcess(Book selectedBook) {   // FUNCTION THAT PRINTS THE BOOK DETAILS AND ASKS THE USER IF THEY WANT TO PUT THE BOOK INTO THEIR FAVORITES

    selectedBook.printDetails();    // PRINTS THE BOOK DETAILS WHILE THE OBJECT IS BEING THE REFERENCE FOR DETAILS

    char addtoFav;
    while (true) {  // THIS LOOP ASKS THE USER IF THEY WANT TO ADD THE SPECIFIC BOOK TO THEIR FAVORITES SECTION
        cout << "      Add this book to your personal favorites? (Y/N)" << endl;
        cout << "              -----------------------------" << endl;
        cout << "              User Input >>> "; 
        cin >> addtoFav;
             
        if (addtoFav == 'N' || addtoFav == 'n') {   // IF THEY DONT WANT TO ADD
            cout << "              Cancelled." << endl;
            break;
        }

        else if (addtoFav == 'Y' || addtoFav == 'y') {  // IF THEY WANT TO ADD
            bool alreadyExists = false;

            for (int i = 0; i < MyFavorites.size(); i++) {  // CHECKS IF THE BOOK THEY ARE TRYING TO ADD IS ALREADY IN THEIR FAVORITES LIST ("MyFavorites" VECTOR)
                if (MyFavorites[i].id == selectedBook.id) {
                    alreadyExists = true;
                    break; 
                }
            }

            if (alreadyExists) {    // IF THE BOOK IS A DUPLICATE
                cout << "              Duplicate Warning: '" << selectedBook.title << "' is already in your list!" << endl;
                break; 
            }
                
            else {  // IF THE BOOK IS NOT A DUPLICATE
                MyFavorites.push_back(selectedBook);
                cout << "              Success! " << "\""<< selectedBook.title << "\"" << " has been successfully added to your catalogue list." << endl;
                break;
            }
        }

        else {  // IF THE USER INPUT IS INVALID
            cout << "              Enter a valid input (Y/N)." << endl;
        }
    }
    
return;
}

void Fiction() {    // FUNCTION THAT PRINTS THE FICTION SECTION + CONTAINS FICTION OBJECTS OF "Book" CLASS  

    // OBJECTS OF THE "Book" CLASS FOR FICTION
    Book no101;
        no101.id = 101;
        no101.title = "1984";
        no101.author = "George Orwell";
        no101.category = "Fiction";

    Book no102;
        no102.id = 102;
        no102.title = "To Kill a Mockingbird";
        no102.author = "Harper Lee";
        no102.category = "Fiction";

    Book no103;
        no103.id = 103;
        no103.title = "The Great Gatsby";
        no103.author = "F. Scott Fitzgerald";
        no103.category = "Fiction";

    Book no104;
        no104.id = 104;
        no104.title = "Pride and Prejudice";
        no104.author = "Jane Austen";
        no104.category = "Fiction";

    Book no105;
        no105.id = 105;
        no105.title = "The Catcher in the Rye";
        no105.author = "J.D. Salinger";
        no105.category = "Fiction";

    // MENU FOR FICTION SECTION
    int bookChoice;
    cout << "       ===================================================\n";
    cout << "       \t\t\t FICTION SECTION\n";
    cout << "       ===================================================\n";
    cout << "       [1] " << no101.title << endl;
    cout << "       [2] " << no102.title << endl;
    cout << "       [3] " << no103.title << endl;
    cout << "       [4] " << no104.title << endl;
    cout << "       [5] " << no105.title << endl << endl;
    cout << "       [0] EXIT" << endl;
    cout << "       ===================================================\n";
    cout << "       \t\t   "; showDateTime();   // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    
    do {    // DO-LOOP THAT STOPS IF THE USER ENTERS 0 (EXIT)
        cout << "       User Input >>> "; cin >> bookChoice;
                
        switch(bookChoice) {    // A SWITCH TO DETERMINE WHICH BOOK THE USER'S INPUT WILL TAKE US
            case 1:
                bookProcess(no101);
                break;            
            case 2:
                bookProcess(no102);
                break;
            case 3:
                bookProcess(no103);
                break;
            case 4:
                bookProcess(no104);
                break;
            case 5:
                bookProcess(no105);
                break;
            case 0:
                break;
            default:
                cout << "               Invalid input." << endl;
                break;
        } 
    } while (bookChoice != 0);

return;   
}

void Scifi() {      // FUNCTION THAT PRINTS THE SCIFI SECTION + CONTAINS SCIFI OBJECTS OF "Book" CLASS

    // OBJECTS OF THE "Book" CLASS FOR SCIFI
    Book no201;
        no201.id = 201;
        no201.title = "Dune";
        no201.author = "Frank Herbert";
        no201.category = "Science Fiction";   

    Book no202;
        no202.id = 202;
        no202.title = "The Hitchhiker's Guide to the Galaxy";
        no202.author = "Douglas Adams";
        no202.category = "Science Fiction";

    Book no203;
        no203.id = 203;
        no203.title = "Ender's Game";
        no203.author = "Orson Scott Card";
        no203.category = "Science Fiction";

    Book no204;
        no204.id = 204;
        no204.title = "Neuromancer";
        no204.author = "William Gibson";
        no204.category = "Science Fiction";

    Book no205;
        no205.id = 205;
        no205.title = "Snow Crash";
        no205.author = "Neal Stephenson";
        no205.category = "Science Fiction";

    // MENU FOR SCIFI SECTION
    int bookChoice;
    cout << "       ===================================================\n";
    cout << "       \t\t    SCIENCE FICTION SECTION\n";
    cout << "       ===================================================\n";
    cout << "       [1] " << no201.title << endl;
    cout << "       [2] " << no202.title << endl;
    cout << "       [3] " << no203.title << endl;
    cout << "       [4] " << no204.title << endl;
    cout << "       [5] " << no205.title << endl << endl;
    cout << "       [0] EXIT" << endl;
    cout << "       ===================================================\n";
    cout << "       \t\t   "; showDateTime();   // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    
    do {    // DO-LOOP THAT STOPS IF THE USER ENTERS 0 (EXIT)
        cout << "       User Input >>> "; cin >> bookChoice;
                
        switch(bookChoice) {    // A SWITCH TO DETERMINE WHICH BOOK THE USER'S INPUT WILL TAKE US
            case 1:
                bookProcess(no201);
                break;            
            case 2:
                bookProcess(no202);
                break;
            case 3:
                bookProcess(no203);
                break;
            case 4:
                bookProcess(no204);
                break;
            case 5:
                bookProcess(no205);
                break;
            case 0:
                break;
            default:
                cout << "               Invalid input." << endl;
                break;
        } 
    } while (bookChoice != 0);

return; 
}

void Mystery() {    // FUNCTION THAT PRINTS THE MYSTERY SECTION + CONTAINS MYSTERY OBJECTS OF "Book" CLASS

    // OBJECTS OF THE "Book" CLASS FOR MYSTERY
    Book no301;
        no301.id = 301;
        no301.title = "The Girl with the Dragon Tattoo";
        no301.author = "Stieg Larsson";
        no301.category = "Mystery";   

    Book no302;
        no302.id = 302;
        no302.title = "And Then There Were None";
        no302.author = "Agatha Christie";
        no302.category = "Mystery";    

    Book no303;
        no303.id = 303;
        no303.title = "The Da Vinci Code";
        no303.author = "Dan Brown";
        no303.category = "Mystery"; 

    Book no304;
        no304.id = 304;
        no304.title = "Gone Girl";
        no304.author = "Gillian Flynn";
        no304.category = "Mystery";     

    Book no305;
        no305.id = 305;
        no305.title = "The Big Sleep";
        no305.author = "Raymond Chandler";
        no305.category = "Mystery"; 

    // MENU FOR MYSTERY SECTION
    int bookChoice;
    cout << "       ===================================================\n";
    cout << "       \t\t\t MYSTERY SECTION\n";
    cout << "       ===================================================\n";
    cout << "       [1] " << no301.title << endl;
    cout << "       [2] " << no302.title << endl;
    cout << "       [3] " << no303.title << endl;
    cout << "       [4] " << no304.title << endl;
    cout << "       [5] " << no305.title << endl << endl;
    cout << "       [0] EXIT" << endl;
    cout << "       ===================================================\n";
    cout << "       \t\t   "; showDateTime();   // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    
    do {    // DO-LOOP THAT STOPS IF THE USER ENTERS 0 (EXIT)
        cout << "       User Input >>> "; cin >> bookChoice;
                
        switch(bookChoice) {    // A SWITCH TO DETERMINE WHICH BOOK THE USER'S INPUT WILL TAKE US
            case 1:
                bookProcess(no301);
                break;            
            case 2:
                bookProcess(no302);
                break;
            case 3:
                bookProcess(no303);
                break;
            case 4:
                bookProcess(no304);
                break;
            case 5:
                bookProcess(no305);
                break;
            case 0:
                break;
            default:
                cout << "               Invalid input." << endl;
                break;
        } 
    } while (bookChoice != 0);

return;   
}

void Fantasy() {    // FUNCTION THAT PRINTS THE FANTASY SECTION + CONTAINS FANTASY OBJECTS OF "Book" CLASS
    
    // OBJECTS OF THE "Book" CLASS FOR FANTASY
    Book no401;
        no401.id = 401;
        no401.title = "Harry Potter and the Sorcerer's Stone";
        no401.author = "J.K. Rowling";
        no401.category = "Fantasy";   

    Book no402;
        no402.id = 402;
        no402.title = "The Hobbit";
        no402.author = "J.R.R. Tolkien";
        no402.category = "Fantasy";   

    Book no403;
        no403.id = 403;
        no403.title = "A Game of Thrones";
        no403.author = "George R.R. Martin";
        no403.category = "Fantasy"; 

    Book no404;
        no404.id = 404;
        no404.title = "The Name of the Wind";
        no404.author = "Patrick Rothfuss";
        no404.category = "Fantasy";

    Book no405;
        no405.id = 405;
        no405.title = "The Lion, the Witch and the Wardrobe";
        no405.author = "C.S. Lewis";
        no405.category = "Fantasy";
     
    // MENU FOR FICTION SECTION
    int bookChoice;
    cout << "       ===================================================\n";
    cout << "       \t\t\t FANTASY SECTION\n";
    cout << "       ===================================================\n";
    cout << "       [1] " << no401.title << endl;
    cout << "       [2] " << no402.title << endl;
    cout << "       [3] " << no403.title << endl;
    cout << "       [4] " << no404.title << endl;
    cout << "       [5] " << no405.title << endl << endl;
    cout << "       [0] EXIT" << endl;
    cout << "       ===================================================\n";
    cout << "       \t\t   "; showDateTime();   // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    
    do {    // DO-LOOP THAT STOPS IF THE USER ENTERS 0 (EXIT)
        cout << "       User Input >>> "; cin >> bookChoice;
                
        switch(bookChoice) {    // A SWITCH TO DETERMINE WHICH BOOK THE USER'S INPUT WILL TAKE US
            case 1:
                bookProcess(no401);
                break;            
            case 2:
                bookProcess(no402);
                break;
            case 3:
                bookProcess(no403);
                break;
            case 4:
                bookProcess(no404);
                break;
            case 5:
                bookProcess(no405);
                break;
            case 0:
                break;
            default:
                cout << "               Invalid input." << endl;
                break;
        } 
    } while (bookChoice != 0);

return; 
}

void Compsci() {    // FUNCTION THAT PRINTS THE COMPSCI SECTION + CONTAINS COMPSCI OBJECTS OF "Book" CLASS
    
    // OBJECTS OF THE "Book" CLASS FOR COMPSCI
    Book no501;
        no501.id = 501;
        no501.title = "The Pragmatic Programmer";
        no501.author = "Andrew Hunt & David Thomas";
        no501.category = "Computer Science";  

    Book no502;
        no502.id = 502;
        no502.title = "Clean Code";
        no502.author = "Robert C. Martin";
        no502.category = "Computer Science";  

    Book no503;
        no503.id = 503;
        no503.title = "Introduction to Algorithms";
        no503.author = "Thomas H. Cormen";
        no503.category = "Computer Science";

    Book no504;
        no504.id = 504;
        no504.title = "Design Patterns";
        no504.author = "Erich Gamma";
        no504.category = "Computer Science";

    Book no505;
        no505.id = 505;
        no505.title = "The C Programming Language";
        no505.author = "Brian Kernighan & Dennis Ritchie";
        no505.category = "Computer Science";
      
    // MENU FOR COMPSCI SECTION    
    int bookChoice;
    cout << "       ===================================================\n";
    cout << "       \t\t   COMPUTER SCIENCE SECTION\n";
    cout << "       ===================================================\n";
    cout << "       [1] " << no501.title << endl;
    cout << "       [2] " << no502.title << endl;
    cout << "       [3] " << no503.title << endl;
    cout << "       [4] " << no504.title << endl;
    cout << "       [5] " << no505.title << endl << endl;
    cout << "       [0] EXIT" << endl;
    cout << "       ===================================================\n";
    cout << "       \t\t   "; showDateTime();   // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    
    do {    // DO-LOOP THAT STOPS IF THE USER ENTERS 0 (EXIT)
        cout << "       User Input >>> "; cin >> bookChoice;
                
        switch(bookChoice) {    // A SWITCH TO DETERMINE WHICH BOOK THE USER'S INPUT WILL TAKE US
            case 1:
                bookProcess(no501);
                break;            
            case 2:
                bookProcess(no502);
                break;
            case 3:
                bookProcess(no503);
                break;
            case 4:
                bookProcess(no504);
                break; 
            case 5:
                bookProcess(no505);
                break;               
            case 0:
                break;
            default:
                cout << "               Invalid input." << endl;
                break;
        } 
    } while (bookChoice != 0);

return;
}

void Credits() {    // FUNCTION THAT PRINTS THE CREDIT SECTION

    cout << "       ===================================================\n";
    cout << "       \t\t\t CREDITS SECTION\n";
    cout << "       ===================================================\n\n";
    cout << "\t     In accordance with his final project\n";
    cout << "\t\t  in Computer Programming 1,\n\n";
    cout << "\t        this program was developed by\n";
    cout << "\t        Ronald John Soriaga from TN06.\n\n";
    cout << "       ===================================================\n";
    cout << "       \t\t   "; showDateTime();   // CALLS THE showDateTime() FUNCTION WHICH PRINTS THE DATE AND TIME
    cout << "       ===================================================\n";
    cout << "\t\t   Press any key to return...";
    _getch();   
    cout <<"\n\n\n";

return;
}