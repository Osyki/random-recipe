//
// Created by Ekyso on 4/16/2021.
//

#include <iostream>
#include "RecipeList.h"

//RecipeList::RecipeList(const Recipe recipes) {
//    recipeList.push_back(recipes);
//}

void RecipeList::PrintRecipes(const char option) {
    std::cout << std::endl << "********************" << std::endl;
    if (option == '1') {
        for (auto & i : recipeList2D) { //cycle through vector that holds the categorized lists
            for (auto & j : i) { //for every recipe in list
                std::cout << std::endl; //newline
                j.PrintRecipe(); //print recipe
                std::cout << std::endl << "********************" << std::endl; //used to separate
            }
        }
    }

    if (option == '3') {
        for (auto & i : recipeList2D.at(0)) { //for every recipe in list // 0 = breakfast
            std::cout << std::endl;
            i.PrintRecipe(); //print recipe
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '4') {
        for (auto & i : recipeList2D.at(1)) { //1 = lunch
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '5') {
        for (auto & i : recipeList2D.at(2)) { // 2 = dinner
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '6') {
        for (auto & i : recipeList2D.at(3)) { // 3 = dessert
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

}

void RecipeList::AddRecipe(Recipe &recipes) {
    if (recipes.GetType() == Recipe::recipeType::breakfast) {
        recipeList2D.at(0).push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::lunch) {
        recipeList2D.at(1).push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::dinner) {
        recipeList2D.at(2).push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::dessert) {
        recipeList2D.at(3).push_back(recipes);
    }
}

RecipeList::RecipeList() {
    recipeList2D.resize(4); //currently set to 4 for breakfast, lunch, dinner, dessert
    breakfastHeader = "---Breakfast Recipes---";
    lunchHeader = "---Lunch Recipes---";
    dinnerHeader = "---Dinner Recipes---";
    dessertHeader = "---Dessert Recipes---";
}

void RecipeList::SaveFile(std::ostream &out) {
    for (int i = 0; i < recipeList2D.size(); i++) {
        switch (i) {
            case 0:
                out << breakfastHeader << std::endl;
                break;
            case 1:
                out << lunchHeader << std::endl;
                break;
            case 2:
                out << dinnerHeader << std::endl;
                break;
            case 3:
                out << dessertHeader << std::endl;
            default:
                break;
        }
        for (auto & j : recipeList2D.at(i)) {
            j.save(out);
        }
    }
}
