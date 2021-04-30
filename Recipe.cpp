//
// Created by Ekyso on 4/16/2021.
//

#include <iostream>
#include "Recipe.h"


Recipe::Recipe() {
    type = {};
    nameOfRecipe = "";
    description = "";
    ingredients = {};
    steps = {};
}

Recipe::Recipe(recipeType type, std::string name, std::string desc, std::vector<std::string> ingredients,
               std::vector<std::string> steps) {
    this->type = type;
    nameOfRecipe = std::move(name);
    description = std::move(desc);
    this->ingredients = std::move(ingredients);
    this->steps = std::move(steps);

}

void Recipe::PrintRecipe() {
    int i;
    std::cout << "Name: " << nameOfRecipe << std::endl;
    std::cout << "Description: " << description << std::endl << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (i = 0; i < ingredients.size(); i++ ) {
        std::cout << ingredients.at(i) << std::endl;
    }
    std::cout << std::endl << "Steps:" << std::endl;
    for (i = 0; i < steps.size(); i++) {
        std::cout << steps.at(i) << std::endl;
    }
}

void Recipe::save(std::ostream &out) {
    int i;
    out << "Name: " << nameOfRecipe << std::endl;
    out << "Description: " << description << std::endl << std::endl;
    out << "Ingredients:" << std::endl;
    for (i = 0; i < ingredients.size(); i++ ) {
        out << ingredients.at(i) << std::endl;
    }
    out << std::endl;
    out << "Steps:" << std::endl;
    for (i = 0; i < steps.size(); i++) {
        out << steps.at(i) << std::endl;
    }
    out << "********************" << std::endl;
}
