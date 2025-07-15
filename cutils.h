#ifndef _CUTILS_H_
#define _CUTILS_H_

#ifdef __cplusplus
extern "C"
{
#endif

// Importations:
#include <stdio.h>
#include <stdlib.h>


// Terminal colors:
#define BASE_TERMINAL      "\033[m"        // Reset terminal.
#define BOLD               "\033[1m"       // Bold terminal.
#define BASE_TERMINAL_BOLD "\033[m\033[1m" // Reset and bold terminal.
#define ITALIC             "\033[3m"       // Italic terminal.
#define UNDERLINE          "\033[4m"       // Underline terminal.
#define RED_COLOR          "\033[31m"      // Red terminal.
#define GREEN_COLOR        "\033[32m"      // Green terminal.
#define YELLOW_COLOR       "\033[33m"      // Yellow terminal.
#define BLUE_COLOR         "\033[34m"      // Blue terminal.
#define MAGENTA_COLOR      "\033[35m"      // Magenta terminal.
#define CYAN_COLOR         "\033[36m"      // Cyan terminal.

// Math variables:
#define PI_L  3.1415926535897932385L                                // Pi (long double).
#define PI_LL 3.14159265358979323846264338327950288419716939937510L // Pi (long long double).

// Clear terminal function:
extern void clear_terminal(void)
{
	fputs("\033[2J\033[H", stdout);
	fflush(stdout);
}

// Pause function:
extern void petc(void)
{
	signed int characters;
	while((characters = getchar()) != EOF && characters != '\n');
	fputs("Press \"ENTER\" to continue...", stdout);
	getchar();
}

// Unsigned char verify OS function:
extern unsigned char verify_os_u(void)
{
	#ifdef _WIN32 || _WIN64 // For Windows.
		return 1u;
	#elif defined(__linux__) // For Linux.
		return 2u;
	#else // For another OS.
		return 0u;
	#endif
}

// Signed char verify OS function:
extern signed char verify_os(void)
{
	#ifdef _WIN32 || _WIN64 // For Windows.
		return 1;
	#elif defined(__linux__) // For Linux.
		return 2;
	#else // For another OS.
		return 0;
	#endif
}

// Read "READ-ME" function:
extern void rrmf(void)
{
	#ifdef _WIN32 || _WIN64 // For Windows.
		puts("When you enter just press \"space\" to advance 1 page, \"enter\" to go down 1 line and \"Ctrl-C\" to quit \"READ-ME\"!");
		petc();
		system("more /E /C /P \"..\\README.md\"");
	#elif defined(__linux__) // For Linux.
		puts("When you enter press \"q\" to quit, \"enter\" to go down to the next line, \"space\" to go down next page, and type \"/ + text\" to search for text!");
		petc();
		system("less \"../README.md\"");
	#endif
}

// Easter egg function:
extern void easter_egg_function(void)
{
	// Basic commands:
	printf("%sCongratulations!!!%s You just discovered a new easter egg! (please don't say it to anywhone ok!)\n", BOLD, BASE_TERMINAL);
	puts("This is the link to our github account! If you want to see our projects, codes, etc...");
	puts("Link: https://github.com/GodProgrammer512/");

	// Command to open the link on browser:
	#ifdef _WIN32 || _WIN64 // For Windows.
	  system("start https://github.com/GodProgrammer512/");
	#elif defined(__linux__) // For Linux.
	  system("xdg-open https://github.com/GodProgrammer512/");
	#endif

	// Pause APP:
	petc();
}

#ifdef __cplusplus
}
#endif

// End code:
#endif