//
// Created by Ekyso on 4/16/2021.
//

#ifndef RECIPES_MAINMENU_H
#define RECIPES_MAINMENU_H
#include "DisplayRecipeMenu.h"
#include "AddRecipeMenu.h"
#include "SaveLoadMenu.h"


void UserOptionMain(RecipeList *list, char option);

void MainMenu(RecipeList *list) { //Displays the main menu
    char option;

    std::cout << std::endl;
    std::cout << "What would you like to do?" << std::endl; //begin PrintMenu
    std::cout << "1 - Add a recipe" << std::endl;
    std::cout << "2 - Display a recipe" << std::endl;
    std::cout << "3 - Delete a recipe" << std::endl;
    //std::cout << "4 - Load from file" << std::endl;
    //std::cout << "5 - Save to file" << std::endl;
    std::cout << "q - Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose an option:" << std::endl;

    std::cin >> option; //asks user for option
    UserOptionMain(list, option); //passes list and the option to function
}

void UserOptionMain(RecipeList *list, char option) { //function to call appropriate menu option
    bool validOption = false; //set false for first instance so it can go into loop
    while (!validOption) { //if false go into loop, will only exit if correct option is chosen
        switch (option) { //switch case for easy option integration
            case '1':
                validOption = true; //to exit loop after functions are called if switch case matches
                //std::cout << "This is option 1" << std::endl; //TODO: testing option only
                AddRecipeMenu(list); //call addrecipemenu and pass list
                MainMenu(list); //call main menu again
                break; //break out of switch

            case '2':
                validOption = true;
                DisplayRecipeMenu(list);
                //std::cout << "This is option 2" << std::endl; //TODO: testing option only
                MainMenu(list);
                break;

            case '3':
                validOption = true;
                //std::cout << "This is option 3" << std::endl; //TODO: testing option only
                MainMenu(list);
                break;

            case '4': //load from file //TODO: NO LONGER NEEDED, AUTOMATIC LOADING WHEN RUNNING PROGRAM
                validOption = true;
                LoadFromFile(list); //
                //std::cout << "This is option 4" << std::endl; //TODO: testing option only
                MainMenu(list);
                break;

            case '5':
                validOption = true;
                //SaveToFile(list);
                list->SaveFile(); //call save method to save to file
                //std::cout << "This is option 5" << std::endl; //TODO: testing option only
                MainMenu(list);
                break;

            case 'q': //quits the program
            case 'Q':
                validOption = true;
                break;

            default: //default case is set to always ask for a valid option because of loop
                std::cout << "Please select a valid option:" << std::endl;
                std::cin >> option; //ask user for another option
        }
    }
}

#endif //RECIPES_MAINMENU_H
