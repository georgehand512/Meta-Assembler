// Cedar_Code Class
// # CEDAR Logic RAM memory file.
// The file format is : "hex_address : hex_data"
// Class will allow output to Cedar Logic RAM file in correct format

#include "Cedar_Code.h"

Cedar_Code::Cedar_Code()
{
}

Cedar_Code::Cedar_Code(int inst_type, string instruction, char code_1, char code_2, char code_3, char code_4, string inst_comments)
{
    Instruction_Type = inst_type;
    Mnemonic = instruction;
    Address = 63982;            // Set to Free or Hex F9EE
    Separator = " : ";
    Code_1 = code_1;
    Code_2 = code_2;
    Code_3 = code_3;
    Code_4 = code_4;
    Data_Field = "       ";
    Description = inst_comments;
}

Cedar_Code::Cedar_Code(string instruction, string data_field)
{
    Instruction_Type = 9;
    Mnemonic = instruction;
    Address = 63982;            // Set to Free or Hex F9EE
    Separator = " : ";
    Code_1 = 0;
    Code_2 = 0;
    Code_3 = 0;
    Code_4 = 0;
    Data_Field = data_field;
    Description = "       ";
}

int Cedar_Code::get_Instruction_Type()
{
    return Instruction_Type;
}

string Cedar_Code::get_Mnemonic()
{
    return Mnemonic;
}

int Cedar_Code::get_Address()
{
    return Address;
}

string Cedar_Code::get_Separator()
{
    return Separator;
}

char Cedar_Code::get_Code_1()
{
    return Code_1;
}

char Cedar_Code::get_Code_2()
{
    return Code_2;
}

char Cedar_Code::get_Code_3()
{
    return Code_3;
}

char Cedar_Code::get_Code_4()
{
    return Code_4;
}

string Cedar_Code::get_Data_Field()
{
    return Data_Field;
}

string Cedar_Code::get_Description()
{
    return Description;
}


// Setters

void Cedar_Code::set_Instruction_Type(int inst_type)
{
    Instruction_Type = inst_type;
}

void Cedar_Code::set_Mnemonic(string mneumonic)
{
    Mnemonic = mneumonic;
}

void Cedar_Code::set_Address(int address)
{
    Address = address;
}

void Cedar_Code::set_Code_1(char c1)
{
    Code_1 = c1;
}

void Cedar_Code::set_Code_2(char c2)
{
    Code_2 = c2;
}

void Cedar_Code::set_Code_3(char c3) 
{
    Code_3 = c3;
}

void Cedar_Code::set_Code_4(char c4)
{
    Code_4 = c4;
}

void Cedar_Code::set_Data_Field(string data_field)
{
    Data_Field = data_field;
}

void Cedar_Code::set_Description(string comments)
{
    Description = comments;
}