//
// Created by danium on 1/11/19.
//

#include "Wepon.h"


    //pixmap = new QPixmap("/home/danium/Desktop/sprotes/craftpix-901177-free-2d-battle-tank-game-assets/PNG/Hulls_Color_A/Hull_01.png");

Wepon::Wepon(int x, int y) {
    this->posX = x;
    this->posY = y;
    pixmap = new QPixmap("/home/danium/Desktop/sprotes/craftpix-901177-free-2d-battle-tank-game-assets/PNG/Hulls_Color_A/Hull_01.png");
}
