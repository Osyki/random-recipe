//
// Created by Ekyso on 4/30/2021.
//

#ifndef RECIPES_SAVELOADMENU_H
#define RECIPES_SAVELOADMENU_H
#include <iostream>
#include <fstream>

//void SaveToFile(RecipeList *list) {
//    std::string fileName; //create fileName string
//    std::ofstream outFile;// create buffer to be saved
//
//    std::cout << "File name:" << std::endl; //print file name:
//    std::cin >> fileName; //ask user for file name
//    outFile.open(fileName+=".txt"); //create file and append .txt to end #FIXME: check if user entered .txt
//    list->SaveFile(outFile); //send created buffer to list object's SaveFile method
//    outFile.close(); //close the file
//}

void LoadFromFile(RecipeList *list) {
    std::string fileName, tmpStr; //filename and tmpStr to hold line from file
    std::cout << "File name:" << std::endl; //print
    std::cin >> fileName; //ask user for input
    std::ifstream inFile; //create infile buffer object
    while (getline(inFile,tmpStr)) { //while reading each line in file
        if (inFile.eof()) { //if it gets to end of file
            break; //break
        }
        else {
            if (tmpStr == list->GetBreakfastHeader()) { //if the tmpStr line matches the breakfast header
                //FIXME do some code
            }
            else if (tmpStr == list->GetLunchHeader()) { //else if tmpStr line matches the lunch header
                //FIXME do some code
            }
            else if (tmpStr == list->GetDinnerHeader()) { //else if tmpStr line matches the dinner header
                //FIXME do some code
            }
            else if (tmpStr == list->GetDessertHeader()) { //else if tmpStr line matches the dessert header
                //FIXME do some code
            }
        }
    }

}

#endif //RECIPES_SAVELOADMENU_H
