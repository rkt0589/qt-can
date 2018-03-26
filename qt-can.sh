#!/bin/bash
ts_calibrate
while : ; do
export QT_QPA_EGLFS_HIDECURSOR=1
export QT_QPA_EGLFS_FB=/dev/fb0
#screen1 -platform eglfs
demo_can_adc_gpio_qt
done
