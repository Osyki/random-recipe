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
        for (auto & i : recipeList) {
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '3') {
        for (auto & i : breakfastList) {
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '4') {
        for (auto & i : lunchList) {
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '5') {
        for (auto & i : lunchList) {
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

    if (option == '6') {
        for (auto & i : dessertList) {
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << "********************" << std::endl;
        }
    }

}

void RecipeList::AddRecipe(Recipe &recipes) {
    recipeList.push_back(recipes);
    if (recipes.GetType() == Recipe::recipeType::breakfast) {
        breakfastList.push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::lunch) {
        lunchList.push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::dinner) {
        dinnerList.push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::dessert) {
        dessertList.push_back(recipes);
    }
}

RecipeList::RecipeList() {
    recipeList = {};
}
