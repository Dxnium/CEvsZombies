#include <QApplication>
#include "GUI/StartWindow.h"
#include "GA/Zombies.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    StartWindow *widget = new StartWindow();

    Zombies *zom = new Zombies();

    delete(zom);
    widget->show();


    return app.exec();
}
