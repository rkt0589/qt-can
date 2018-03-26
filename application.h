#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class application;
}

class application : public QMainWindow
{
    Q_OBJECT

public:
    QTimer *adcScan;
public:
    explicit application(QWidget *parent = 0);
    ~application();

private slots:
    void on_Led_toggled(bool checked);
    void on_Led_clicked();
    void on_startADC_clicked();
    void updateGUI();

private:
    Ui::application *ui;
};

#endif // APPLICATION_H
