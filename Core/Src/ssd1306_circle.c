/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */
#include "ssd1306_circle.h"

static inline void toggle_circle_vertical_direction_mode(VerticalDirection *const vertical_direction) {
    *vertical_direction = !(*vertical_direction);
}

static inline void toggle_circle_horizontal_direction_mode(HorizontalDirection *const horizontal_direction) {
    *horizontal_direction = !(*horizontal_direction);
}

static inline void assign_circle_random_horizontal_direction(HorizontalDirection *const horizontal_direction) {
    srand(HAL_GetTick());
    *horizontal_direction = (HorizontalDirection)(rand() % HORIZONTAL_DIRECTION_COUNT);
}

static inline void update_circle_horizontal(Circle *const circle) {
    HorizontalDirection horizontal_direction = circle->movement_direction.horizontal_direction;
    switch(horizontal_direction) {
        case RIGHT:
            ++circle->x;
            break;
        case LEFT:
            --circle->x;
            break;
        case STRAIGHT:
            break;
        case HORIZONTAL_DIRECTION_COUNT:
        	break;
    }
}

static inline void update_circle_vertical(Circle *const circle) {
    VerticalDirection vertical_direction = circle->movement_direction.vertical_direction;
    switch(vertical_direction) {
        case DOWN:
            ++circle->y;
            break;
        case UP:
            --circle->y;
            break;
    }
}

inline void update_circle_position(Circle *const circle) {
    update_circle_horizontal(circle);
    update_circle_vertical(circle);
}

inline void update_vertical_movement(Circle *const circle) {
	toggle_circle_vertical_direction_mode(&circle->movement_direction.vertical_direction);
    assign_circle_random_horizontal_direction(&circle->movement_direction.horizontal_direction);
}

inline void update_horizontal_movement(Circle *const circle) {
	toggle_circle_horizontal_direction_mode(&circle->movement_direction.horizontal_direction);
}

Circle init_circle(void) {
    Circle circle = {
        .x = SSD1306_CENTER_X,
        .y = SSD1306_BALL_START_Y,
        .movement_direction = {
            .vertical_direction = DOWN,
            .horizontal_direction = STRAIGHT
        }
    };
    return circle;
}
