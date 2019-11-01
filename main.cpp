#include <QApplication>
#include "GUI/StartWindow.h"
#include "GUI/gameMatrixGUI.h"

int main(int argc, char *argv[]) {
//Qt test
    QApplication app(argc, argv);

    gameMatrixGUI game;

    game.setWindowTitle("CEvsZombies");

    game.show();

    return app.exec();




}