/**
 * @file SendPacket.h
 * @brief Declaration of the ASM-based packet sending routine for the Gunbound client.
 *
 * This header exposes the SendPacket function, which copies the provided payload into the
 * client's internal buffer and invokes the native sending routine. The implementation uses
 * x86 inline assembly and absolute addresses tied to a specific client version, so version
 * changes may invalidate the hardcoded offsets.
 *
 * Dependencies: requires Windows headers for BYTE type.
 *
 * @date 2025-08-25
 */

#pragma once

#include <windows.h>

/**
 * @brief Sends a raw packet to the client.
 *
 * Copies the buffer pointed to by payload to the memory region expected by the client and
 * adjusts the packet size before invoking the internal send function. Implemented in
 * `SendPacket.cpp` using inline ASM.
 *
 * Assembly implementation details:
 * - Computes total length: sizeof(payload) + 4
 * - Sets destination base pointer from 0x006e3e28
 * - Copies payload data to destination [base + 0xA4]
 * - Writes packet length (WORD) at [base deref + 0x40A0]
 * - Prepares call context for native send routine
 *
 * Contract:
 * - payload must not be null
 * - total length is computed as sizeof(payload) + 4
 * - Call site must run in the correct client context compatible with the offsets
 *
 * @param payload Pointer to the packet data to send.
 */
void SendPacket(BYTE *payload);
