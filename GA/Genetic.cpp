//
// Created by danium on 30/10/19.
//

#include "Genetic.h"


char Genetic::mutated_genes() {
    return 0;
}

string Genetic::create_gnome() {
    return std::__cxx11::string();
}

int Genetic::random_num(int start, int end) {
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}