## Guessing Game with GTKmm GUI  

This C++ program implements a simple guessing game with a graphical user interface using GTKmm. The game displays an image of a cartoon character, and the user has to guess the character's name. The GUI includes options to access hints about enemies, allies, and pets. The user can input their guess, and the program provides feedback on correctness.  

main.cpp:  
The main entry point of the program.  
Creates an instance of the MyWindow class and runs the GTK application.  

MyWindow - Implements the MyWindow class, which derives from Gtk::Window.
Creates the main window, menus, labels, image, entry box, and buttons.
Defines callback functions for button clicks and handling user input.

GUI Components:  
Enemy Hints: Submenu with hints about enemies (Anita and Roger).  
Allies Hints: Submenu with hints about allies (Jasper and Horace).  
Pet Hints: Submenu with hints about pets (Pongo and Perdita).  

Image and Label:  
Displays an image of the cartoon character (Cruella De Vil).  
Includes a label prompting the user to guess the character's name.  

Entry Box: Allows the user to enter their guess.  

Buttons:    
Ok: Validates the user's guess and provides feedback.  
Cancel: Closes the application.  

Compilation:  
The program can be compiled using a C++ compiler with GTKmm library support.  

Dependencies:  
The program depends on the GTKmm library.  

Notes:  
The game checks if the user's guess matches the correct answer ("Cruella").    e