//
// Created by Ekyso on 4/16/2021.
//

#ifndef RECIPES_RECIPELIST_H
#define RECIPES_RECIPELIST_H
#include <string>
#include <vector>
#include "Recipe.h"

class RecipeList {
public:
    RecipeList();
    void PrintRecipes(char option);
    void AddRecipe(Recipe &recipes);
    void SaveFile();
    std::string GetBreakfastHeader() {return breakfastHeader;};
    std::string GetLunchHeader() {return lunchHeader;};
    std::string GetDinnerHeader() {return dinnerHeader;};
    std::string GetDessertHeader() {return dessertHeader;};
private:
    std::vector<std::vector<Recipe>> recipeList2D;
    /**
     * recipeList2D is set up this way:
     * 0 - Breakfast
     * 1 - Lunch
     * 2 - Dinner
     * 3 - Dessert
     */
     std::string breakfastHeader, lunchHeader, dinnerHeader, dessertHeader; //headers for loading/saving
     std::string separator;
};


#endif //RECIPES_RECIPELIST_H
