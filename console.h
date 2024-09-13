/**
 * @file console.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-09-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __CONSOLE_H
#define __CONSOLE_H

#ifdef __cplusplus
extern "C" {
#endif

/*  */
#pragma region includes

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma endregion includes

/*  */
#pragma region typedef

typedef struct _command_t {
    const char *command;
    void (*function)(int argc, char **argv);
    struct _command_t *next;
} command_t;

#pragma endregion typedef

/*  */
#pragma region defines

#pragma endregion defines

/*  */
#pragma region Exported Functions

void console_init(command_t *commands);
void console_handler(void);

#pragma endregion Exported Functions

#ifdef __cplusplus
}
#endif

#endif  // __CONSOLE_H
