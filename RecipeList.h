//
// Created by Ekyso on 4/16/2021.
//

#ifndef RECIPES_RECIPELIST_H
#define RECIPES_RECIPELIST_H
#include <string>
#include <vector>
#include "Recipe.h"
#include <sstream>

class RecipeList {
public:
    RecipeList();
    ~RecipeList();
    void PrintRecipes(char option);
    void AddRecipe(Recipe &recipes);
    void SaveFile();
    void LoadFile();
    void CreateRecipeFromLoad(std::istream &in, Recipe::recipeType type);
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
     std::string separator2;
     std::ostringstream breakfastHeader2, lunchHeader2, dinnerHeader2, dessertHeader2; //FIXME not filling asterisks correctly
     std::ostringstream separator;
     char separatingChar;

};


#endif //RECIPES_RECIPELIST_H
