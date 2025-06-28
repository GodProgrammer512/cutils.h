// Run once:
#ifndef CUTILS_H
#define CUTILS_H

// Importations:
#include <stdio.h>


// Variables:
#define BASE_TERMINAL "\033[m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"
#define MAGENTA_COLOR "\033[35m"
#define CYAN_COLOR "\033[36m"

// Math variables:
#ifdef M_PI
#define M_PI_L 3.1415926535897932385L
#define M_PI_L_100D 3.14159265358979323846264338327950288419716939937510L
#endif

// Clear terminal function:
extern void clear_terminal(void)
{
	fputs("\033[2J\033[H", stdout);
	fflush(stdout);
}

// Pause function:
extern void petc(void)
{
	int characters;
	while((characters = getchar()) != '\n' && characters != EOF);
	fputs("Press \"ENTER\" to continue...", stdout);
	getchar();
}

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

// End code:
#endif
