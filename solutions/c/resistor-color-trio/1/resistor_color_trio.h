#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

typedef enum {
 OHMS, KILOOHMS
} resistor_unit_t;

typedef enum {
 BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

typedef struct {
    resistor_unit_t unit;
    uint32_t value;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t* resistor_color);

#endif
