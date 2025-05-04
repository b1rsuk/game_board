/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_SSD1306_PONG_H_
#define INC_SSD1306_PONG_H_
#include "ssd1306_circle.h"
#include "ssd1306_paddle.h"

#include "pong_game.h"

typedef struct {
	Circle circle;
	Paddle paddle;
	bool is_game_over;
} PongGameState;

void pong_game(void);

#endif /* INC_SSD1306_CIRCLE_H_ */
