#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

typedef enum {
 BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

typedef unsigned short uint16_t;

uint16_t color_code(resistor_band_t* resistor_color);
#endif
