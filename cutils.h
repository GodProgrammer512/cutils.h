/* Include guard: */
#ifndef _CUTILS_H_
#define _CUTILS_H_

/* Importations: */
#if defined(_MSVC_LANG)
	#if _MSVC_LANG < 201103L
		#define __USE_MINGW_ANSI_STDIO 1
	#endif
#elif defined(__cplusplus)
	#if __cplusplus < 201103L
		#define __USE_MINGW_ANSI_STDIO 1
	#endif
#endif
#include <stdio.h>
#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__DJGPP__) /* For Linux, Android, macOS and MS-DOS. */
	#include <unistd.h>
#endif


#ifdef __cplusplus
extern "C"
{
#endif

/* C Utils version: */
#define CUTILS_VERSION "1.2.1" /* C Utils version variable. */

/* Terminal colors: */
#ifdef IMPORT_TERMINAL_COLORS
	#define BASE_TERMINAL      "\033[m"        /* Reset terminal text. */
	#define BOLD               "\033[1m"       /* Bold terminal text. */
	#define BASE_TERMINAL_BOLD "\033[m\033[1m" /* Reset and bold terminal text. */
	#define ITALIC             "\033[3m"       /* Italic terminal text. */
	#define UNDERLINE          "\033[4m"       /* Underline terminal text. */
	#define BLACK_COLOR        "\033[30m"      /* Black terminal text. */
	#define RED_COLOR          "\033[31m"      /* Red terminal text. */
	#define GREEN_COLOR        "\033[32m"      /* Green terminal text. */
	#define YELLOW_COLOR       "\033[33m"      /* Yellow terminal text. */
	#define BLUE_COLOR         "\033[34m"      /* Blue terminal text. */
	#define MAGENTA_COLOR      "\033[35m"      /* Magenta terminal text. */
	#define CYAN_COLOR         "\033[36m"      /* Cyan terminal text. */
	#define WHITE_COLOR        "\033[37m"      /* White terminal text. */
#endif

/* Math utils: */
#ifdef IMPORT_MATH_UTILS
	/* Math variables: */
	#define PI_S_L 3.14L                 /* Approximate pi value (short type in long double, 2 precision). */
	#define PI_M_L 3.14159L		 		 		   /* Medium pi value (medium type in long double, 5 precision). */
	#define PI_L_L 3.141592653589793239L /* Long pi value (long type in long double, 18 precision). */

	/* Function to calculate the circumference: */
	#define CIRCUMFER(pi_val_, radius_val_) ((long double)(2.0L) * (long double)(pi_val_) * (long double)(radius_val_))

	/* Function to calculate the area of a circle: */
	long double circle_area(long double pi_val_, long double radius_val_)
	{
		return pi_val_ * (radius_val_ * radius_val_);
	}

	/* Function to calculate the volume of a sphere: */
	long double sphere_volume(long double pi_val_, long double radius_val_)
	{
		return (4.0L / 3.0L) * pi_val_ * (radius_val_ * radius_val_ * radius_val_);
	}
#endif

/* Encoding utils: */
static inline void enable_vt_and_utf8(void)
{
	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		if(hOut == INVALID_HANDLE_VALUE)
		{
			return;
		}

		DWORD mode = 0u;

		if(!GetConsoleMode(hOut, &mode))
		{
			return;
		}

		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

		if(!SetConsoleMode(hOut, mode))
		{
			DWORD err = GetLastError();
			(void)err;
			return;
		}
	
		if(!SetConsoleOutputCP(CP_UTF8))
		{
			DWORD err = GetLastError();
			(void)err;
		}
	#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__DJGPP__) /* For Linux, Android, macOS and MS-DOS. */
		return;
	#endif
}

/* Clear terminal function: */
static inline void clear_terminal(void)
{
	fputs("\033[3J\033[2J\033[H", stdout);
	fflush(stdout);
}

/* Pause function: */
static inline void petc(void)
{
	signed int characters; /* Variable to store characters. */
	while((characters = getchar()) != EOF && characters != '\n');
	fputs("Press \"ENTER\" to continue...", stdout);
	getchar();
}

/* Alternative pause function (without pausing, just saying to press "ENTER"): */
static inline void petc_a(void)
{
	fputs("Press \"ENTER\" to continue...", stdout);
	getchar();
}

/* Unsigned char verify OS function: */
static inline unsigned char verify_os_u(void)
{
	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		return 1u;
	#elif defined(__linux__) || defined(__ANDROID__) /* For Linux and Android. */
		return 2u;
	#elif defined(__APPLE__) /* For macOS. */
		return 3u;
	#elif defined(__DJGPP__) /* For MS-DOS. */
		return 4u;
	#else /* For another OS. */
		return 0u;
	#endif
}

/* Signed char verify OS function: */
static inline signed char verify_os_s(void)
{
	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		return 1;
	#elif defined(__linux__) || defined(__ANDROID__) /* For Linux and Android. */
		return 2;
	#elif defined(__APPLE__) /* For macOS. */
		return 3;
	#elif defined(__DJGPP__) /* For MS-DOS. */
		return 4;
	#else /* For another OS. */
		return 0;
	#endif
}

/* Seconds sleep function: */
static inline void ssleep(unsigned int time)
{
	if(time == 0u)
	{
		return;
	}

	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		Sleep((DWORD)time * (DWORD)1000u);
	#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__DJGPP__) /* For Linux, Android, macOS and MS-DOS. */
		sleep(time);
	#endif
}

/* Milliseconds sleep function: */
static inline void mssleep(unsigned int time)
{
	if(time == 0UL)
	{
		return;
	}

	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		Sleep((DWORD)time);
	#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__DJGPP__) /* For Linux, Android, macOS and MS-DOS. */
		usleep((useconds_t)time * (useconds_t)1000u);
	#endif
}

/* Read "READ-ME" function: */
static inline void read_me(void)
{
	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		puts("When you enter just press \"space\" to advance 1 page, \"enter\" to go down 1 line and \"Ctrl-C\" to quit \"READ-ME\"!");
		petc();
		system("more /E /C /P \".\\README.md\"");
		petc_a();
		clear_terminal();
	#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) /* For Linux, Android and macOS. */
		puts("When you enter press \"q\" to quit, \"enter\" to go down to the next line, \"space\" to go down next page, and type \"/ + text\" to search for text!");
		petc();
		system("less \"./README.md\"");
	#elif defined(__DJGPP__) /* For MS-DOS. */
		system("type \".\\README.MD\"");
	#endif
}

/* Open URL function: */
static inline void url_openner(const char *url)
{
	if(url == NULL)
	{
		return;
	}

	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
		char command[256]; /* Command variable. */
		snprintf(command, sizeof(command), "start \"%s\"", url);
		system(command);
	#elif defined(__linux__) || defined(__ANDROID__) /* For Linux and Android. */
		char command[256]; /* Command variable. */
		snprintf(command, sizeof(command), "xdg-open \"%s\"", url);
		system(command);
	#elif defined(__APPLE__) /* For macOS. */
		char command[256]; /* Command variable. */
		snprintf(command, sizeof(command), "open \"%s\"", url);
		system(command);
	#elif defined(__DJGPP__) /* For MS-DOS. */
		return;
	#endif
}

/* Easter egg function: */
static inline void easter_egg_function(void)
{
	/* Basic commands: */
	puts("Congratulations!!! You just discovered a new easter egg! (please don't say it to anywhone ok!)");
	puts("This is the link to our github account! If you want to see our projects, codes, etc...");
	puts("Link: \"https://github.com/GodProgrammer512/\"");

	/* Command to open the link on browser: */
	#if defined(_WIN32) || defined(_WIN64) /* For Windows. */
	  system("start \"https://github.com/GodProgrammer512/\"");
	#elif defined(__linux__) || defined(__ANDROID__) /* For Linux and Android. */
	  system("xdg-open \"https://github.com/GodProgrammer512/\"");
	#elif defined(__APPLE__) /* For macOS. */
	  system("open \"https://github.com/GodProgrammer512/\"");
	#endif

	/* Pause APP: */
	petc();
}

#ifdef __cplusplus
}
#endif

/* End code: */
#endif
