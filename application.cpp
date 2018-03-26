#include "application.h"
#include "ui_application.h"
#include "gpio.h"
#include "adc.h"

bool ledChecked = true;
bool adcRunning = true;
gpio led(58);
gpio sw(54);
adc imx7Adc(100);

application::application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::application)
{
    ui->setupUi(this);

    adcScan = new QTimer(this);
    connect(adcScan, SIGNAL(timeout()), this, SLOT(updateGUI()));
    // user init
    led.pinMode(gpio::Direction::OUTPUT);
    sw.pinMode(gpio::Direction::INPUT);
}

application::~application()
{
    delete ui;
}

void application::on_Led_toggled(bool checked)
{

}

void application::on_Led_clicked()
{
    if(ledChecked){
        led.digitalWrite(gpio::State::HIGH);
        ui->Led->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
    else{
        led.digitalWrite(gpio::State::LOW);
        ui->Led->setStyleSheet("background-color: rgb(46, 52, 54);");
    }
    ledChecked = !ledChecked;
    fprintf(stderr, "LED event\n");
}

void application::on_startADC_clicked()
{
    if(adcRunning){
        adcScan->start(500);
        ui->startADC->setStyleSheet("background-color: rgb(0, 100, 0);");
    }
    else{
        adcScan->stop();
        ui->startADC->setStyleSheet("background-color: rgb(46, 52, 54);");
    }
    adcRunning=!adcRunning;
    fprintf(stderr, "ADC event\n");
}
void application::updateGUI()
{
    ui->AI1->display(imx7Adc.analogRead(adc::Channel::A1));
    ui->AI2->display(imx7Adc.analogRead(adc::Channel::A2));
    ui->AI3->display(imx7Adc.analogRead(adc::Channel::A3));
    ui->AI4->display(imx7Adc.analogRead(adc::Channel::A4));
    ui->pinState->setText(sw.digitalRead() ? "High" : "Low");
}
