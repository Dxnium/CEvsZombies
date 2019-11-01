//
// Created by danium on 29/10/19.
//

#include "Zombies.h"
#include <iostream>
Zombies::Zombies(int vida , int defense) {
    this->vida = vida;
    this->defense=defense;
}

int Zombies::getposX() {
    return x;
}

int Zombies::getposY() {
    return y;
}

void Zombies::setposX(int x) {
    this->x = x;
}

void Zombies::setposY(int y) {
    this->y = y;
}







