// Function to set 12 bit op/field code instructions from data field
// 12 Bit Instructions contain data or address fields in the Hex format "AAA" or "DDD" (000 - FFF) 
// 12 Bit Instructions have been assigned as type - 3 (having 3 Hex chars in Data/Address field)

#pragma once
#include "global.h"	// global variables

void set_12_bit_nonBranch_opcodes();