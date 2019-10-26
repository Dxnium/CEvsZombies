#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "GUI/gameMatrixGUI.h"

int main(int argc, char *argv[]) {
//Qt test
    QApplication app(argc, argv);




    // Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);

    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);



    gameMatrixGUI game;
    game.AStar.aStarSearch(game.AStar.grid, src, dest);
    game.setWindowTitle("CEvsZombies");

    game.show();

    return app.exec();




}