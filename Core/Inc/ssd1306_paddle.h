/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_SSD1306_PADDLE_H_
#define INC_SSD1306_PADDLE_H_

#include <inttypes.h>
#include "ssd1306.h"

#define SSD1306_PADDLE_START_X   (SSD1306_CENTER_X - 10)
#define SSD1306_PADDLE_Y   60
#define SSD1306_PADDLE_LENGTH   20

typedef struct {
    int16_t x;
    int16_t y;
} Paddle;
Paddle init_paddle(void);

#endif /* INC_SSD1306_CIRCLE_H_ */
