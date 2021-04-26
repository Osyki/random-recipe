cmake_minimum_required(VERSION 3.19)
project(recipes)

set(CMAKE_CXX_STANDARD 14)

add_executable(recipes main.cpp MainMenu.h AddRecipeMenu.h NewRecipes.h RecipeList.cpp RecipeList.h Recipe.cpp Recipe.h DisplayRecipeMenu.h)