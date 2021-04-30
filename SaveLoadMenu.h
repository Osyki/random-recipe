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

#endif //RECIPES_SAVELOADMENU_H
