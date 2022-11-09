#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "matmathlib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Memento_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }


    std::vector<std::vector<int>> lhs{
        {2, 5},
        {3, 6},
        {4, 7}
    };
    std::vector<std::vector<int>> rhs{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    MatMathLib::multiply(lhs[0].size(), rhs[0].size(), lhs.size(), lhs, rhs);
    MainWindow w;
    w.show();
    return a.exec();
}
