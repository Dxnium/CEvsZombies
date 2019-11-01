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
#include <QtWidgets/QApplication>
//#include "Bresenham.h"
using namespace std;


gameMatrixGUI::gameMatrixGUI(QWidget *parent) : QWidget(parent) {

    resize(600, 500);
    textLabel = new QLabel("Modos de juego: ", this);
    textLabel->setGeometry(200,100,150,50);
    btn_Infinity->setStyleSheet("background-color: rgb(181,56,56);border: none; ");
    btn_Infinity->setGeometry(200,200,200,20);
    connect(btn_Infinity, &QPushButton::clicked, this, &gameMatrixGUI::Action);



    btn_noInfinity->setStyleSheet("background-color: rgb(0,147,56);border: none; ");
    btn_noInfinity->setGeometry(200,300,200,20);
    connect(btn_noInfinity, &QPushButton::clicked, this, &gameMatrixGUI::Action);


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


    x =100;
    y = (ROW * 70)-20;

    timerId = startTimer(DELAY);
}

void gameMatrixGUI::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    if(appear) {
        doDrawing();
    }
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

    }
}

void gameMatrixGUI::move() {

        //cout << "X1: " << AStar.XList[counter]<< " Y1: " << AStar.YList[counter] << " X2: " << AStar.XList[counter+1] << " Y2: " << AStar.YList[counter+1] << endl;
        if(AStar.XList.size() == counter){
            x =100;
            y = (ROW * 70)-20;
            counter =1;
            arrivedX = false;
            arrivedY = false;
        }else {
            if (arrivedX == true && arrivedY == true) {
                counter++;
                arrivedX = false;
                arrivedY = false;

            } else {
                cout << "DestX: " << AStar.XList[counter] << "DestY: " << AStar.YList[counter] << endl;
                if (AStar.XList[counter] > x) {
                    x += DOT_SIZE;

                } else {
                    if (AStar.XList[counter] == x) {
                        cout << "Hola22123" << endl;
                        arrivedX = true;
                    } else {
                        x -= DOT_SIZE;
                    }
                }
                if (AStar.YList[counter] > y) {
                    y += DOT_SIZE;

                } else {
                    if (AStar.YList[counter] == y) {
                        cout << "Hola7777" << endl;
                        arrivedY = true;
                    } else {
                        y -= DOT_SIZE;
                    }
                }
            }

        }


}

void gameMatrixGUI::checkCollision() {

    if (y < 0) {
        x = 300;
        y = 600;
    }

}

int gameMatrixGUI::generateRnd(){
    int num = (rand() % 500) + 1;
    return num;
}



void gameMatrixGUI::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) {
        checkPositions();
        checkCollision();
        move();
        repaint();

    }




}
void gameMatrixGUI::goTo(int x1, int y1, int x2, int y2 ){
    int dx, dy, p, x_b, y_b;



    p=2*dy-dx;
    if(x<x2)
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
}

void gameMatrixGUI::mouseDoubleClickEvent(QMouseEvent *event) {

    x = event->x();
    y= event->y();
    cout<<"X: "<< event->x() << " Y: "<< event->y()<<endl;
};
void gameMatrixGUI::Action() {
    appear = true;
    btn_Infinity->hide();
    btn_noInfinity->hide();
    textLabel->hide();
    setStyleSheet("background-color:white;");
    // Source is the left-most bottom-most corner
    Pair src = make_pair(8,0 );
    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 9);
    AStar.aStarSearch(AStar.grid, src, dest);

    inGame = true;
    elfLabel->setAttribute(Qt::WA_TranslucentBackground);
    resize(B_WIDTH, B_HEIGHT);
    //getDimensions(B_WIDTH,B_HEIGHT);
    loadImages();
    initGame();
}