/*
 *   motors.h
 *
 *   Created on: Oct 20, 2020
 *    Author: amr essam
 */

#define MOTOR_DDR	DDRC
#define MOTOR_PORT	PORTC
#define MOTOR_RIGHT_FWD_PIN		PC0
#define MOTOR_RIGHT_REV_PIN		PC1
#define MOTOR_LEFT_FWD_PIN		PC2
#define MOTOR_LEFT_REV_PIN		PC3

#define FORWARD_MODE() { MOTOR_PORT |= (1 << MOTOR_RIGHT_FWD_PIN) | (1 << MOTOR_LEFT_FWD_PIN); MOTOR_PORT &= ~((1 << MOTOR_RIGHT_REV_PIN) | (1 << MOTOR_LEFT_REV_PIN)); }
#define REVERSE_MODE() { MOTOR_PORT |= (1 << MOTOR_RIGHT_REV_PIN) | (1 << MOTOR_LEFT_REV_PIN); MOTOR_PORT &= ~((1 << MOTOR_RIGHT_FWD_PIN) | (1 << MOTOR_LEFT_FWD_PIN)); }
#define RIGHT_MODE()   { MOTOR_PORT |= (1 << MOTOR_RIGHT_REV_PIN) | (1 << MOTOR_LEFT_FWD_PIN); MOTOR_PORT &= ~((1 << MOTOR_RIGHT_FWD_PIN) | (1 << MOTOR_LEFT_REV_PIN)); }
#define LEFT_MODE()    { MOTOR_PORT |= (1 << MOTOR_RIGHT_FWD_PIN) | (1 << MOTOR_LEFT_REV_PIN); MOTOR_PORT &= ~((1 << MOTOR_RIGHT_REV_PIN) | (1 << MOTOR_LEFT_FWD_PIN)); }
void set_direction(unsigned char ir_right ,unsigned char ir_left);
