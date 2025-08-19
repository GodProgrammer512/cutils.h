#ifndef _CUTILS_H_
#define _CUTILS_H_

// Importations:
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32 || _WIN64 // For Windows.
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#elif defined(__linux__) // For Linux.
	#include <unistd.h>
#endif


#ifdef __cplusplus
extern "C"
{
#endif

// Terminal colors:
#define BASE_TERMINAL      "\033[m"        // Reset terminal text.
#define BOLD               "\033[1m"       // Bold terminal text.
#define BASE_TERMINAL_BOLD "\033[m\033[1m" // Reset and bold terminal text.
#define ITALIC             "\033[3m"       // Italic terminal text.
#define UNDERLINE          "\033[4m"       // Underline terminal text.
#define BLACK_COLOR        "\033[30m"      // Black terminal text.
#define RED_COLOR          "\033[31m"      // Red terminal text.
#define GREEN_COLOR        "\033[32m"      // Green terminal text.
#define YELLOW_COLOR       "\033[33m"      // Yellow terminal text.
#define BLUE_COLOR         "\033[34m"      // Blue terminal text.
#define MAGENTA_COLOR      "\033[35m"      // Magenta terminal text.
#define CYAN_COLOR         "\033[36m"      // Cyan terminal text.
#define WHITE_COLOR        "\033[37m"      // White terminal text.

// Math utils:
#ifdef IMPORT_MATH_UTILS
	// Math variables:
	#define PI_S_L 3.14L                  // Approximate pi (short type in long double).
	#define PI_L_L 3.1415926535897932385L // Pi (Long type in long double).

	// Function to calculate the circumference:
	long double calc_circumfer(long double pi_val_, long double radius_val_)
	{
		return 2.0L * pi_val_ * radius_val_;
	}
	// Function to calculate the area of a circle:
	long double calc_circ_area(long double pi_val_, long double radius_val_)
	{
		return pi_val_ * (radius_val_ * radius_val_);
	}

	// Function to calculate the volume of a sphere:
	long double calc_spher_vol(long double pi_val_, long double radius_val_)
	{
		return (4.0L / 3.0L) * pi_val_ * (radius_val_ * radius_val_ * radius_val_);
	}
#endif

// Clear terminal function:
static inline void clear_terminal(void)
{
	fputs("\033[2J\033[H", stdout);
	fflush(stdout);
}

// Pause function:
static inline void petc(void)
{
	signed int characters; // Variable to store characters.
	while((characters = getchar()) != EOF && characters != '\n');
	fputs("Press \"ENTER\" to continue...", stdout);
	getchar();
}

// Alternative pause function (without pausing, just saying to press "ENTER"):
static inline void petc_a(void)
{
	signed int characters; // Variable to store characters.
	fputs("Press \"ENTER\" to continue...", stdout);
	getchar();
}

// Unsigned char verify OS function:
static inline unsigned char verify_os_u(void)
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
static inline signed char verify_os(void)
{
	#ifdef _WIN32 || _WIN64 // For Windows.
		return 1;
	#elif defined(__linux__) // For Linux.
		return 2;
	#else // For another OS.
		return 0;
	#endif
}

// Seconds sleep function:
static inline void ssleep(unsigned int time)
{
	if(time == 0u)
	{
		return;
	}

	#ifdef _WIN32 || _WIN64 // For Windows.
		Sleep((DWORD)time * (DWORD)1000u);
	#else // For Linux.
		sleep(time);
	#endif
}

// Milliseconds sleep function:
static inline void mssleep(unsigned int time)
{
	if(time == 0UL)
	{
		return;
	}

	#ifdef _WIN32 || _WIN64 // For Windows.
		Sleep((DWORD)time);
	#else // For Linux.
		usleep((useconds_t)time * (useconds_t)1000u);
	#endif
}

// Read "READ-ME" function:
static inline void rrmf(void)
{
	#ifdef _WIN32 || _WIN64 // For Windows.
		puts("When you enter just press \"space\" to advance 1 page, \"enter\" to go down 1 line and \"Ctrl-C\" to quit \"READ-ME\"!");
		petc();
		system("more /E /C /P \".\\README.md\"");
		petc_a();
		clear_terminal();
	#elif defined(__linux__) // For Linux.
		puts("When you enter press \"q\" to quit, \"enter\" to go down to the next line, \"space\" to go down next page, and type \"/ + text\" to search for text!");
		petc();
		system("less \"./README.md\"");
	#endif
}

// Easter egg function:
static inline void easter_egg_function(void)
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
