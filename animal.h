
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <fstream>
#include "string"

// Перечисляемый тип - тип животного
enum enum_animal {
    FISH,
    BIRD,
};

// Животные
struct animal {
    animal *next; // Последующий элемент
    animal *prev; // Предыдущий  элемент
    enum_animal tr_type; // Тип животного
    std::string name; // Имя животного
};

animal* ReadA(std::ifstream&ifs);
void OutA(std::ofstream& ofs, animal*A);

#endif //ANIMAL_H