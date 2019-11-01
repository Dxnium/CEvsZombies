//
// Created by danium on 11/10/19.
//

#include <iostream>
#include <QtWidgets/QPushButton>
#include <QRadioButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include "StartWindow.h"
#include "gameMatrixGUI.h"

using namespace std;

StartWindow::StartWindow(QWidget *parent): QWidget(parent){
    resize(700,1020);
    setWindowTitle("CEvsZombies");



    QPushButton *btn_Infinity = new QPushButton("Modo 1",this);
    connect(btn_Infinity, &QPushButton::clicked, this, &StartWindow::Action);
    btn_Infinity->setStyleSheet("background-color: rgb(181,56,56);border: none; ");
    btn_Infinity->setGeometry(200,200,200,20);

    QPushButton *btn_noInfinity = new QPushButton("Modo2",this);
    connect(btn_noInfinity, &QPushButton::clicked, this, &StartWindow::Action);
    btn_noInfinity->setStyleSheet("background-color: rgb(0,147,56);border: none; ");
    btn_noInfinity->setGeometry(200,300,200,20);

}
void StartWindow::Action()
{

    gameMatrixGUI game;
    game.setWindowTitle("CEvsZombies");
    game.show();



}
