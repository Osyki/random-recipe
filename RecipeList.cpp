//
// Created by Ekyso on 4/16/2021.
//

#include <iostream>
#include "RecipeList.h"
#include <fstream>
#include "CenterMiddleHelperClass.h"

//RecipeList::RecipeList(const Recipe recipes) {
//    recipeList.push_back(recipes);
//}

void RecipeList::PrintRecipes(const char option) {
    if (option == '1') {
        for (auto & i : recipeList2D) { //cycle through vector that holds the individual recipe vectors
            for (auto & j : i) { //for every recipe in recipe vector
                std::cout << separator.str();
                std::cout << std::endl;
                j.PrintRecipe(); //print recipe
            }
        }
        std::cout << separator.str();
    }

    if (option == '3') {
        for (auto & i : recipeList2D.at(0)) { //for every recipe in list // 0 = breakfast
            std::cout << std::endl;
            i.PrintRecipe(); //print recipe
            std::cout << std::endl << separator.str() << std::endl;
        }
    }

    if (option == '4') {
        for (auto & i : recipeList2D.at(1)) { //1 = lunch
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << separator.str() << std::endl;
        }
    }

    if (option == '5') {
        for (auto & i : recipeList2D.at(2)) { // 2 = dinner
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << separator.str() << std::endl;
        }
    }

    if (option == '6') {
        for (auto & i : recipeList2D.at(3)) { // 3 = dessert
            std::cout << std::endl;
            i.PrintRecipe();
            std::cout << std::endl << separator.str() << std::endl;
        }
    }

}

void RecipeList::AddRecipe(Recipe &recipes) {
    if (recipes.GetType() == Recipe::recipeType::breakfast) {
        recipeList2D.at(0).push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::lunch) {
        recipeList2D.at(1).push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::dinner) {
        recipeList2D.at(2).push_back(recipes);
    }
    if (recipes.GetType() == Recipe::recipeType::dessert) {
        recipeList2D.at(3).push_back(recipes);
    }
}

RecipeList::RecipeList() {
    recipeList2D.resize(4); //currently set to 4 for breakfast, lunch, dinner, dessert
    separatingChar = '-';
    breakfastHeader = "Breakfast Recipes";
    breakfastHeader2 << std::setw(50) << std::setfill(separatingChar) << centered(breakfastHeader);
    lunchHeader = "Lunch Recipes";
    lunchHeader2 << std::setw(50) << std::setfill(separatingChar) << centered(lunchHeader);
    dinnerHeader = "Dinner Recipes";
    dinnerHeader2 << std::setw(50) << std::setfill(separatingChar) << centered(breakfastHeader);
    dessertHeader = "Dessert Recipes";
    dessertHeader2 << std::setw(50) << std::setfill(separatingChar) << centered(breakfastHeader);
    separator2 = "********************"; //change this to change separator in save/load file
    separator << std::setw(50) << std::setfill(separatingChar)  << "";
    LoadFile();
}

/**
    * recipeList2D is set up this way:
    * 0 - Breakfast
    * 1 - Lunch
    * 2 - Dinner
    * 3 - Dessert
    */
void RecipeList::SaveFile() {
    std::string fileName; //create fileName string
    std::ofstream outFile;// create buffer to be saved

    std::cout << "File name:" << std::endl; //print file name:
    std::cin >> fileName; //ask user for file name

    //checks to see if .txt is added by user, if not found add it
    if ((fileName.length() > 4) && (fileName.substr(fileName.size()-4,fileName.size()-1)) != ".txt") {
        fileName += ".txt";
    }
    else if (fileName.length() < 4 ){
        fileName += ".txt";
    }

    //create file
    outFile.open(fileName); //create file and append .txt to end
    for (int i = 0; i < recipeList2D.size(); i++) { //for every option in recipe list
        switch (i) { //change headers in constructor
            case 0: //first vector in 2d vector is breakfast
                outFile << separator.str() << std::endl;
                outFile << breakfastHeader2.str() << std::endl; //save header to file
                outFile << separator.str() << std::endl;
                break; //break after writing header to file
            case 1:
                outFile << lunchHeader2.str() << std::endl;
                outFile << separator.str() << std::endl;
                break;
            case 2:
                outFile << dinnerHeader2.str() << std::endl;
                outFile << separator.str() << std::endl;
                break;
            case 3:
                outFile << dessertHeader2.str() << std::endl;
                outFile << separator.str() << std::endl;
            default:
                break;
        }

        for (auto & j : recipeList2D.at(i)) { //for every recipe in vector[i]
            //FIXME: need to create a function that returns an object and writes to the outfile, move from recipe to recipeList
            j.save(outFile); //send outFile to save function inside recipe
            outFile << separator.str() << std::endl;
        }
    }
    outFile.close(); //close the file
}

void RecipeList::LoadFile() {
    char userOption;
    bool validOption = false;
    std::cout << "Load from file? (Y/n)" << std::endl;

    while (!validOption) { //testing if gitignore is working for cmakefiles
        std::cin >> userOption;
        userOption = char(std::tolower(userOption)); //convert to lowercase
        if (userOption == 'y') {
            validOption = true;
            std::string fileName, tmpStr; //filename and tmpStr to hold lines from file
            std::cout << "File name:" << std::endl; //print
            std::cin >> fileName; //ask user for input
            std::ifstream inFile; //create infile buffer object
            inFile.open(fileName); //open filename given, must be exact match TODO: check .txt
            while (getline(inFile,tmpStr)) { //while reading each line in file
                    if (tmpStr == breakfastHeader2.str()) { //if the tmpStr line matches the breakfast header
                        //FIXME do some code
                            CreateRecipeFromLoad(inFile,Recipe::recipeType::breakfast);
                    } else if (tmpStr == lunchHeader2.str()) { //else if tmpStr line matches the lunch header
                        //FIXME do some code
                            CreateRecipeFromLoad(inFile,Recipe::recipeType::lunch);

                    } else if (tmpStr == dinnerHeader2.str()) { //else if tmpStr line matches the dinner header
                        //FIXME do some code
                            CreateRecipeFromLoad(inFile,Recipe::recipeType::dinner);

                    } else if (tmpStr == dessertHeader2.str()) { //else if tmpStr line matches the dessert header
                        //FIXME do some code
                        CreateRecipeFromLoad(inFile,Recipe::recipeType::dessert);
                    }
                if (inFile.peek() == EOF) //if next char is EOF
                    break; //break
            }
        }
        else if (userOption == 'n') {
            validOption = true;
        }
        else {
            std::cout << "Please enter 'y' or 'n':" << std::endl;
        }
    }

}

RecipeList::~RecipeList() {
    SaveFile();
}

void RecipeList::CreateRecipeFromLoad(std::istream &in, Recipe::recipeType type) {
    std::string tmpStr;
    std::getline(in,tmpStr);
    while (in.peek() != separatingChar) {
        std::string name, description;
        std::vector<std::string> ingredients, steps;
        in >> tmpStr; //erase "Name:"
        std::getline(in,name);
        in >> tmpStr; //erase "Description: "
        std::getline(in,description);
        in >> tmpStr; //erase "Ingredients:"
        while (std::getline(in,tmpStr)) {
            if (tmpStr == "Steps:" || in.eof()) {
                break;
            }
            if (!tmpStr.empty()) {
                ingredients.push_back(tmpStr);
            }

        }
        while (std::getline(in,tmpStr)) {
            if (!tmpStr.empty()) {
                steps.push_back(tmpStr);
            }
            if (in.peek() == separatingChar) {
                std::getline(in,tmpStr);
                break;
            }
        }
        Recipe createdRecipe(type,name,description,ingredients,steps);
        AddRecipe(createdRecipe);
    }
}
