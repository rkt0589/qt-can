#include "adc.h"

adc::adc(int interval):_interval(interval)
{
    start(QThread::NormalPriority);
}

void adc::run()
{
    while(true)
    {
        readInternalADC();
        msleep(_interval);
    }
}

uint16_t adc::analogRead(Channel ch)
{
    return _value[ch];
}

int adc::readInternalADC()
{
    char *rawAdc[]={IN_ADC0,
                    IN_ADC1,
                    IN_ADC2,
                    IN_ADC3,
                   CPU_TEMP};

    for(int adc=0; adc<5;adc++)
    {
        QFile file(rawAdc[adc]);
        QString string;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            string = in.readLine();
            _value[adc]=string.toInt();
            qDebug()<<QString(string);
        }
        file.close();
    }
    return 0;
}
