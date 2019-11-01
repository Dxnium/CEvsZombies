//
// Created by danium on 30/10/19.
//

#ifndef CEVSZOMBIES_GENETIC_H
#define CEVSZOMBIES_GENETIC_H

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include "Zombies.h"



using namespace std;
class Genetic {
public:


    //array de la poblacion de los zombies
    Zombies population[10];
    //array con los 3 mejores zombies
    Zombies top_population[3];


    int Generation;

    void mutated_genes();



    // Function to generate random numbers in given range
    int random_num(int start, int end);

    //Generate a Zombie
    Zombies create_Zombie();
    //Function to generate a population
    void create_Population();

    //Define fitness for all population
    void define_Fitness();


};


#endif //CEVSZOMBIES_GENETIC_H
