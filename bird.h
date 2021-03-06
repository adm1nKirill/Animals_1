
#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <fstream>
#include "animal.h"

struct bird {
    enumAnimal TYPE; // Тип животного
    std::string name; // Имя животного
    int age; // Возраст
    bool is_migratory; // Перелетная ли птица
};

bool readB(std::ifstream& ifs, bird *b);
void outB(std::ofstream& ofs, bird *b);

#endif //BIRD_H
