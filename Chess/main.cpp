#include "chess.h"
#include <QApplication>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess w;
    w.show();
    return a.exec();
}
