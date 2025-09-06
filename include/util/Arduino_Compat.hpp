#pragma once

#include "pico/stdlib.h"
#include <pico/time.h>

namespace Util {

// Mimic Arduino constants
static constexpr auto OUTPUT = 1;
static constexpr auto INPUT = 0;
static constexpr auto HIGH = 1;
static constexpr auto LOW = 0;

inline void pinMode(uint pin, int mode) {
    gpio_init(pin);
    gpio_set_dir(pin, (mode == OUTPUT));
}

inline void digitalWrite(uint pin, int value) {
    gpio_put(pin, value);
}

inline unsigned long micros() {
    return to_ms_since_boot(get_absolute_time());
}

inline void delay(unsigned long ms) {
    sleep_ms(ms);
}

inline void delayMicroseconds(unsigned int us) {
    sleep_us(us);
}

inline int constrain(int value, int min, int max) {
    if(value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

} // namespace Util
