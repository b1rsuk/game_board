/*
 * game_checks.h
 *
 *  Created on: May 4, 2025
 *      Author: borsuk
 */

#ifndef INC_PONG_GAME_CHECKS_H_
#define INC_PONG_GAME_CHECKS_H_

static inline bool is_circle_at_bottom_boundary(const Circle *const p_circle) {
    return p_circle->y + SSD1306_BALL_RADIUS >= SSD1306_HEIGHT;
}

static inline bool is_circle_at_top_boundary(const Circle *const p_circle) {
    return p_circle->y - SSD1306_BALL_RADIUS <= 0;
}

static inline bool is_circle_at_vertical_boundary(const Circle *const p_circle) {
    return is_circle_at_bottom_boundary(p_circle) || is_circle_at_top_boundary(p_circle);
}

static inline bool is_circle_at_left_boundary(const Circle *const p_circle) {
    return p_circle->x <= SSD1306_BALL_RADIUS;
}

static inline bool is_circle_at_right_boundary(const Circle *const p_circle) {
    return p_circle->x >= SSD1306_WIDTH - SSD1306_BALL_RADIUS;
}

static inline bool is_circle_at_horizontal_boundary(const Circle *const p_circle) {
    return is_circle_at_left_boundary(p_circle) || is_circle_at_right_boundary(p_circle);
}

static inline bool is_move_right_pressed(void) {
    return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == GPIO_PIN_SET;
}

static inline bool is_move_left_pressed(void) {
    return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_SET;
}

static inline bool is_ball_right_of_paddle_left(const Circle *const p_circle, const Paddle *const p_paddle) {
    return p_circle->x + SSD1306_BALL_RADIUS >= p_paddle->x;
}

static inline bool is_ball_left_of_paddle_right(const Circle *const p_circle, const Paddle *const p_paddle) {
    return p_circle->x - SSD1306_BALL_RADIUS <= p_paddle->x + SSD1306_PADDLE_LENGTH;
}

static inline bool is_ball_in_paddle_x_range(const Circle *const p_circle, const Paddle *const p_paddle) {
    return is_ball_right_of_paddle_left(p_circle, p_paddle) && is_ball_left_of_paddle_right(p_circle, p_paddle);
}

static inline bool is_ball_at_paddle_y_level(const Circle *const p_circle) {
    return p_circle->y + SSD1306_BALL_RADIUS >= SSD1306_PADDLE_Y;
}

static inline bool is_paddle_hit(const Circle *const p_circle, const Paddle *const p_paddle) {
    return is_ball_in_paddle_x_range(p_circle, p_paddle) && is_ball_at_paddle_y_level(p_circle);
}


#endif /* INC_PONG_GAME_CHECKS_H_ */
