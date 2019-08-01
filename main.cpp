#include <QApplication>
#include <QLineSeries>
#include <QtMath>
#include "chart/chartform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineSeries *sSeries = new QLineSeries();
    QLineSeries *tSeries = new QLineSeries();

    for (int i = 0; i < 360; ++i) {
        sSeries->append(i, sin(M_PI * i / 180));
        tSeries->append(i, cos(M_PI * i / 180));
    }

    ChartForm w;
    w.allowUserEdit();
    w.addSeries(sSeries, QString("Sin"));
    w.addSeries(tSeries, QString("Cos"));

    w.show();

    return a.exec();
}
