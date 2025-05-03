/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_SSD1306_CIRCLE_H_
#define INC_SSD1306_CIRCLE_H_
#include <inttypes.h>

typedef struct {
    int16_t x;
    int16_t y;
    int16_t radius;
} Circle;

typedef enum {
    RIGHT,
    LEFT,
    STRAIGHT,
	NO_CHANGE
} HorizontalDirection;

typedef enum {
    UP,
    DOWN
} VerticalDirection;

void update_circle_x(Circle* circle, HorizontalDirection direction);
void update_circle_y(Circle* circle, VerticalDirection direction);

#endif /* INC_SSD1306_CIRCLE_H_ */
