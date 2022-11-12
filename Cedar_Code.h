// Cedar_Code Class
// # CEDAR Logic RAM memory file.
// The file format is : "hex_address : hex_data"
// Object Class will allow output to Cedar Logic RAM file in correct format

#pragma once
#include <iostream> // standard library

using namespace std;

class Cedar_Code
{
private:
    int Instruction_Type;       // sort types by Address/Data field size
    string Mnemonic;            // Cedar_Code object properties
    int Address;                // Address to be assigned in output Cedar RAM memory file    
    string Separator = " : ";   // formatting separator
    char Code_1;                // OpCode msb
    char Code_2;                // OpCode 2nd msb
    char Code_3;                // OpCode 3rd msb
    char Code_4;                // OpCode lsb
    string Data_Field;          // Data field from Assembly program code
    string Description;         // Op decription

public:
    // constructors
    Cedar_Code(); 
    Cedar_Code(int type, string instruction, char code_1, char code_2, char code_3, char code_4, string inst_comments);
    Cedar_Code(string instruction, string data_field);

    //setters & getters 
    int get_Instruction_Type();
    string get_Mnemonic();
    int get_Address();
    string get_Separator();
    char get_Code_1();
    char get_Code_2();
    char get_Code_3();
    char get_Code_4();
    string get_Data_Field();
    string get_Description();

    void set_Instruction_Type(int inst_type);
    void set_Mnemonic(string mneumonic);
    void set_Address(int address);
    void set_Code_1(char c1);
    void set_Code_2(char c2);
    void set_Code_3(char c3);
    void set_Code_4(char c4);
    void set_Data_Field(string data_field);
    void set_Description(string comments);
};

