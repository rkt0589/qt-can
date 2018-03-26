#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>                  // standard I/O header file
#include <fcntl.h>                   // for open(), close(), lseek()
#include <sys/stat.h>                // for open()
#include <stdio.h>                   // standard I/O header file
#include <sys/types.h>               // for open()
#include <unistd.h>                  // for write(), open(), read(), usleep()
#include <string.h>

class gpio
{

private:
    int _pin;
    void export_gpio(int pin);
    void set_pin_direction(int pin, int direction);
    void set_pin_level(int pin, int level);
    int get_pin_level(int pin);

public:
    enum Direction
    {
        INPUT=0,
        OUTPUT
    };
    enum State
    {
        LOW=0,
        HIGH
    };
    gpio(int pin);
    void pinMode(Direction direction);
    void digitalWrite(State state);
    int digitalRead();
};

#endif // GPIO_H
