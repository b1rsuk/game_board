/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */
#include "ssd1306_circle.h"


void update_circle_x(Circle* circle, HorizontalDirection direction) {
    switch(direction) {
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

void update_circle_y(Circle* circle, VerticalDirection direction) {
    switch(direction) {
        case DOWN:
            ++circle->y;
            break;
        case UP:
            --circle->y;
            break;
    }
}

