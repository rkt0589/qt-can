#include "gpio.h"

gpio::gpio(int pin):_pin(pin)
{
    export_gpio(_pin);
}

void gpio::pinMode(Direction direction)
{
    set_pin_direction(_pin, direction);
}

void gpio::digitalWrite(State state)
{
    set_pin_level(_pin, state);
}

int gpio::digitalRead()
{
    return get_pin_level(_pin);
}

void gpio::export_gpio(int pin)
{
    int fd;
    char buf[1024];

    fd = open("/sys/class/gpio/export", O_WRONLY);
    sprintf(buf, "%d", pin);
    write(fd, buf, strlen(buf));
    close(fd);
}

void gpio::set_pin_direction(int pin, int direction)
{
    int fd;
    char buf[1024];

    sprintf(buf, "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(buf, O_WRONLY);

    if(direction == 1)
        write(fd, "out", 3);
    else
        write(fd, "in", 2);

    close(fd);
}

void gpio::set_pin_level(int pin, int level)
{
    int fd;
    char buf[1024];

    sprintf(buf, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(buf, O_WRONLY);

    // Set GPIO high status
    if(level == 1)
        write(fd, "1", 1);
    // Set GPIO low status
    else
        write(fd, "0", 1);

    close(fd);
}

int gpio::get_pin_level(int pin)
{
    int fd;
    char buf[1024];
    char value;

    sprintf(buf, "/sys/class/gpio/gpio%d/value", pin);

    fd = open(buf, O_RDONLY);

    read(fd, &value, 1);

    if(value == '0')
    {
         // Current GPIO status low
        return 0;
    }
    else
    {
         // Current GPIO status high
        return 1;
    }
}
