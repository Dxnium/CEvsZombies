#include <QApplication>
#include "GUI/StartWindow.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    StartWindow *widget =  new StartWindow();
    widget->show();


    return app.exec();
