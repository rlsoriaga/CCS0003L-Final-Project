#pragma once            // MAKES SURE THERES NO DUPLICATION OF DEFINED ENTITIES 

#include <iostream>     // BASIC INPUT/OUTPUT LIBRARY
#include <string>       // STRING LIBRARY

using namespace std;    // REMOVES STD::

class Book {            // THE CLASS THAT SERVES AS THE BLUEPRINT OF THE BOOKS
    public:
        int id;
        string title;
        string author;
        string category;  
        
        void printDetails() {      // FUNCTION FOR PRINTING THE DETAILS OF THE BOOK
            cout << "              -----------------------------" << endl;
            cout << "              ID:       " << id << endl;
            cout << "              Title:    " << title << endl;
            cout << "              Author:   " << author << endl;
            cout << "              Category: " << category << endl;
            cout << "              -----------------------------" << endl;
            
        }
};