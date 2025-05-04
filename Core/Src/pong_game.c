/*
 * ssd1306_circle.h
 *
 *  Created on: 3 мая 2025 г.
 *      Author: borsuk
 */

#include <stdbool.h>
#include "pong_game.h"
#include "pong_game_checks.h"

static inline void update_vertical_movement_on_wall_hit(Circle *const p_circle) {
    if (is_circle_at_vertical_boundary(p_circle)) {
        update_vertical_movement(p_circle);
    }
}

static inline void update_horizontal_movement_on_wall_hit(Circle *const p_circle) {
    if (is_circle_at_horizontal_boundary(p_circle)) {
        update_horizontal_movement(p_circle);
    }
}

static inline void update_circle_movement_on_wall_hit(Circle *const p_circle) {
    update_vertical_movement_on_wall_hit(p_circle);
    update_horizontal_movement_on_wall_hit(p_circle);
}

static inline void update_circle_movement_on_paddle_hit(Circle *const p_circle) {
    update_vertical_movement(p_circle);
    update_horizontal_movement(p_circle);
}

static inline void update_paddle_right(Paddle *const p_paddle) {
    if (is_move_right_pressed()) {
        ++p_paddle->x;
    }
}

static inline void update_paddle_left(Paddle *const p_paddle) {
    if (is_move_left_pressed()) {
        --p_paddle->x;
    }
}

static inline void move_paddle_by_input(Paddle *const p_paddle) {
    update_paddle_right(p_paddle);
    update_paddle_left(p_paddle);
}

static inline void show_game_over_screen(void) {
    ssd1306_Clear();
    ssd1306_SetCursor(0, 0);
    FontDef font = Font_7x10;
    ssd1306_WriteString("THE GAME IS OVER!", font);
    ssd1306_UpdateScreen();
}

static inline void pong_game_init(PongGameState *const pong_game_state) {
    pong_game_state->circle = init_circle();
    pong_game_state->paddle = init_paddle();
    pong_game_state->is_game_over = false;
}

static inline void pong_game_update(PongGameState *const pong_game_state) {
    if (is_circle_at_bottom_boundary(&pong_game_state->circle)) {
        pong_game_state->is_game_over = true;
        return;
    }

    move_paddle_by_input(&pong_game_state->paddle);
    update_circle_movement_on_wall_hit(&pong_game_state->circle);
    update_circle_position(&pong_game_state->circle);

    if (is_paddle_hit(&pong_game_state->circle, &pong_game_state->paddle)) {
        update_circle_movement_on_paddle_hit(&pong_game_state->circle);
    }
}

static inline void pong_game_render(const PongGameState *const pong_game_state) {
    ssd1306_Clear();
    ssd1306_FillCircle(pong_game_state->circle.x, pong_game_state->circle.y, SSD1306_BALL_RADIUS);
    ssd1306_DrawHorizontalLine(pong_game_state->paddle.x, pong_game_state->paddle.y, SSD1306_PADDLE_LENGTH);
    ssd1306_UpdateScreen();
}

static inline void pong_game_handle_game_over(void) {
    show_game_over_screen();
    HAL_Delay(5000);
}

inline void pong_game(void) {
    PongGameState pong_game_state;
    PongGameState *const p_pong_game_state = &pong_game_state;

    pong_game_init(p_pong_game_state);

    while(true) {
        pong_game_update(p_pong_game_state);

        if (pong_game_state.is_game_over) {
            pong_game_handle_game_over();
            return;
        }

        pong_game_render(p_pong_game_state);
    }
}
