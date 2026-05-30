#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// A helper to find data in the raw JSON text
// Example: If data is '..."weight":60,...' and we search "weight", it returns "60"
string getJsonValue(string json, string key) {
    string searchKey = "\"" + key + "\":"; // Look for "key":
    size_t foundPos = json.find(searchKey);
    
    if (foundPos == string::npos) return "Not Found"; // Safety check

    // Move past the key to find the value
    foundPos += searchKey.length();
    
    string value = "";
    // Keep reading until we hit a comma (end of data) or closing brace
    while (json[foundPos] != ',' && json[foundPos] != '}') {
        value += json[foundPos];
        foundPos++;
    }
    
    return value;
}

int main() {
    string pokemonName;
    
    while(true) {
        cout << "\n=== TERMINAL POKEDEX ===\n";
        cout << "Enter Pokemon Name (or 'exit'): ";
        cin >> pokemonName;

        if (pokemonName == "exit") break;

        // 1. FETCH: Download data to a file
        string command = "curl -s https://pokeapi.co/api/v2/pokemon/" + pokemonName + " > pokedex_entry.txt";
        system(command.c_str());

        // 2. READ: Open the file we just downloaded
        ifstream file("pokedex_entry.txt");
        string fileContent, line;
        
        // Read the whole file into one huge string
        if (file.is_open()) {
            while (getline(file, line)) {
                fileContent += line;
            }
            file.close();
        }

        // 3. CHECK: Did we get valid data?
        if (fileContent.find("Not Found") != string::npos || fileContent.empty()) {
            cout << "Pokemon not found! Check your spelling.\n";
            continue;
        }

        // 4. MINE & DISPLAY: Extract specific stats
        // Note: PokeAPI returns weight in hectograms, so 60 = 6.0kg
        cout << "\n--- " << pokemonName << " Stats ---\n";
        cout << "ID:     " << getJsonValue(fileContent, "id") << endl;
        cout << "Height: " << getJsonValue(fileContent, "height") << " decimetres" << endl;
        cout << "Weight: " << getJsonValue(fileContent, "weight") << " hectograms" << endl;
        cout << "Base XP: " << getJsonValue(fileContent, "base_experience") << endl;
    }

    return 0;
}