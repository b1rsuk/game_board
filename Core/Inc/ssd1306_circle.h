/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_SSD1306_CIRCLE_H_
#define INC_SSD1306_CIRCLE_H_

#define SSD1306_BALL_RADIUS 10
#define SSD1306_BALL_START_Y 30

#include <inttypes.h>
#include <stdbool.h>
#include "ssd1306.h"

typedef enum {
    RIGHT,
    LEFT,
    STRAIGHT,
	HORIZONTAL_DIRECTION_COUNT
} HorizontalDirection;

typedef enum {
    UP,
    DOWN
} VerticalDirection;

typedef struct {
	 VerticalDirection vertical_direction;
	 HorizontalDirection horizontal_direction;
} MovementDirection;

typedef struct {
    int16_t x;
    int16_t y;
    MovementDirection movement_direction;
} Circle;
Circle init_circle(void);

void update_vertical_movement(Circle *const p_circle);
void update_horizontal_movement(Circle *const p_circle);
void update_circle_position(Circle *const circle);

#endif /* INC_SSD1306_CIRCLE_H_ */
