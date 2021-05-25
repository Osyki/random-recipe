//
// Created by Ekyso on 4/16/2021.
//

#ifndef RECIPES_NEWRECIPES_H
#define RECIPES_NEWRECIPES_H
#include <vector>
#include "Recipe.h"
#include "RecipeList.h"

void NewRecipe(RecipeList *list, Recipe::recipeType type) {

    std::string name, desc, tmpStr;
    std::vector<std::string> ingredients;
    std::vector<std::string> steps;

    std::cout << "Enter name of recipe:" << std::endl;
    std::cin.ignore();
    getline(std::cin, name);

    std::cout << "Enter description of recipe:" << std::endl;
    getline(std::cin, desc);

    std::cout << "Enter the ingredients, type -1 when finished" << std::endl;
    getline(std::cin,tmpStr);
    while (tmpStr != "-1") {
        ingredients.push_back(tmpStr);
        getline(std::cin,tmpStr);
    }

    std::cout << "Enter the steps, type -1 when finished" << std::endl;
    int count = 1;
    while (getline(std::cin,tmpStr)) {
        std::ostringstream oss;
        if (tmpStr == "-1")
            break;
        oss << count << ".) " << tmpStr;
        std::string tempString = oss.str();
        std::cout << tempString << std::endl;
        steps.push_back(oss.str());
        count++;
    }

    Recipe tmpRecipe(type,name,desc,ingredients,steps); //Create recipe object
    list->AddRecipe(tmpRecipe);
/*    Used to test vectors */
//    std::cout << "Testing ingredients" << std::endl;
//    for (auto & ingredient : ingredients) {
//        std::cout << ingredient << std::endl;
//    }
//
//    std::cout << "Testing steps" << std::endl;
//    for (auto & step : steps) {
//        std::cout << step << std::endl;
//    }

}


void NewBreakfastRecipe(RecipeList *list) {
    NewRecipe(list, Recipe::recipeType::breakfast);
}

void NewLunchRecipe(RecipeList *list) {
    NewRecipe(list,Recipe::recipeType::lunch);
}

void NewDinnerRecipe(RecipeList *list) {
    NewRecipe(list,Recipe::recipeType::dinner);
}
void NewDessertRecipe(RecipeList *list) {
    NewRecipe(list,Recipe::recipeType::dessert);
}

#endif //RECIPES_NEWRECIPES_H
