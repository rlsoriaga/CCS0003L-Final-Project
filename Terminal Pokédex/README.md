# Terminal Pokedex

  <p>
Terminal Pokédex is a lightweight, command-line application written in C++ that fetches and displays Pokémon statistics directly in your terminal. By utilizing curl to pull live data from the PokéAPI, 
this project demonstrates system command execution, file I/O operations, and custom string parsing. It processes the raw JSON response to extract key stats without relying on external parsing libraries.  

Key Features:

  Live Data Retrieval: Uses a system command to trigger curl, downloading real-time Pokémon data into a local text file.  

  Custom JSON Parser: Manually searches and parses the raw JSON string to extract the Pokémon's ID, Height, Weight, and Base XP.  

  Interactive Loop: Continuously prompts the user for new Pokémon names until they type "exit" to close the application.  

Prerequisites:

  A standard C++ compiler.

  curl must be installed and accessible via your system's command line, as the program relies on it to fetch the API data. 
  </p>
