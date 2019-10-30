//
// Created by danium on 29/10/19.
//

#include "Zombies.h"
#include <iostream>
Zombies::Zombies(int vida , int defense,QWidget *parent) : QLabel(parent) {
    setMovie(elfMovie);
    setAttribute(Qt::WA_TranslucentBackground);
}

Zombies::~Zombies(void){
    std::cout<<"deleting"<<std::endl;
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







