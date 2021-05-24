//
// Created by Ekyso on 4/16/2021.
//

#ifndef RECIPES_RECIPE_H
#define RECIPES_RECIPE_H
#include <string>
#include <vector>


class Recipe {
public:
    enum class recipeType {breakfast, lunch, dinner, dessert};
    Recipe();
    Recipe(recipeType type, std::string name, std::string desc, std::vector<std::string> ingredients, std::vector<std::string> steps);
    Recipe(std::string name, std::string desc, std::vector<std::string> ingredients, std::vector<std::string> steps);
    void PrintRecipe();
    void save(std::ostream &out);
    recipeType GetType() {return type;};
private:
    recipeType type;
    std::string nameOfRecipe;
    std::string description;
    std::vector<std::string> ingredients;
    std::vector<std::string> steps;
};


#endif //RECIPES_RECIPE_H
