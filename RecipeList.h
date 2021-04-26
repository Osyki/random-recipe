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

private:
    std::vector<Recipe> recipeList;
    std::vector<Recipe> breakfastList;
    std::vector<Recipe> lunchList;
    std::vector<Recipe> dinnerList;
    std::vector<Recipe> dessertList;
};


#endif //RECIPES_RECIPELIST_H
