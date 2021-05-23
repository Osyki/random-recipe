//
// Created by Ekyso on 4/16/2021.
//

#ifndef RECIPES_ADDRECIPEMENU_H
#define RECIPES_ADDRECIPEMENU_H
#include "NewRecipes.h"

void UserOptionAdd(RecipeList *list, char option);

void AddRecipeMenu(RecipeList *list) { //Displays add recipe menu
    char option;

    std::cout << std::endl << "What kind of recipe is it?" << std::endl; //Begin add recipe menu
    std::cout << "1 - Breakfast" << std::endl;
    std::cout << "2 - Lunch" << std::endl;
    std::cout << "3 - Dinner" << std::endl;
    std::cout << "4 - Dessert" << std::endl;
    std::cout << "q - Back to main menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose an option:" << std::endl;

    std::cin >> option; //ask user for an option
    UserOptionAdd(list, option); //passes list and the option to function
}

void UserOptionAdd(RecipeList *list, char option) { //function to call appropriate menu option
    bool validOption = false; //set false for first instance so it can go into loop
    while (!validOption) { //if false go into loop, will only exit if correct option is chosen
        switch (option) {  //switch case for easy option integration
            case '1':
                validOption = true; //to exit loop after functions are called if switch case matches
                NewBreakfastRecipe(list);
                //std::cout << "This is option 1" << std::endl;//TODO testing option only
                break;

            case '2':
                validOption = true;
                NewLunchRecipe(list);
                // std::cout << "This is option 2" << std::endl;//TODO testing option only
                break;

            case '3':
                NewDinnerRecipe(list);
                validOption = true;
                //  std::cout << "This is option 3" << std::endl;//TODO testing option only
                break;

            case '4':
                NewDessertRecipe(list);
                validOption = true;
                // std::cout << "This is option 4" << std::endl;//TODO testing option only
                break;

            case 'q': //quits the program
            case 'Q':
                validOption = true;
                break;

            default:
                std::cout << "Please select a valid option:" << std::endl;
                std::cin >> option;
        }
    }
}

#endif //RECIPES_ADDRECIPEMENU_H
