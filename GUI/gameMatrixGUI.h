//
// Created by smz on 25/10/19.
//

#ifndef CEVSZOMBIES_GAMEMATRIXGUI_H
#define CEVSZOMBIES_GAMEMATRIXGUI_H


#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QtWidgets/QLabel>
//#include "crusader.h"
#include <QMovie>
#include <QtWidgets/QPushButton>
#include "AStarAlgthm.h"
#include "StartWindow.h"

class gameMatrixGUI : public QWidget {

    public:
        gameMatrixGUI(QWidget *parent = 0);
        AStarAlgthm AStar;
        QPushButton *btn_Infinity = new QPushButton("Modo 1",this);
        QPushButton *btn_noInfinity = new QPushButton("Modo2",this);

    protected:
        void paintEvent(QPaintEvent *);
        void timerEvent(QTimerEvent *);
        void drawLines(QPainter *qp);



    private:
        QRect crusaderRect;
        QImage gameMatrixGUIImg;

        QImage shieldImg;

        QMovie *elfMovie = new QMovie("/home/smz/TEC/Algoritmos y Estructuras de Datos II/Proyectos Datos II/CEvsZombies/Images/elf.gif");
        QLabel *elfLabel = new QLabel(this);

        QLabel *textLabel;

        //crusader crusaderList[19];
        static const int filas = 15;
        static const int columnas = 15;
        int mapMatrix[columnas][filas];
        bool appear = false;
        static const int B_WIDTH = 1000;
        static const int B_HEIGHT = 800;
        static const int DOT_SIZE = 5;
        static const int ALL_DOTS = 900;
        static const int RAND_POS = 50;
        static const int DELAY = 140;

        int timerId;
        int dots;
        int crusaderImg_x;
        int crusaderImg_y;
        int shieldImg_x;
        int shieldImg_y;
        int x;
        int y;

        bool leftDirection;
        bool rightDirection;
        bool upDirection;
        bool downDirection;
        bool inGame;
        int counter = 1;
        bool arrivedX= false;
        bool arrivedY= false;
        int dimX =0;
        int dimY=0;
        int maxDivX  = 0;
        int maxDivY  = 0;
        int squareSize = 75;
        QRect  gameMatrixGUIRect;
        QRect shieldRect;
        void loadImages();
        void initGame();
        void checkPositions();
        void checkCollision();
        void move();
        void doDrawing();
        void gameOver(QPainter &);
        void getDimensions(int , int);
        int generateRnd();
        void goTo(int, int, int, int);
        void mouseDoubleClickEvent(QMouseEvent *event);

    private slots:
        void Action();
};


#endif //CEVSZOMBIES_GAMEMATRIXGUI_H
