#include <iostream>
#include "MainMenu.h"
#include <vector>
#include <iomanip>

int main() {
    RecipeList list1;
    MainMenu(&list1); //call printmenu

    /***
     * Below is only used for testing purposes.
     */

//    std::vector<std::vector<RecipeList>> doubleVector;
//    RecipeList list2;
//    std::vector<std::string> ingredients1 = {"Eggs"};
//    std::vector<std::string> steps1 = {"1.) Cook the eggs"};
//    Recipe recipe1(Recipe::recipeType::breakfast,"eggs","just eggs, this is a really long description just to see if the justification is working. BLah blah blah blah blah blah.",ingredients1,steps1);
//    list2.AddRecipe(recipe1);
//    std::vector<std::string> ingredients2 = {"Bacon"};
//    std::vector<std::string> steps2 = {"1.) Heat Skillet","2.) Cook the bacon until done"};
//    Recipe recipe2(Recipe::recipeType::breakfast,"Bacon","Delicious Bacon",ingredients2,steps2);
//    list2.AddRecipe(recipe2);
//
//    std::vector<std::string> ingredients3 = {"Ham", "Cheese", "Bread"};
//    std::vector<std::string> steps3 = {"1.) Put everything together","2.) Enjoy!"};
//    Recipe recipe3(Recipe::recipeType::lunch,"Ham and cheese sandwich","Easiest sandwich when hungry",ingredients3,steps3);
//    list2.AddRecipe(recipe3);
//
//    std::vector<std::string> ingredients4 = {"Turkey", "Stuffing"};
//    std::vector<std::string> steps4 = {"1.) Heat the oven","2.) Cook the turkey and stuff when done"};
//    Recipe recipe4(Recipe::recipeType::dinner,"Baked Turkey","Delicious Thanksgiving dinner",ingredients4,steps4);
//    list2.AddRecipe(recipe4);
//
//    std::vector<std::string> ingredients5 = {"Flour", "Sugar", "Butter"};
//    std::vector<std::string> steps5 = {"1.) Preheat oven","2.) Mix everything together", "3.) Put in oven and wait"};
//    Recipe recipe5(Recipe::recipeType::dessert,"Best cake ever","Delicious buttery flavor",ingredients5,steps5);
//    list2.AddRecipe(recipe5);
//
//    MainMenu(&list2);


    return 0;
}

