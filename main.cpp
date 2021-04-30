#include <iostream>
#include "MainMenu.h"
#include <vector>

int main() {
    RecipeList list1;
    std::cout << "Welcome to your recipe log!" << std::endl;
    MainMenu(&list1); //call printmenu

    /***
     * Below is only used for testing purposes.
     */

//    std::vector<std::vector<RecipeList>> doubleVector;
//    RecipeList list2;
//    std::vector<std::string> ingredients1 = {"Eggs"};
//    std::vector<std::string> steps1 = {"Cook the eggs"};
//    Recipe recipe1(Recipe::recipeType::breakfast,"eggs","just eggs",ingredients1,steps1);
//    list2.AddRecipe(recipe1);
//    std::vector<std::string> ingredients2 = {"Bacon"};
//    std::vector<std::string> steps2 = {"Heat Skillet","Cook the bacon until done"};
//    Recipe recipe2(Recipe::recipeType::breakfast,"Bacon","Delicious Bacon",ingredients2,steps2);
//    list2.AddRecipe(recipe2);
//    MainMenu(&list2);


    return 0;
}

