// ASM.CPP v1.0b
// (c) 1993 Frank Bruno
// all rights reserved
// Part of a project for Professor Chang
// Partial fulfillment for the degree of
// M.S.E.E.
// This program is written in C++ for the Borland C++ 3.1
// Compiler, although it may be portable to other C++ compilers
// or environments

// includes
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

// prototypes
int hextoi(char orgval[3], int count);
int make_out(char *out, int input);

// main program
void main(int argc, char *argv[])
{
	FILE *fp, *out_fp;
	char buffer[80], op_str, temp_buf[4], **endptr;
	char *buff_up, address[4], *c_ptr, arg2[5], out[17];
	int temp, streams_closed, temp_var, i_flag, in_done, indirect;
	int counter, char_count, done, i, add_count, in_char_count;
	int org_count, end_count, var_count, line_num, in_line, org_val;
	int when_count = 3;
	unsigned int program[4096];
	struct symbol			// sybol table
	{
		char name[4];   // Variable Names
		int address;    // Variable Addresses
	};
	struct symbol Symbol[4096];	// Define 4096 symbols


// Print opening screen
	clrscr();
	cout << "\nBasic Computer Assembler\n";
	cout << "(c) 1993 Frank Bruno, All rights reserved\n";

// check to be sure of the proper command line
	if (argc <= 2)   		// Not the proper number of arguments
	{
		cout << "Usage:\n";
		cout << "	ASM INFILE OUTFILE.VHD\n";
		cout << " No Extension is assumed, so the assembler\n";
		cout << " will process the INFILE given, if no\n";
		cout << " 'ext' is defined, then none will be used.\n";
		exit(1);
	}


// This first section of code will parse the file specified in
// argv[1], and act as a first pass of the assembler
// First, we must open the file
	fp = fopen(argv[1], "r");
	if (!fp)     				// check if error opening file
	{
		cout << "Error opening file... " << argv[1] << " ...for read\n";
		cout << "Terminating...";
		exit(1);
	}

// initialize global counters
	org_count = 0;
	end_count = 0;
	var_count = 0;
	line_num = 0;
	in_line = 0;

// Get the data
	while (fgets(buffer, 80, fp) != NULL) // read in data 1 line at a time
	{
		buff_up = strupr(buffer);						// convert buffer to upper case
		counter = 0;
		in_line++;
		char_count = 0;
		done = 0;
// Main Parsing Section, Here we will ocate and define all variables
		while (*(buff_up + counter) != '\0')
		{
			if (done == 0)
			{
				switch (*(buff_up + counter))
				{
					// A ',' indicates a variable definition
					case ',':
						if ((char_count > 3) || (char_count < 0))
						{
							cout << "Error on line number: " << in_line << ".\n";
							cout << "Terminating....\n";
							exit(1);
						}
						temp_buf[char_count] = '\0';
						strcpy(Symbol[var_count].name, temp_buf);
						Symbol[var_count].address = line_num;
						char_count = 0;
						var_count++;
						done = 1;
						break;
					case ' ':
						if (char_count == 3)
						{
							temp_buf[char_count] = '\0';
							if ((temp_var = strcmp(temp_buf, "ORG")) == 0)
							{
								org_count++;
								temp = 0;
								counter++;
								while ((*(buff_up + counter) >= '0') && (*(buff_up + counter) <= '9'))
								{
									address[temp] = *(buff_up + counter);
									temp++;
									if (temp > 3)
									{
										cout << "Address may only be represented by four Hex\n";
										cout << "Digits or less. This error has forced termination\n";
										cout << "Occured at line number: " << in_line;
										exit(1);
									}
									counter++;
								}
								line_num = 0;
								temp--;
								line_num = hextoi(address, temp);
								done = 1;
								line_num--;
							}
							else if ((temp_var = strcmp(temp_buf, "END")) == 0)
							{
								end_count++;
							}
							else
							{
								char_count = 0;
							}
						}
						break;
					case '/':
						if (counter == 0)
						{
							line_num--;
						}
						done = 1;
						break;
					default:
						if (char_count > 3)
						{
							cout << "Error, word too long, on line number " << line_num << "\n";
							exit(1);
						}
						temp_buf[char_count] = *(buff_up + counter);
						char_count++;
						break;

				}
			}
			counter++;
		}
		line_num++;
	}

// If no origin is specified, default to an org of 0
	if (org_count == 0)
	{
		cout << "No origin Specified, Defaulting to org 0\n";
		cout << "First Pass Complete, Symbol Table Built:\n";
		exit(1);
	}

// If no end specified, quit
	if (end_count == 0)
	{
		cout << "No End Specified, Error in coding\n";
		exit(1);
	}

// Status the user
	cout << "First pass complete.\n" << "Symbol Table Built.\n";

// output the variables
	for (i = 0; i <= var_count - 1; i++)
	{
		cout << Symbol[i].name << ",     " << Symbol[i].address << "\n";
	}
	cout << "\nSecond Pass...\n";
	fclose(fp);

// Open file for output
	out_fp = fopen(argv[2], "w");
	if (!out_fp)
	{
		cout << "Error opening file " << argv[2] << " For output!";
		cout << "Terminating...";
		exit(1);
	}

	// Write out standard VHDL header info for testbench
	fprintf(out_fp, "----------------------------------------\n");
	fprintf(out_fp, "-- Basic Computer VHDL Testbench\n");
	fprintf(out_fp, "-- Generated by the Basic Computer\n");
	fprintf(out_fp, "-- Assembler by Frank Bruno\n");
	fprintf(out_fp, "-- Original file: %s\n", argv[1]);
	fprintf(out_fp, "----------------------------------------\n\n");
	fprintf(out_fp, "ENTITY test_%s IS\n\n", argv[1]);
	fprintf(out_fp, "END test_%s;\n\n", argv[1]);
	fprintf(out_fp, "ARCHITECTURE beh_test_%s OF test_%s IS\n\n", argv[1], argv[1]);
	fprintf(out_fp, "COMPONENT basic_comp\n");
	fprintf(out_fp, "PORT(clock          : IN     bit;\n");
	fprintf(out_fp, "     load           : IN     bit;\n");
	fprintf(out_fp, "     start          : IN     bit;\n");
	fprintf(out_fp, "     reset          : IN     bit;\n");
	fprintf(out_fp, "     address_in     : IN     integer range 0 to 4095;\n");
	fprintf(out_fp, "     instr          : IN     bit_vector(15 DOWNTO 0);\n");
	fprintf(out_fp, "     inpr           : IN     bit_vector(7 DOWNTO 0);\n");
	fprintf(out_fp, "     fgi            : IN     bit;\n");
	fprintf(out_fp, "     ar             : BUFFER bit_vector(11 DOWNTO 0);\n");
	fprintf(out_fp, "     ir             : BUFFER bit_vector(15 DOWNTO 0);\n");
	fprintf(out_fp, "     tr             : BUFFER bit_vector(11 DOWNTO 0);\n");
	fprintf(out_fp, "     dr             : BUFFER bit_vector(11 DOWNTO 0);\n");
	fprintf(out_fp, "     i              : BUFFER bit;\n");
	fprintf(out_fp, "     e              : BUFFER bit;\n");
	fprintf(out_fp, "     ac             : BUFFER bit_vector(15 DOWNTO 0);\n");
	fprintf(out_fp, "     ien            : BUFFER bit;\n");
	fprintf(out_fp, "     outr           : BUFFER bit_vector(7 DOWNTO 0);\n");
	fprintf(out_fp, "     fgo            : BUFFER bit\n");
	fprintf(out_fp, "     );\nEND COMPONENT;\n");
	fprintf(out_fp, "  SIGNAL clock : bit;\n  SIGNAL load : bit;\n  SIGNAL start : bit;\n");
	fprintf(out_fp, "  SIGNAL reset : bit;\n");
	fprintf(out_fp, "  SIGNAL address_in : integer range 0 to 4095;\n");
	fprintf(out_fp, "  SIGNAL instr : bit_vector(15 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL inpr : bit_vector(7 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL fgi : bit;\n");
	fprintf(out_fp, "  SIGNAL ar : bit_vector(11 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL ir : bit_vector(15 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL tr : bit_vector(11 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL dr : bit_vector(11 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL i : bit;\n  SIGNAL e : bit;\n");
	fprintf(out_fp, "  SIGNAL ac : bit_vector(15 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL ien : bit;\n");
	fprintf(out_fp, "  SIGNAL outr : bit_vector(7 DOWNTO 0);\n");
	fprintf(out_fp, "  SIGNAL fgo : bit;\n\nBEGIN\n\n");
	fprintf(out_fp, "  u1: basic_comp\n");
	fprintf(out_fp, "  PORT MAP(clock => clock,\n    load => load,\n");
	fprintf(out_fp, "    start => start,\n    reset => reset,\n");
	fprintf(out_fp, "    address_in => address_in,\n");
	fprintf(out_fp, "    instr => instr,\n    inpr => inpr,\n");
	fprintf(out_fp, "    fgi => fgi,\n    ar => ar,\n    ir => ir,\n");
	fprintf(out_fp, "    tr => tr,\n    dr => dr,\n    i => i,\n");
	fprintf(out_fp, "    e => e,\n    ac => ac,\n    ien => ien,\n");
	fprintf(out_fp, "    outr => outr,\n    fgo => fgo);\n\n");
	fprintf(out_fp, "  clock_gen:\n  PROCESS\n  BEGIN\n");
	fprintf(out_fp, "    clock <= '0' AFTER 40 ns;\n");
	fprintf(out_fp, "    WAIT FOR 40 ns;\n    clock <= '1' AFTER 40 ns;\n");
	fprintf(out_fp, "    WAIT FOR 40 ns;\n  END PROCESS;\n\n");
	fprintf(out_fp, "  PROCESS\n    VARIABLE state : integer := 0;\n\n");
	fprintf(out_fp, "    BEGIN\n");
	fprintf(out_fp, "      WAIT UNTIL clock'EVENT AND clock = '1';\n");
	fprintf(out_fp, "      CASE state IS\n");
	fprintf(out_fp, "        WHEN 0 =>\n");
	fprintf(out_fp, "          reset <= '1';\n          start <= '0';\n");
	fprintf(out_fp, "          state := 1;\n");
	fprintf(out_fp, "        WHEN 1 =>\n");
	fprintf(out_fp, "          reset <= '0';\n");
	fprintf(out_fp, "          load <= '1';\n");
	fprintf(out_fp, "          state := 2;\n");
	fprintf(out_fp, "        WHEN 2 =>\n");

	// Open Input file again for input
	fp = fopen(argv[1], "r");
	if (!fp)     				// check if error opening file
	{
		cout << "Error opening file... " << argv[1] << " ...for read\n";
		cout << "Terminating...";
		exit(1);
	}

// initialize global counters
	org_count = 0;
	end_count = 0;
	line_num = 0;
	in_line = 0;

// Get the data
	while (fgets(buffer, 80, fp) != NULL) // read in data 1 line at a time
	{
		buff_up = strupr(buffer);						// convert buffer to upper case
		counter = 0;
		in_line++;
		char_count = 0;
		done = 0;

// read in the file for parsing
		while (*(buff_up + counter) != '\0')
		{
			if (done == 0)
			{
				switch (*(buff_up + counter))
				{
					case ',':
						char_count = 0;
						break;
					case ' ':
						i_flag = 0;
						if (char_count > 3)
						{
							cout << "Word longer than 3 characters on line: " << line_num << "\n";
							exit(1);
						}
						if (char_count > 0)
						{
							temp_buf[char_count] = '\0';
							counter++;
							in_done = 0;
							indirect = 0;
							in_char_count = 0;
							if ((temp_var = strcmp(temp_buf, "ORG")) == 0)
							{
								if (org_count >= 1)
								{
									for (i = org_val; i < line_num; i++)
									{
										// output the testbench
										fprintf(out_fp, "          address_in <= %u;\n", i);
										temp = make_out(out, program[i]);
										fprintf(out_fp, "          instr <= \"%s\";\n", out);
										fprintf(out_fp, "          state := %u;\n", when_count);
										fprintf(out_fp, "        WHEN %u =>\n", when_count++);
									}
									org_count = 0;
								}
								org_count++;
								temp = 0;
								//counter++;
								while ((*(buff_up + counter) >= '0') && (*(buff_up + counter) <= '9'))
								{
									address[temp] = *(buff_up + counter);
									temp++;
									if (temp > 3)
									{
										cout << "Address may only be represented by four Hex\n";
										cout << "Digits or less. This error has forced termination\n";
										cout << " Occured at line number: " << in_line;
										exit(1);
									}
									counter++;
								}
								temp--;
								line_num = hextoi(address, temp);
								org_val = line_num;
								done = 1;
							}
							else
							{
								while (*(buff_up + counter) != '\0')
								{
									if (in_done == 0)
									{
										switch (*(buff_up + counter))
										{
											case '/':
												in_done = 1;
												break;
											case 'I':
												if (((*(buff_up + counter + 1) == ' ') || (*(buff_up + counter + 1) == '\0')) && (in_char_count == 0))
												{
													indirect = 1;
													in_done = 1;
												}
												else
												{
													in_char_count++;
												}
												break;
											case ' ':
												if (in_char_count > 0)
												{
													arg2[in_char_count] = '\0';
												}
												in_char_count = 0;
												break;
											default:
												arg2[in_char_count] = *(buff_up + counter);
												in_char_count++;
												break;
										}
									}
									counter++;
								}
								if ((temp_var = strcmp(temp_buf, "END")) == 0)
								{
									end_count++;
									for (i = org_val; i < line_num; i++)
									{
										// output the testbench
										fprintf(out_fp, "          address_in <= %u;\n", i);
										temp = make_out(out, program[i]);
										fprintf(out_fp, "          instr <= \"%s\";\n", out);
										fprintf(out_fp, "          state := %u;\n", when_count);
										fprintf(out_fp, "        WHEN %u =>\n", when_count++);
									}
									// END of file coding
									fprintf(out_fp, "          load <= '0';\n");
									fprintf(out_fp, "          start <= '1';\n");
									fprintf(out_fp, "          reset <= '1';\n");
									fprintf(out_fp, "          state := %u;\n", when_count);
									fprintf(out_fp, "        WHEN %u =>\n", when_count);
									fprintf(out_fp, "          start <= '0';\n");
									fprintf(out_fp, "          reset <= '0';\n");
									fprintf(out_fp, "          state := %u;\n", ++when_count);
									fprintf(out_fp, "        WHEN OTHERS =>\n");
									fprintf(out_fp, "      END CASE;\n");
									fprintf(out_fp, "  END PROCESS;\n");
									fprintf(out_fp, "END beh_test_%s;\n\n", argv[1]);
									fprintf(out_fp, "CONFIGURATION config_%s OF test_%s IS\n", argv[1], argv[1]);
									fprintf(out_fp, "  FOR beh_test_%s\n", argv[1]);
									fprintf(out_fp, "    FOR u1: basic_comp\n");
									fprintf(out_fp, "      USE ENTITY work.basic_comp;\n");
									fprintf(out_fp, "    END FOR;\n");
									fprintf(out_fp, "  END FOR;\n");
									fprintf(out_fp, "END config_%s;\n", argv[1]);
								}
								else if ((temp_var = strcmp(temp_buf, "DEC")) == 0)
								{
								program[line_num] = atol(arg2);
								}
								else if ((temp_var = strcmp(temp_buf, "HEX")) == 0)
								{
								program[line_num] = hextoi(arg2, (strlen(arg2)-1));
								}
								else if ((temp_var = strcmp(temp_buf, "AND")) == 0)
								{
								// set base operation number
									if (indirect == 0)
									{
										program[line_num] = 0;
									}
									else
									{
										program[line_num] = 32768;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
									// code to implement
								}
								else if ((temp_var = strcmp(temp_buf, "ADD")) == 0)
								{
									// code to implement
									// set base operation number
									if (indirect == 0)
									{
										program[line_num] = 4096;
									}
									else
									{
										program[line_num] = 36864;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
								}
							else if ((temp_var = strcmp(temp_buf, "LDA")) == 0)
								{
								// code to implement
									if (indirect == 0)
									{
										program[line_num] = 8192;
									}
									else
									{
										program[line_num] = 40960;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
								}
								else if ((temp_var = strcmp(temp_buf, "STA")) == 0)
								{
								// code to implement
									if (indirect == 0)
									{
										program[line_num] = 12288;
									}
									else
									{
										program[line_num] = 45056;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
								}
								else if ((temp_var = strcmp(temp_buf, "BUN")) == 0)
								{
								// code to implement
									if (indirect == 0)
									{
										program[line_num] = 16384;
									}
									else
									{
										program[line_num] = 49152;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
								}
								else if ((temp_var = strcmp(temp_buf, "BSA")) == 0)
								{
								// code to implement
									if (indirect == 0)
									{
										program[line_num] = 20480;
									}
									else
									{
										program[line_num] = 53248;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
								}
								else if ((temp_var = strcmp(temp_buf, "ISZ")) == 0)
								{
								// code to implement
									if (indirect == 0)
									{
										program[line_num] = 24576;
									}
									else
									{
										program[line_num] = 57344;
									}
									// set rest of instruction
									if ((arg2[0] > 0) && (arg2[0] < 9))
									{
										program[line_num] += strtol(arg2, endptr, 16);
									}
									else
									{
										for ( i = 0; i <= var_count; i++)
										{
											if ((temp_var = strcmp(Symbol[i].name, arg2)) == 0)
											{
												program[line_num] += Symbol[i].address;
												i = var_count;
											}
											else if (i == var_count)
											{
												cout << "variable not legal on line number ";
												cout << line_num << "\n";
											}
										}
									}
								}
								else if ((temp_var = strcmp(temp_buf, "CLA")) == 0)
								{
								// code to implement
								program[line_num] = 30720;
								}
								else if ((temp_var = strcmp(temp_buf, "CLE")) == 0)
								{
								// code to implement
								program[line_num] = 29696;
								}
								else if ((temp_var = strcmp(temp_buf, "CMA")) == 0)
								{
								// code to implement
								program[line_num] = 28184;
								}
								else if ((temp_var = strcmp(temp_buf, "CME")) == 0)
								{
								// code to implement
								program[line_num] = 28928;
								}
								else if ((temp_var = strcmp(temp_buf, "CIR")) == 0)
								{
								// code to implement
								program[line_num] = 28800;
								}
								else if ((temp_var = strcmp(temp_buf, "CIL")) == 0)
								{
								// code to implement
								program[line_num] = 28736;
								}
								else if ((temp_var = strcmp(temp_buf, "INC")) == 0)
								{
								// code to implement
								program[line_num] = 28704;
								}
								else if ((temp_var = strcmp(temp_buf, "SPA")) == 0)
								{
								// code to implement
								program[line_num] = 28688;
								}
								else if ((temp_var = strcmp(temp_buf, "SNA")) == 0)
								{
								// code to implement
								program[line_num] = 28680;
								}
								else if ((temp_var = strcmp(temp_buf, "SZA")) == 0)
								{
								// code to implement
								program[line_num] = 28676;
								}
								else if ((temp_var = strcmp(temp_buf, "SZE")) == 0)
								{
								// code to implement
								program[line_num] = 28674;
								}
								else if ((temp_var = strcmp(temp_buf, "HLT")) == 0)
								{
								// code to implement
								program[line_num] = 28673;
								}
								else if ((temp_var = strcmp(temp_buf, "INP")) == 0)
								{
								// code to implement
								program[line_num] = 63488;
								}
								else if ((temp_var = strcmp(temp_buf, "OUT")) == 0)
								{
								// code to implement
								program[line_num] = 62464;
								}
								else if ((temp_var = strcmp(temp_buf, "SKI")) == 0)
								{
								// code to implement
								program[line_num] = 61952;
								}
								else if ((temp_var = strcmp(temp_buf, "SKO")) == 0)
								{
								// code to implement
								program[line_num] = 61696;
								}
								else if ((temp_var = strcmp(temp_buf, "ION")) == 0)
								{
								// code to implement
								program[line_num] = 61568;
								}
								else if ((temp_var = strcmp(temp_buf, "IOF")) == 0)
								{
								// code to implement
								program[line_num] = 61504;
								}
								else
								{
									cout << "Illegal Operand\n";
									cout << "Error on line number " << line_num << "\n";
									cout << "Terminating\n";
									exit(1);
								}
								line_num++;
								done = 1;
							}
						}
						break;
					case '/':
						if (counter == 0)
						{
							line_num--;
						}
						done = 1;
						break;
					default:
						if (char_count > 3)
						{
							cout << "Error, word too long, line number " << line_num << "\n";
							exit(1);
						}
						temp_buf[char_count] = *(buff_up + counter);
						char_count++;
						break;

				}
			}
			counter++;
		}
	}
	exit(0);
}

// the subroutine make_out will take a decimal number and output
// a 16 bit binary number
int make_out(char *out, int input)
{
	unsigned count = 0;
	int i;
	for (i = 15; i >= 0; i--)
	{
		if (input >= (count = pow(2, i)))
		{
			*(out + (15 - i)) = '1';
			input -= count;
		}
		else
		{
			*(out + (15 - i)) = '0';
		}
	}
	*(out + 16) = '\0';
	return 0;
}

// hextoi will take a hex number of length count and output an integer
int hextoi(char *orgval, int count)
{
	int current_val = 0;		// current integer value
	int temp;								// count variable
	for (temp = 0; temp <= count; temp++)
	{
		switch (orgval[temp])
		{
			case '0':
				break;
			case '1':
				current_val += pow(16, (count - temp));
				break;
			case '2':
				current_val += 2 * pow(16, (count - temp));
				break;
			case '3':
				current_val += 3 * pow(16, (count - temp));
				break;
			case '4':
				current_val += 4 * pow(16, (count - temp));
				break;
			case '5':
				current_val += 5 * pow(16, (count - temp));
				break;
			case '6':
				current_val += 6 * pow(16, (count - temp));
				break;
			case '7':
				current_val += 7 * pow(16, (count - temp));
				break;
			case '8':
				current_val += 8 * pow(16, (count - temp));
				break;
			case '9':
				current_val += 9 * pow(16, (count - temp));
				break;
			case 'A':
				current_val += 10 * pow(16, (count - temp));
				break;
			case 'B':
				current_val += 11 * pow(16, (count - temp));
				break;
			case 'C':
				current_val += 12 * pow(16, (count - temp));
				break;
			case 'D':
				current_val += 13 * pow(16, (count - temp));
				break;
			case 'E':
				current_val += 14 * pow(16, (count - temp));
				break;
			case 'F':
				current_val += 15 * pow(16, (count - temp));
				break;
			default:
				cout << "\nError in Assembler Subsystem: hextoi\n";
				exit(1);
		}
	}
	return current_val;
}




