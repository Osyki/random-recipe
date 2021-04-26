//
// Created by Ekyso on 4/17/2021.
//

#ifndef RECIPES_DISPLAYRECIPEMENU_H
#define RECIPES_DISPLAYRECIPEMENU_H

#include "RecipeList.h"

void UserOptionDisplay(RecipeList *list, char option);

void DisplayRecipeMenu(RecipeList *list) { //Displays the display recipe menu
    char option;

    std::cout << std::endl << "What kind of recipe is it?" << std::endl; //begin DisplayRecipeMenu
    std::cout << "1 - Display All Recipes" << std::endl;
    std::cout << "2 - Find a recipe by name" << std::endl;
    std::cout << "3 - Find a breakfast recipe" << std::endl;
    std::cout << "4 - Find a lunch recipe" << std::endl;
    std::cout << "5 - Find a dinner recipe" << std::endl;
    std::cout << "6 - Find a dessert recipe" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose an option:" << std::endl;

    std::cin >> option; //ask user for an option
    UserOptionDisplay(list, option); //passes list and the option to function
}

void UserOptionDisplay(RecipeList *list, char option) { //function to call appropriate menu option
    bool validOption = false; //set false for first instance so it can go into loop
    while (!validOption) { //if false go into loop, will only exit if correct option is chosen
        switch (option) { //switch case for easy option integration
            case '1':
            case '3':
            case '4':
            case '5':
            case '6':
                validOption = true; //to exit loop after functions are called if switch case matches
                list->PrintRecipes(option); //call method to print recipes in the list depending on option given
                //std::cout << "This is option 1" << std::endl; //testing option only
                break;

            case '2':
                validOption = true;
                // std::cout << "This is option 2" << std::endl; //testing option only
                break;

            case 'q': //quit loop
            case 'Q':
                validOption = true;
                break;

            default:  //default case is set to always ask for a valid option because of loop
                std::cout << "Please select a valid option:" << std::endl;
                std::cin >> option; //ask user for another option
        }
    }
}

#endif //RECIPES_DISPLAYRECIPEMENU_H
