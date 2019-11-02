//
// Created by danium on 29/10/19.
//

#ifndef CEVSZOMBIES_ZOMBIES_H
#define CEVSZOMBIES_ZOMBIES_H


class Zombies {
public:
    int vida;
    int counterPos =1;
    int x=100;
    int y= (9 * 70)-20;
    bool moving = false;
    bool arrivedX= false;
    bool arrivedY= false;
    Zombies();
    ~Zombies();
};


#endif //CEVSZOMBIES_ZOMBIES_H
