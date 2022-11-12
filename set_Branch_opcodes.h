// Complete LABEL destinations and Branch to Addresses to complete ALL OpCodes
// 
// Assign LABEL address as the address of the first valid instruction after the LABEL
// If the LABEL is the last instruction then the destination address is: Last Address + 1
// 
// Assign direct jump addresses to the LABEL assigned address
// For Branch instructions need to calculate relative data value: Branch Address +/- Label Address


#pragma once
#include "global.h"	// global variables

void set_Branch_opcodes();