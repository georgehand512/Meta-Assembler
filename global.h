// Global variables

#pragma once

// Standard Library
#include <iostream>		// Standard Input/Output Streams library
#include <fstream>		// File read/write library
#include <iomanip>		// Output formatting library
#include <string>		// String manipulation library
#include <sstream>		// String stream library used in converting strings to char

// Class
#include "Cedar_Code.h" // Class which contains all information related to one Cedar_Code instruction

// Functions
#include "read_instruction_set_refernce.h"	// Read Instruction Set Reference from "Resource Files/Instruction_Set.txt"
#include "read_assembly_program.h"			// Read program to be converted "Resource Files/Assembly_Program.txt"
#include "set_reference_constants.h"		// Cross reference Assembly data to Instruction Set Reference and update constant OpCode values
#include "set_4_bit_opcodes.h"				// Validate 4 Bit Instructions, complete OpCode or generate error message in comments
#include "set_12_bit_nonBranch_opcodes.h"	// Validate 12 Bit Instructions, complete OpCode or generate error message in comments
#include "set_load_constants.h"				// loads constants Address & Data into LOAD instructions
#include "assign_Cedar_RAM_Address.h"		// Assigns instruction Addresses from 000 or "ORG" instruction value
#include "set_Branch_opcodes.h"				// Complete LABEL destinations and Branch to Addresses to complete ALL OpCodes
#include "write_CEDAR_Logic_RAM_file.h"		// Writes Cedar Logic "Resource Files/Cedar Logic Ram Memory File.cdm" and displays on screen

// Delcare constants
const int Max_Address = 4095; // Max Ram address of 0xFFF

//Declare variables
extern int ref_instruction_count;		// holds number of instructions in the Instruction Set refeerence
extern int program_instruction_count;	// holds number of instructions in the User Assembler Program
extern int error_count;					// maintains an instruction/data/format error count
extern int last_add;	// stores value of last address assigned - for use if last instruction is a Label so can add additional Address
extern int null_add;	// 765357 is Hex BADAD, which signifies BAD ADDRESS assigned as error address
extern int free_add;	// 63982 is Hex F9EE, which signifies FREE ADDRESS a valid instruction awaiting address assignment

extern char null_code;	// 0 is written to blank out invalid or Label OpCodes

extern Cedar_Code ref_instruction_set[50];	// Array of Cedar_Code instruction objects - Instruction Set Reference limit
extern Cedar_Code program_instructions[150];// Array of Cedar_Code instruction objects - Limits Program size