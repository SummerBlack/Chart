# Chart
Qt 平台图表的封装，便于简单地向图表中添加曲线和对图表进行编辑。<br>
核心类ChartForm的用法很简单，对外提供的接口主要用于添加、更新、删除曲线：<br>
```cpp

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
```

用于向表格中添加、更新、删除数据。<br>
## 简单应用
```cpp
    QLineSeries *sSeries = new QLineSeries();
    QLineSeries *tSeries = new QLineSeries();
    // 数据
    for (int i = 0; i < 360; ++i) {
        sSeries->append(i, sin(M_PI * i / 180));
        tSeries->append(i, cos(M_PI * i / 180));
    }

    ChartForm w;
    w.allowUserEdit();
    w.addSeries(sSeries, QString("Sin"));
    w.addSeries(tSeries, QString("Cos"));

    w.show();
```
## 图表编辑
主要是对图表的标题、坐标轴、曲线的外观、主题进行编辑。<br>
### 标题
主要对标题、标题字体、标题颜色的编辑。<br>
 ![](https://github.com/SummerBlack/Chart/blob/master/title.PNG) <br>
### 坐标轴
对坐标轴名称、范围进行设置。<br>
![](https://github.com/SummerBlack/Chart/blob/master/axis.png) <br>
### 外观
在数据列表中显示所有加入的曲线title，通过勾选与否可以选择是否显示对应的曲线。外观栏主要是对左侧选中的数据列对应的曲线进行编辑，可以选择曲线的颜色、线宽、线形。
![](https://github.com/SummerBlack/Chart/blob/master/data.png) <br>
### 主题
可以对图表的主题、动画以及Legend进行设置，当设置显示Legend还可以通过点击对应的legend显示或隐藏对应的曲线。<br>
![](https://github.com/SummerBlack/Chart/blob/master/theme.png) <br>

### 其他
通过鼠标悬停，可以显示标签。<br>
![](https://github.com/SummerBlack/Chart/blob/master/callout.png) <br>

