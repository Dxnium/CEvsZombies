//
// Created by danium on 29/10/19.
//

#ifndef CEVSZOMBIES_ZOMBIES_H
#define CEVSZOMBIES_ZOMBIES_H

#include <QApplication>
#include <QLabel>
#include <QMovie>

class Zombies{
public:
    //Constructor
    Zombies(int vida, int defense);

    //Caracteristicas
    int vida;
    int defense;
    int x;
    int y;
    int fitness;

    //Movie for the label
    QMovie *elfMovie = new QMovie("/home/danium/Documents/TEC/Datos II/Proyecto II/CEvsZombies/Images/elf.gif");

    //get and set positions
    int getposX();
    int getposY();
    void setposX(int x);
    void setposY(int y);


};


#endif //CEVSZOMBIES_ZOMBIES_H
