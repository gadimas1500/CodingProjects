`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: UCSC CSE 100L
// Engineer: Gabriel Dimas
// 
// Create Date: 03/29/2022 06:13:05 PM
// Design Name: HelloWorld
// Module Name: myOR
// Project Name: HelloWorld
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module myOR(
    input A,
    input A_button,
    input B,
    input D,
    output OR,    //LED LD1
    output NOT, //LED LD0
    output XOR,    //LED LD2
    output OOR  //led ld3
    );
    assign NOT = !A_button;                    //I: sw0, O: led ld0
    assign OR = A | B;                //I: sw0 & sw1, O: LED LD1
    assign XOR = (!A & B) | (A & !B);   //I: sw0 &sw1, O: led ld2
    assign OOR = A | B | D;             //I: sw0 & sw1 & sw2, O: led ld3
endmodule
