#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>
#include <QPainter>

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
    void isChangeValue(QString);

private slots:
    void on_btn_searchRange_clicked();

    void on_onButtonSend_clicked();

    void on_btn_findSlots_clicked();




private:
    Ui::CalendarWindow *ui;

};

#endif // CALENDARWINDOW_H
