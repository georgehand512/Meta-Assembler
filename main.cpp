// Meta Assembler.cpp 
// George Hand N1050297
// 

#include "global.h"

int main()
{
    read_instruction_set_refernce();    // Read Instruction Set Reference from "Resource Files/Instruction_Set.txt"

    read_assembly_program();            // Read program to be converted "Resource Files/Assembly_Program.txt"

    set_reference_constants();          // Cross reference Assembly data to Instruction Set Reference and update constant OpCode values

    set_4_bit_opcodes();                // Validate 4 Bit Instructions, complete OpCode or generate error message in comments

    set_12_bit_nonBranch_opcodes();     // Validate 12 Bit Instructions, complete OpCode or generate error message in comments

    set_load_constants();               // loads constants Address & Data into LOAD instructions

    assign_Cedar_RAM_Address();         // Assigns instruction Addresses from 000 or "ORG" instruction value

    set_Branch_opcodes();               // Complete LABEL destinations and Branch to Addresses to complete ALL OpCodes

    write_CEDAR_Logic_RAM_file();       // Writes Cedar Logic "Resource Files/Cedar Logic Ram Memory File.cdm" and displays on screen
}