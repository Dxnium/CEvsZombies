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
    textLabel->setGeometry(200, 100, 150, 50);
    btn_Infinity->setStyleSheet("background-color: rgb(181,56,56);border: none; ");
    btn_Infinity->setGeometry(200, 200, 200, 20);
    connect(btn_Infinity, &QPushButton::clicked, this, &gameMatrixGUI::Action);


    btn_noInfinity->setStyleSheet("background-color: rgb(0,147,56);border: none; ");
    btn_noInfinity->setGeometry(200, 300, 200, 20);
    connect(btn_noInfinity, &QPushButton::clicked, this, &gameMatrixGUI::Action);
}

void gameMatrixGUI::loadImages() {

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


    x = 100;
    y = (ROW * 70) - 20;

    timerId = startTimer(DELAY);
}

void gameMatrixGUI::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    if (appear) {
        doDrawing();
    }
}

void gameMatrixGUI::getDimensions(int dimX, int dimY) {

    maxDivX = dimX / squareSize;
    maxDivY = dimY / squareSize;
    cout << "MAX en X:" << maxDivX << endl;
    cout << "MAX en Y:" << maxDivY << endl;

}

void gameMatrixGUI::doDrawing() {

    QPainter qp(this);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    qp.setPen(pen);
    for (int c = 0; c < COL; c++) {
        for (int f = 0; f < ROW; f++) {
            if (AStar.grid[f][c] == 1) {
                qp.drawRect((c * squareSize) + 100, (f * squareSize) + 20, squareSize, squareSize);
            } else {

                qp.fillRect((c * squareSize) + 100, (f * squareSize) + 20, squareSize, squareSize, Qt::green);
                qp.drawRect((c * squareSize) + 100, (f * squareSize) + 20, squareSize, squareSize);
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
        zombiesList[0]->moving = true;
        for (int pos = 0; pos < 10; pos++) {
            if (zombiesList[pos - 1]->y < 600) {
                zombiesList[pos]->moving = true;

            }


        }paint_buttons();

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

    qp.translate(QPoint(w / 2, h / 2));
    qp.drawText(-textWidth / 2, 0, message);
}

void gameMatrixGUI::checkPositions() {
    for (int i = 0; i < 19; i++) {
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
    if (shieldRect.intersects(gameMatrixGUIRect)) {

    }
}

void gameMatrixGUI::move() {

    for (int i = 0; i < 10; i++) {
        if (zombiesList[i]->moving) {

            if (AStar.XList.size() == zombiesList[i]->counterPos) {
                zombiesList[i]->x = 100;
                zombiesList[i]->y = (ROW * 70) - 20;
                zombiesList[i]->counterPos = 1;
                zombiesList[i]->arrivedX = false;
                zombiesList[i]->arrivedY = false;
            } else {
                if (zombiesList[i]->arrivedX == true && zombiesList[i]->arrivedY == true) {
                    zombiesList[i]->counterPos++;
                    zombiesList[i]->arrivedX = false;
                    zombiesList[i]->arrivedY = false;

                } else {
                    //cout << "DestX: " << AStar.XList[counter] << "DestY: " << AStar.YList[counter] << endl;
                    if (AStar.XList[zombiesList[i]->counterPos] > labelList[i]->x()) {
                        zombiesList[i]->x += DOT_SIZE;

                    } else {
                        if (AStar.XList[zombiesList[i]->counterPos] == labelList[i]->x()) {
                            //cout << "Hola22123" << endl;
                            zombiesList[i]->arrivedX = true;
                        } else {
                            zombiesList[i]->x -= DOT_SIZE;
                        }
                    }
                    if (AStar.YList[zombiesList[i]->counterPos] > labelList[i]->y()) {
                        zombiesList[i]->y += DOT_SIZE;

                    } else {
                        if (AStar.YList[zombiesList[i]->counterPos] == labelList[i]->y()) {
                            //cout << "Hola7777" << endl;
                            zombiesList[i]->arrivedY = true;
                        } else {
                            zombiesList[i]->y -= DOT_SIZE;
                        }
                    }
                }

            }
            labelList[i]->setGeometry(zombiesList[i]->x, zombiesList[i]->y, 100, 100);
            labelList[i]->show();
        }

    }


}


void gameMatrixGUI::checkCollision() {

    if (y < 0) {
        x = 300;
        y = 600;
    }

}

int gameMatrixGUI::generateRnd() {
    int num = (rand() % 500) + 1;
    return num;
}


void gameMatrixGUI::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) {
        checkPositions();
        checkCollision();
        if(startGame) {
            move();
        }
        repaint();

    }


}

void gameMatrixGUI::goTo(int x1, int y1, int x2, int y2) {
    int dx, dy, p, x_b, y_b;


    p = 2 * dy - dx;
    if (x < x2) {

        if (p >= 0) {
            //std::cout<<"("<<x<<","<<y<<")"<<std::endl;
            y = y + DOT_SIZE;
            p = p + 2 * dy - 2 * dx;
        } else {
            //std::cout<<"("<<x<<","<<y<<")"<<std::endl;
            p = p + 2 * dy;
        }
        x = x + DOT_SIZE;
    }
}

void gameMatrixGUI::mouseDoubleClickEvent(QMouseEvent *event) {

//    x = event->x();
//    y= event->y();
    cout << "X: " << event->x() << " Y: " << event->y() << endl;
};

void gameMatrixGUI::Action() {
    appear = true;
    btn_Infinity->hide();
    btn_noInfinity->hide();
    textLabel->hide();
    setStyleSheet("background-color:white;");


    inGame = true;

    resize(B_WIDTH, B_HEIGHT);
    //getDimensions(B_WIDTH,B_HEIGHT);
    fillArray();
    loadImages();
    create_Buttons();
    initGame();
}

void gameMatrixGUI::fillArray() {
    QMovie *elfMovie = new QMovie(
            "/home/smz/TEC/Algoritmos y Estructuras de Datos II/Proyectos Datos II/CEvsZombies/Images/elf.gif");
    QMovie *purpleElf = new QMovie(
            "/home/smz/TEC/Algoritmos y Estructuras de Datos II/Proyectos Datos II/CEvsZombies/Images/purpleElf.gif");
    for (int i = 0; i < 10; i++) {
        zombiesList[i] = new Zombies();
        if (i % 2 == 0) {
            labelList[i] = new QLabel(this);
            labelList[i]->setAttribute(Qt::WA_TranslucentBackground);
            labelList[i]->setMovie(elfMovie);
            elfMovie->start();
        } else {
            labelList[i] = new QLabel(this);
            labelList[i]->setAttribute(Qt::WA_TranslucentBackground);
            labelList[i]->setMovie(purpleElf);
            purpleElf->start();

        }
    }


}

void gameMatrixGUI::create_Buttons() {
    QPixmap pixmap("/home/danium/Documents/TEC/Datos II/Proyecto II/CEvsZombies/Images/Hull_01.png");
    button->setPixmap(pixmap);

    btn->setStyleSheet("background-color: rgb(181,56,56);border: none; ");
    connect(btn, &QPushButton::clicked, this, &gameMatrixGUI::Start);
    button1->setPixmap(pixmap);
    button2->setPixmap(pixmap);
}

void gameMatrixGUI::paint_buttons() {
    button->setGeometry(900, 50, squareSize, squareSize);
    button1->setGeometry(900, 175, squareSize, squareSize);
    button2->setGeometry(900, 300, squareSize, squareSize);
    puntos->setGeometry(900, 400, squareSize, squareSize);
    btn->setGeometry(900, 500, 100, 20);

}


void gameMatrixGUI::mousePressEvent(QMouseEvent *event) {
    int x = event->x();
    int y = event->y();
    //buttons
    if (x > 900 and x < 975) {
        if (y > 50 and y < 125) {
            cout << "button\n";
        }
        if (y > 175 and y < 250) {
            cout << "button1\n";
        }
        if (y > 300 and y < 375) {
            cout << "button2\n";
        }
    } else if (x > 100 and x < 750) {
        int posX = (x - 100) / 75;
        int posY = (y - 20) / 75;
        cout << "x:" << posX << " y:" << posY << endl;
        refresh_matriz(posX, posY);
    }
}

void gameMatrixGUI::refresh_matriz(int x, int y) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 10; col++) {
            if (x == row and y == col and pts != 0) {
                AStar.grid[col][row] = 0;
                pts -= 20;
                std::string s = to_string(pts);
                QString str = QString::fromUtf8(s.c_str());
                puntos->setText(str);
            }
        }
    }
}

void gameMatrixGUI::Start() {
    startGame = true;
    // Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);

    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 9);

    AStar.aStarSearch(AStar.grid, src, dest);
}
