#ifndef CHARTFORM_H
#define CHARTFORM_H

#include <QWidget>
#include <QtCharts/QChartGlobal>
#include "chart.h"
#include "chartview.h"
#include <QListWidgetItem>
#include <QMenu>
#include <QAction>
#include "callout.h"
#include <QButtonGroup>

namespace Ui {
class ChartForm;
}

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
class QXYSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class ChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChartForm(QWidget *parent = 0);
    ~ChartForm();

    /**
     * @brief 允许用户对图表的数据进行编辑
     */
    void allowUserEdit();

    /**
     * @brief 向图表中添加一组数据
     * @param series 数据
     * @param title 名称
     */
    void addSeries(QXYSeries *series, QString &title);

    /**
     * @brief 更新同名的数据
     * @param series
     * @param title
     */
    void updateSeries(QXYSeries *series, QString &title);

    /**
     * @brief 移除名称为title的一组数据
     * @param title
     */
    void removeSeries(QString &title);

    /**
     * @brief 清除所有数据
     */
    void removeAllSeries();

protected:

    void mouseReleaseEvent(QMouseEvent *event);

private:
    /**
     * @brief 绘制图表
     * @return
     */
    QChart *createChart();

    /**
     * @brief 主题
     */
    void populateThemeBox();

    /**
     * @brief 动画
     */
    void populateAnimationBox();

    /**
     * @brief 标签
     */
    void populateLegendBox();

    /**
     * @brief 通过点击标签显示或隐藏对应的数据
     */
    void connectMarkers();

    /**
     * @brief 取消标签点击功能
     */
    void disconnectMarkers();
private slots:
    void updateUI();

    void editChart();

    void clearChart();

    void on_led_title_returnPressed();

    void on_btn_titleFont_clicked();

    void on_btn_titleColor_clicked();

    void on_led_xAxisTitle_returnPressed();

    void on_dsb_xMinValue_valueChanged(double arg1);

    void on_dsb_xMaxValue_valueChanged(double arg1);

    void on_led_yAxisTitle_returnPressed();

    void on_dsb_yMinValue_valueChanged(double arg1);

    void on_dsb_yMaxValue_valueChanged(double arg1);

    void on_btn_dataColor_clicked();

    void on_update_dataStyle(int id);

    void changeSeriesVisiable(int check);

    void handleMarkerClicked();

    void keepCallout();

    void tooltip(QPointF point, bool state);

    void on_sbx_lineWidth_valueChanged(int arg1);

    void on_groupBox_5_toggled(bool arg1);

private:
    Ui::ChartForm *ui;

    bool mEditEnable = false;

    // 一个图表
    QChartView *mChartView = NULL;
    Chart *mChart = NULL;
    // 多个数据(一张图中可以显示多组数据)
    QList<QXYSeries*> mSeries;
    // 右击弹出菜单
    QMenu *mRightClickMenu;
    QAction *mEditAction;
    QAction *mClearAction;
    QButtonGroup buttonGroup;
    // tip
    Callout *mTooltip = NULL;
    QList<Callout *> mCallouts;
};

#endif // CHARTFORM_H
