#include "calendarwindow.h"
#include "ui_calendarwindow.h"
#include "mainwindow.h"
#include <QTextCharFormat>

QString dates;

CalendarWindow::CalendarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarWindow)
{

    ui->setupUi(this);
    QDate cd = QDate::currentDate();
    ui->calendarWidget->setSelectedDate(cd);

    ui->dt_now->setDisplayFormat("dd.MM.yyyy");
    ui->dt_end->setDisplayFormat("dd.MM.yyyy");
    ui->dt_start->setDisplayFormat("dd.MM.yyyy");
    ui->dt_now->setDate(cd);
    ui->dt_start->setDate(cd.addMonths(-1));
    ui->dt_end->setDate(cd);
    connect(ui->btn_findSlots,&QPushButton::clicked,
                this,[=]()
        {

            emit this->isChangeValue(dates);
            // Дальнейший код

        });
    connect(ui->btn_searchRange,&QPushButton::clicked,
                this,[=]()
        {

            emit this->isChangeValue(dates);
            // Дальнейший код

        });







}


/*void CalendarWindow::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    // change color for dates before current date
    if (date < QDate::currentDate())
    {
        painter->save();
        // set color for the text
        painter->setPen(QColor(64, 64, 64));
        // draw text with new color
        painter->drawText(rect, Qt::TextSingleLine | Qt::AlignCenter, QString::number(date.day()));

        // here you can draw anything you want

        painter->restore();
    } else {
        // draw cell in standard way
        QCalendarWidget::paintCell(painter, rect, date);
    }
}*/

CalendarWindow::~CalendarWindow()
{

    delete ui;
}



void CalendarWindow::on_btn_searchRange_clicked()
{
    QDate startDate = ui->dt_start->date();
    QDate endDate = ui->dt_end->date();
    dates = startDate.toString() + "|" + endDate.toString();

}
QString m_value = "";



void CalendarWindow::on_onButtonSend_clicked()
{


    connect(this, &CalendarWindow::isChangeValue,
               this,[=](QString isChange)
       {


           // Значение изменено
           m_value = isChange;

qDebug("1");

       });

    QTextCharFormat highlight;
    highlight.setBackground(Qt::cyan);
     ui->calendarWidget->setDateTextFormat(QDate::fromString(m_value, "ddd MMM d yyyy"), highlight);
}


void CalendarWindow::on_btn_findSlots_clicked()
{
dates = ui->calendarWidget->selectedDate().toString();

}

