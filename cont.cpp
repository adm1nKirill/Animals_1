
#include "cont.h"

void Read(std::ifstream &ifs, cont &q) {
    while(!ifs.eof()) { // Пока есть что считывать
        animal *A = ReadA(ifs); // Функция возвращает считанные данные
        if(A==NULL) {
            Clear(q);
            std::cout << "Error reading file structure.\n";
            return;
        }
        Add(A, q); // Сохраняем в контейнер
    }
}

void Add(animal *A, cont&q) {
    q.size++;
    if(q.first == nullptr) { // Если контейнер пуст
        q.first = A;
        A->prev = A->next = A;
    } else {
        // Связываем A с предыдущим
        (q.first->prev)->next = A;
        A->prev = (q.first->prev);
        // Связываем A с последующим
        q.first->prev = A;
        A->next = q.first;
    }
}

void Init(cont &cont) {
    cont.first = NULL;
    cont.size = 0;
}

void Clear(cont &q) {
    animal *A = q.first;
    for(int i = 0; i < q.size; i++) {
        animal *deleting = A;
        A = A->next;
        delete deleting;
    }
    q.size = 0;
}

void Out(std::ofstream &ofs, cont &q) {
    animal *A = q.first;
    for(int i = 1; i <= q.size; i++) {
        ofs << i << ". ";
        OutA(ofs, A);
        A = A->next;
    }
}