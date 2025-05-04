/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_SSD1306_CIRCLE_H_
#define INC_SSD1306_CIRCLE_H_

#define SSD1306_BALL_RADIUS 10
#define SSD1306_CENTER_X (SSD1306_WIDTH / 2)
#define SSD1306_BALL_START_Y 30

#include <inttypes.h>
#include <stdbool.h>
#include "ssd1306.h"

typedef enum {
    RIGHT,
    LEFT,
    STRAIGHT
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


static inline bool is_at_bottom_boundary(const Circle *const circle) {
    return circle->y + SSD1306_BALL_RADIUS >= SSD1306_HEIGHT;
}

static inline bool is_at_top_boundary(const Circle *const circle) {
    return circle->y - SSD1306_BALL_RADIUS <= 0;
}

static inline bool is_at_vertical_boundary(const Circle *const circle) {
    return is_at_bottom_boundary(circle) || is_at_top_boundary(circle);
}

static inline bool is_at_left_boundary(const Circle *const circle) {
    return circle->x <= SSD1306_BALL_RADIUS;
}

static inline bool is_at_right_boundary(const Circle *const circle) {
    return circle->x >= SSD1306_WIDTH - SSD1306_BALL_RADIUS;
}

static inline bool is_at_horizontal_boundary(const Circle *const circle) {
    return is_at_left_boundary(circle) || is_at_right_boundary(circle);
}


void update_circle_position(Circle *const circle);
void update_circle_on_wall_hit(Circle *const circle);
void update_circle_on_line_hit(Circle *const circle);

#endif /* INC_SSD1306_CIRCLE_H_ */
