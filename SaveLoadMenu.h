//
// Created by Ekyso on 4/30/2021.
//

#ifndef RECIPES_SAVELOADMENU_H
#define RECIPES_SAVELOADMENU_H
#include <iostream>
#include <fstream>

void SaveToFile(RecipeList *list) {
    std::string fileName;
    std::cout << "File name:" << std::endl;
    std::cin >> fileName;
    std::ofstream outFile;
    outFile.open(fileName+=".txt");
    list->SaveFile(outFile);
    outFile.close();
}

void LoadFromFile(RecipeList *list) {
    std::string fileName, tmpStr;
    std::cout << "File name:" << std::endl;
    std::cin >> fileName;
    std::ifstream inFile;
    while (getline(inFile,tmpStr)) {
        if (inFile.eof()) {
            break;
        }
        else {
            if (tmpStr == list->GetBreakfastHeader()) {

            }
            else if (tmpStr == list->GetLunchHeader()) {

            }
            else if (tmpStr == list->GetDinnerHeader()) {

            }
            else if (tmpStr == list->GetDessertHeader()) {

            }
        }
    }

}

#endif //RECIPES_SAVELOADMENU_H
