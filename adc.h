#ifndef ADC_H
#define ADC_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QList>
#include <QTimer>
#include <QIODevice>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>
#include <QCursor>
#include <QObject>
#include <QThread>

// ADC for iMX7
#define IN_ADC0 "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define IN_ADC1 "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
#define IN_ADC2 "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"
#define IN_ADC3 "/sys/bus/iio/devices/iio:device0/in_voltage3_raw"
#define CPU_TEMP "/sys/devices/virtual/thermal/thermal_zone0/temp"
#define COM_TEMP "/sys/bus/iio/devices/iio:device0/in_temp8_input"

class adc : public QThread
{
    Q_OBJECT
public:
    enum Channel
    {
        A1=0,A2,A3,A4,TM
    };
    adc(int pin);
    uint16_t analogRead(Channel ch);
    void run();

private:
    int _interval;
    uint16_t _value[8];
    int readInternalADC();
};

#endif // ADC_H
