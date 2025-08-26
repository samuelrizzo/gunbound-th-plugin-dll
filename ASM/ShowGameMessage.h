/**
 * @file ShowGameMessage.h
 * @brief Declaration of the ASM-based game message display routine for the Gunbound client.
 *
 * This header exposes the ShowGameMessage function, which displays a message in the game
 * with specified color and icon. The implementation uses x86 inline assembly and absolute
 * addresses tied to a specific client version, so version changes may invalidate the
 * hardcoded offsets.
 *
 * Dependencies: requires Windows headers for basic types.
 *
 * @date 2025-08-26
 */

#pragma once

#include <windows.h>

/**
 * @brief Displays a message in the game interface.
 *
 * Invokes the game's internal message display function with the provided parameters.
 * The message appears in the game's UI with the specified color and icon styling.
 * Implemented in `ShowGameMessage.cpp` using inline ASM.
 *
 * Assembly implementation details:
 * - Calls native functions at addresses 0x0044A230 and 0x00527860
 * - Parameters pushed in reverse order (message, color, icon)
 * - Uses standard calling convention
 * - Calls both functions sequentially for complete message display
 *
 * Contract:
 * - message must be a valid null-terminated string
 * - color and icon values should be valid for the game's display system
 * - Call site must run in the correct client context compatible with the address
 *
 * @param message Pointer to the null-terminated message string to display.
 * @param color Color code for the message display.
 * @param icon Icon code to show alongside the message.
 */
void ShowGameMessage(int icon, int color, const char *message);