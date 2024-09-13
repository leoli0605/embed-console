/**
 * @file console.c
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-09-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "console.h"

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

#pragma endregion typedef

/*  */
#pragma region Private Function Prototypes

#pragma endregion Private Function Prototypes

/*  */
#pragma region defines

#pragma endregion defines

/*  */
#pragma region variables

static command_t *p_commands = NULL;

#pragma endregion variables

/*  */
#pragma region External Functions

#pragma endregion External Functions

/*  */
#pragma region Exported Functions

void console_init(command_t *commands) {
    command_t *prev = NULL;
    command_t *curr = NULL;

    commands->next = NULL;
    if (p_commands == NULL) {
        p_commands = commands;
    } else {
        curr = p_commands;
        while (curr != NULL) {
            if (strcmp(commands->command, curr->command) <= 0) {
                commands->next = curr;
                if (prev) {
                    prev->next = commands;
                } else {
                    p_commands = commands;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            prev->next = commands;
        }
    }
}

void console_handler(void) {

}

#pragma endregion Exported Functions

/*  */
#pragma region Private Functions

#pragma endregion Private Functions

#ifdef __cplusplus
}
#endif
