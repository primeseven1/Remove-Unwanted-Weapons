#pragma once

#include <stdint.h>
#include <vector>

void awaitKeyPress(uint8_t key);
uint8_t awaitKeyPress(std::vector<uint8_t> keys);