//
// Created by danium on 30/10/19.
//

#ifndef CEVSZOMBIES_GENETIC_H
#define CEVSZOMBIES_GENETIC_H

#include <bits/stdc++.h>
#include <iostream>
#include "Zombies.h"



using namespace std;
class Genetic {

    Zombies poblacion[10];
    int Generation;
    const string GENES = "";

    char mutated_genes();
    string create_gnome();



    // Function to generate random numbers in given range
    int random_num(int start, int end);


};


#endif //CEVSZOMBIES_GENETIC_H
