// main.cpp
#include <QApplication>
#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SortDialog dialog;
    dialog.setColumnRange('A', 'Z');
    dialog.show();

    return a.exec();
}
