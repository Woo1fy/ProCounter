#include "calendarwindow.h"
#include "ui_calendarwindow.h"

CalendarWindow::CalendarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarWindow)
{
    ui->setupUi(this);
    QDate cd = QDate::currentDate();
    ui->calendarWidget->setSelectedDate(cd);
    ui->dt_now->setDisplayFormat("dd.mm.yyyy");
    ui->dt_end->setDisplayFormat("dd.mm.yyyy");
    ui->dt_start->setDisplayFormat("dd.mm.yyyy");
    ui->dt_now->setDate(cd);
    ui->dt_end->setDate(cd);
}



CalendarWindow::~CalendarWindow()
{

    delete ui;
}

QVector<QDate> dates;

void CalendarWindow::on_btn_searchRange_clicked()
{
    QDate startDate = ui->dt_start->date();
    QDate endDate = ui->dt_end->date();
    dates.append(startDate);
    dates.append(endDate);

}

