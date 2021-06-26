#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>

namespace Ui {
class CalendarWindow;
}

class CalendarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarWindow(QWidget *parent = nullptr);
    ~CalendarWindow();

signals:
    void sendData(QVector<QDate>);

private slots:
    void on_btn_searchRange_clicked();

    void on_pushButton_2_clicked();



    void on_onButtonSend_clicked();

private:
    Ui::CalendarWindow *ui;
};

#endif // CALENDARWINDOW_H
