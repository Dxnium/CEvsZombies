//
// Created by danium on 30/10/19.
//

#include "Genetic.h"


void Genetic::mutated_genes() {

}



int Genetic::random_num(int start, int end) {
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

void Genetic::create_Population() {
    for(int i=0;i<10;i++){
        population[i] = create_Zombie();
    }
    for(int i=0;i<3;i++){
        top_population[i] = population[i];
    }
}

Zombies Genetic::create_Zombie() {
    return Zombies(random_num(0,100), random_num(0,100));
}

void Genetic::define_Fitness() {
    for(int i=0;i<10;i++) {
        int x = population[i].x;
        int y = population[i].y;
        float fitness = sqrt(pow(x, 2) + pow(y, 2));
        population[i].fitness = fitness;

        for(i=0;i<3;i++){
            int actual = top_population[i].fitness;
            if (fitness<actual){
                top_population[i] = population[i];
                break;
            }
        }
    }


}




