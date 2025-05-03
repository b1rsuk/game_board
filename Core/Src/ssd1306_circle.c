/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */
#include "ssd1306_circle.h"


static inline void update_circle_x(Circle *const circle) {
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
    }
}

static inline void update_circle_y(Circle *const circle) {
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

void inline update_circle_position(Circle *const circle) {
	update_circle_x(circle);
	update_circle_y(circle);
}

static inline void toggle_circle_y_mode(VerticalDirection *const vertical_direction) {
	*vertical_direction = !(*vertical_direction);
}

static inline void toggle_circle_x_mode(HorizontalDirection *const horizontal_direction) {
	*horizontal_direction = !(*horizontal_direction);
}

void assign_random_horizontal_direction(HorizontalDirection *const horizontal_direction) {
	 srand(HAL_GetTick());
    *horizontal_direction = (HorizontalDirection)(rand() % 3);
}

static inline void update_vertical_movement_on_hit(Circle *const circle) {
    if (is_at_vertical_boundary(circle)) {
        toggle_circle_y_mode(&circle->movement_direction.vertical_direction);
        assign_random_horizontal_direction(&circle->movement_direction.horizontal_direction);
    }
}

static inline void update_horizontal_movement_on_hit(Circle *const circle) {
    if (is_at_horizontal_boundary(circle)) {
        toggle_circle_x_mode(&circle->movement_direction.horizontal_direction);
    }
}

inline void update_circle_on_wall_hit(Circle *const circle) {
    update_vertical_movement_on_hit(circle);
    update_horizontal_movement_on_hit(circle);
}
