/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */
#include "ssd1306_paddle.h"

Paddle init_paddle(void) {
    Paddle paddle = {
        .x = SSD1306_PADDLE_START_X,
        .y = SSD1306_PADDLE_Y
    };

    return paddle;
}
