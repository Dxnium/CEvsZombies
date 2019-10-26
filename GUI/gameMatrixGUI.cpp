//
// Created by smz on 25/10/19.
//

#include "gameMatrixGUI.h"
#include "gameMatrixGUI.h"

#include <QPainter>
#include <QTime>
#include <iostream>
#include<bits/stdc++.h>
#include <random>
//#include "Bresenham.h"
using namespace std;


gameMatrixGUI::gameMatrixGUI(QWidget *parent) : QWidget(parent) {

    setStyleSheet("background-color:white;");
    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;
    elfLabel->setAttribute(Qt::WA_TranslucentBackground);
    resize(B_WIDTH, B_HEIGHT);
    //getDimensions(B_WIDTH,B_HEIGHT);
    loadImages();
    initGame();

}

void gameMatrixGUI::loadImages() {
    elfLabel->setMovie(elfMovie);
    elfMovie->start();
    //gameMatrixGUIImg.load("/home/smz/CLionProjects/pathfinding/Images/helmet.png");
    /*
    for(int i= 0; i<19; i++) {
        crusader crusader;
        crusaderList[i] = crusader;

        crusaderList[i].crusaderImg.load("/home/smz/CLionProjects/pathfinding/Images/crusader.png");


    }
    **/
    //shieldImg.load("/home/smz/CLionProjects/pathfinding/Images/shield.png");
}

void gameMatrixGUI::initGame() {


    x = 30;
    y = (ROW * 70)-20;
    locateShield();
    locateCrusader();


    timerId = startTimer(DELAY);
}

void gameMatrixGUI::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    doDrawing();
}
void gameMatrixGUI::getDimensions(int dimX, int dimY) {

    maxDivX = dimX / squareSize;
    maxDivY = dimY / squareSize;
    cout<<"MAX en X:"<<maxDivX<<endl;
    cout<<"MAX en Y:"<<maxDivY<<endl;

}

void gameMatrixGUI::doDrawing() {

    QPainter qp(this);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    qp.setPen(pen);
    for(int c = 0; c < COL;c++){
        for(int f = 0; f< ROW;f++){
            if(AStar.grid[f][c] == 1) {
                qp.drawRect((c * squareSize)+100, (f * squareSize)+20, squareSize, squareSize);
            }else{

                qp.fillRect((c * squareSize)+100, (f * squareSize)+20, squareSize, squareSize,Qt::green);
                qp.drawRect((c * squareSize)+100, (f * squareSize)+20, squareSize, squareSize);
            }
        }
    }

    if (inGame) {
        /*
        for(int i= 0; i<19; i++) {
            crusaderList[i].crusaderRect.setRect(crusaderList[i].posX,crusaderList[i].posY,squareSize,squareSize);
            qp.fillRect(crusaderList[i].posX,crusaderList[i].posY,squareSize,squareSize,Qt::green);
            crusaderList[i].crusaderImg.scaled(10,10,Qt::KeepAspectRatio);
            qp.drawImage(crusaderList[i].posX,crusaderList[i].posY,crusaderList[i].crusaderImg);

        }

        qp.drawImage(shieldImg_x,shieldImg_y,shieldImg);
        gameMatrixGUIRect.setRect(x+10,y,30,squareSize);
        qp.fillRect(x+20,y,30,squareSize,Qt::cyan);

        qp.drawImage(x, y, gameMatrixGUIImg);
        */
        elfLabel->setGeometry(x, y, 100,100);

    } else {

        gameOver(qp);
    }
}

void gameMatrixGUI::gameOver(QPainter &qp) {

    QString message = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}

void gameMatrixGUI::checkPositions() {
    for(int i = 0; i<19;i++) {
        /*
        if (crusaderList[i].crusaderRect.intersects(gameMatrixGUIRect)) {
            //cout << "Chocoooooooooooo" << endl;
            int num = (rand() % 20) + 1;
            x = x + num;
            int num2 = (rand() % 20) + 1;
            y= y + num2;
            //locateCrusader();
        }
        **/
    }
    if(shieldRect.intersects(gameMatrixGUIRect)){
        locateShield();
    }
}

void gameMatrixGUI::move() {
    if(shieldImg_x > x){
        x += DOT_SIZE;

    }else {
        if(shieldImg_x == x){

        }else{
            x -= DOT_SIZE;
        }
    }
    if(shieldImg_y > y){
        y += DOT_SIZE;

    }else {
        if(shieldImg_y == y){

        }else{
            y -= DOT_SIZE;
        }
    }


}

void gameMatrixGUI::checkCollision() {

    if (y < 0) {
        x = 300;
        y = 600;
    }

}

void gameMatrixGUI::locateCrusader() {

    for (int i = 0; i < 15; ++i) {
        for(int n = 0; n<15 ; n++) {
            int num = (rand() % 10) + 1;
            mapMatrix[n][i] = num;
        }
    }
    int counter =0;
    for (int i = 0; i < 15; i++) {
        for(int n = 0; n<15 ; n++) {
            if( mapMatrix[n][i] == 7){

                if(counter < 19) {
                    /**
                    crusaderList[counter].posX = (n * 50);
                    crusaderList[counter].posY = (i * 50);
                     */
                    counter++;
                    break;
                }
            }


        }
    }



}
int gameMatrixGUI::generateRnd(){
    int num = (rand() % 500) + 1;
    return num;
}

void gameMatrixGUI::locateShield() {


    int randX;
    int randY;
    for(int i =0; i < 19; i++) {
        randX = generateRnd();
        randY = generateRnd();
        /**
        if(!crusaderList[i].crusaderRect.contains(randX, randY)) {
            shieldRect.setRect(randX,randY,25,25);
            shieldImg_x = randX;

            shieldImg_y = randY;
        }
         */
    }



}

void gameMatrixGUI::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) {
        /*
        checkPositions();
        checkCollision();
        int dx, dy, p, x_b, y_b;

        dx=shieldImg_x-x;
        dy=shieldImg_y-y;

        p=2*dy-dx;
        if(x<shieldImg_x)
        {

            if(p>=0)
            {
                //std::cout<<"("<<x<<","<<y<<")"<<std::endl;
                y=y+DOT_SIZE;
                p=p+2*dy-2*dx;
            }
            else
            {
                //std::cout<<"("<<x<<","<<y<<")"<<std::endl;
                p=p+2*dy;
            }
            x=x+DOT_SIZE;
        }
        //move();
        repaint();
         */
    }




}

void gameMatrixGUI::mouseDoubleClickEvent(QMouseEvent *event) {
    x = event->x();
    y= event->y();
};
