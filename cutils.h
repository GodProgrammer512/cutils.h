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
#include <stdlib.h>
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

/* C Utils version variables: */
#define CUTILS_FULL_VERSION  130L                  /* C Utils full version variable (1.3.0). */
#define CUTILS_MAJOR_VERSION 1L                    /* C Utils major version variable (1).    */
#define CUTILS_MINOR_VERSION 3L                    /* C Utils minor version variable (3).    */
#define CUTILS_PATCH_VERSION 0L                    /* C Utils patch version variable (0).    */

/* Terminal colors: */
#ifdef IMPORT_TERMINAL_COLORS
	#define BASE_TERMINAL      "\033[m"              /* Reset terminal text.          */
	#define BOLD               "\033[1m"             /* Bold terminal text.           */
	#define BASE_TERMINAL_BOLD "\033[m\033[1m"       /* Reset and bold terminal text. */
	#define ITALIC             "\033[3m"             /* Italic terminal text.         */
	#define UNDERLINE          "\033[4m"             /* Underline terminal text.      */
	#define BLACK_COLOR        "\033[30m"            /* Black terminal text.          */
	#define RED_COLOR          "\033[31m"            /* Red terminal text.            */
	#define GREEN_COLOR        "\033[32m"            /* Green terminal text.          */
	#define YELLOW_COLOR       "\033[33m"            /* Yellow terminal text.         */
	#define BLUE_COLOR         "\033[34m"            /* Blue terminal text.           */
	#define MAGENTA_COLOR      "\033[35m"            /* Magenta terminal text.        */
	#define CYAN_COLOR         "\033[36m"            /* Cyan terminal text.           */
	#define WHITE_COLOR        "\033[37m"            /* White terminal text.          */
#endif

/* Math utils: */
#ifdef IMPORT_MATH_UTILS
	/* Math variables: */
	#define PI_S_F             3.14f                 /* Approximate pi value (short type in float, 2 precision).       */
	#define PI_M_F             3.14159f              /* Medium pi value (medium type in float, 5 precision).           */
	#define PI_L_F             3.141592653589793239f /* Long pi value (long type in float, 18 precision).              */
	#define PI_S_D             3.14                  /* Approximate pi value (short type in double, 2 precision).      */
	#define PI_M_D             3.14159               /* Medium pi value (medium type in double, 5 precision).          */
	#define PI_L_D             3.141592653589793239  /* Long pi value (long type in double, 18 precision).             */
	#define PI_S_L             3.14L                 /* Approximate pi value (short type in long double, 2 precision). */
	#define PI_M_L             3.14159L              /* Medium pi value (medium type in long double, 5 precision).     */
	#define PI_L_L             3.141592653589793239L /* Long pi value (long type in long double, 18 precision).        */
	#define MIN_CELSIUS_F     -273.15f               /* Minimum Celsius temperature (in float).                        */
	#define MIN_CELSIUS_D     -273.15                /* Minimum Celsius temperature (in double).                       */
	#define MIN_CELSIUS_L     -273.15L               /* Minimum Celsius temperature (in long double).                  */
	#define MIN_FAHRENHEIT_F  -459.67f               /* Minimum Fahrenheit temperature (in float).                     */
	#define MIN_FAHRENHEIT_D  -459.67                /* Minimum Fahrenheit temperature (in double).                    */
	#define MIN_FAHRENHEIT_L  -459.67L               /* Minimum Fahrenheit temperature (in long double).               */
	#define MIN_KELVIN_F       0.0f                  /* Minimum Kelvin temperature (in float).                         */
	#define MIN_KELVIN_D       0.0                   /* Minimum Kelvin temperature (in double).                        */
	#define MIN_KELVIN_L       0.0L                  /* Minimum Kelvin temperature (in long double).                   */

	/* Functionss to calculate the circumference: */
  #define CIRCUMFER_F(pi_val_float)                               ((float)(2.0f) * (float)(pi_val_) * (float)(radius_val_))                   /* Float version.       */
  #define CIRCUMFER_D(pi_val_double)                              ((double)(2.0) * (double)(pi_val_) * (double)(radius_val_))                 /* Double version.      */
	#define CIRCUMFER_L(pi_val_long_double, radius_val_long_double) ((long double)(2.0L) * (long double)(pi_val_) * (long double)(radius_val_)) /* Long double version. */

	/* Functions to calculate the area of a circle: */
  float circle_area_f(float pi_val_float, float radius_val_float)                                 /* Float version.       */
  {
    return pi_val_float * (radius_val_float * radius_val_float);
  }

  double circle_area_d(double pi_val_double, double radius_val_double)                            /* Double version.      */
  {
    return pi_val_double * (radius_val_double * radius_val_double);
  }

	long double circle_area_l(long double pi_val_long_double, long double radius_val_long_double)   /* Long double version. */
  {
    return pi_val_long_double * (radius_val_long_double * radius_val_long_double);
  }

	/* Functions to calculate the volume of a sphere: */
  float sphere_volume_f(float pi_val_float, float radius_val_float)                               /* Float version.       */
  {
    return (4.0f / 3.0f) * pi_val_float * (radius_val_float * radius_val_float * radius_val_float);
  }

  double sphere_volume_d(double pi_val_double, double radius_val_double)                          /* Double version.      */
  {
    return (4.0 / 3.0) * pi_val_double * (radius_val_double * radius_val_double * radius_val_double);
  }

	long double sphere_volume_l(long double pi_val_long_double, long double radius_val_long_double) /* Long double version. */
	{
		return (4.0L / 3.0L) * pi_val_long_double * (radius_val_long_double * radius_val_long_double * radius_val_long_double);
	}

	/* Temperature convertion functions: */
	#define KELVIN_TO_CELSIUS_F(kelvin_val_float)               ((float)(kelvin_val_float) - (float)(273.15f))                                                      /* Kelvin to Celsius (in float).           */
	#define KELVIN_TO_CELSIUS_D(kelvin_val_double)              ((double)(kelvin_val_double) - (double)(273.15))                                                    /* Kelvin to Celsius (in double).          */
	#define KELVIN_TO_CELSIUS_L(kelvin_val_long_double)         ((long double)(kelvin_val_long_double) - (long double)(273.15L))                                    /* Kelvin to Celsius (in long double).     */
	#define KELVIN_TO_FAHRENHEIT_F(kelvin_val_float)            ((float)(kelvin_val_float) * (float)(9.0f / 5.0f) - (float)(459.67f))                               /* Kelvin to Fahrenheit (in float).        */
	#define KELVIN_TO_FAHRENHEIT_D(kelvin_val_double)           ((double)(kelvin_val_double) * (double)(9.0 / 5.0) - (double)(459.67))                              /* Kelvin to Fahrenheit (in double).       */
	#define KELVIN_TO_FAHRENHEIT_L(kelvin_val_long_double)      ((long double)(kelvin_val_long_double) * (long double)(9.0L / 5.0L) - (long double)(459.67L))       /* Kelvin to Fahrenheit (in long double).  */
	#define CELSIUS_TO_KELVIN_F(celsius_val_float)              ((float)(celsius_val_float) + (float)(273.15f))                                                     /* Celsius to Kelvin (in float).           */
	#define CELSIUS_TO_KELVIN_D(celsius_val_double)             ((double)(celsius_val_double) + (double)(273.15))                                                   /* Celsius to Kelvin (in double).          */
	#define CELSIUS_TO_KELVIN_L(celsius_val_long_double)        ((long double)(celsius_val_long_double) + (long double)(273.15L))                                   /* Celsius to Kelvin (in long double).     */
	#define CELSIUS_TO_FAHRENHEIT_F(celsius_val_float)          ((float)(celsius_val_float) * (float)(9.0f / 5.0f) + (float)(32.0f))                                /* Celsius to Fahrenheit (in float).       */
	#define CELSIUS_TO_FAHRENHEIT_D(celsius_val_double)         ((double)(celsius_val_double) * (double)(9.0 / 5.0) + (double)(32.0))                               /* Celsius to Fahrenheit (in double).      */
	#define CELSIUS_TO_FAHRENHEIT_L(celsius_val_long_double)    ((long double)(celsius_val_long_double) * (long double)(9.0L / 5.0L) + (long double)(32.0L))        /* Celsius to Fahrenheit (in long double). */
	#define FAHRENHEIT_TO_KELVIN_F(fahrenheit_val_float)        (((float)(fahrenheit_val_float) + (float)(459.67f)) * (float)(5.0f / 9.0f))                         /* Fahrenheit to Kelvin (in float).        */
	#define FAHRENHEIT_TO_KELVIN_D(fahrenheit_val_double)       (((double)(fahrenheit_val_double) + (double)(459.67)) * (double)(5.0 / 9.0))                        /* Fahrenheit to Kelvin (in double).       */
	#define FAHRENHEIT_TO_KELVIN_L(fahrenheit_val_long_double)  (((long double)(fahrenheit_val_long_double) + (long double)(459.67L)) * (long double)(5.0L / 9.0L)) /* Fahrenheit to Kelvin (in long double).  */
	#define FAHRENHEIT_TO_CELSIUS_F(fahrenheit_val_float)       (((float)(fahrenheit_val_float) - (float)(32.0f)) * (float)(5.0f / 9.0f))                           /* Fahrenheit to Celsius (in float).       */
	#define FAHRENHEIT_TO_CELSIUS_D(fahrenheit_val_double)      (((double)(fahrenheit_val_double) - (double)(32.0)) * (double)(5.0 / 9.0))                          /* Fahrenheit to Celsius (in double).      */
	#define FAHRENHEIT_TO_CELSIUS_L(fahrenheit_val_long_double) (((long double)(fahrenheit_val_long_double) - (long double)(32.0L)) * (long double)(5.0L / 9.0L))   /* Fahrenheit to Celsius (in long double). */
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
#define CLEAR_TERMINAL() (fputs("\033[2J\033[3J\033[H", stdout))

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
		CLEAR_TERMINAL();
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
		char command[BUFSIZ]; /* Command variable. */
		snprintf(command, sizeof(command), "start %s", url);
		system(command);
	#elif defined(__linux__) || defined(__ANDROID__) /* For Linux and Android. */
		char command[BUFSIZ]; /* Command variable. */
		snprintf(command, sizeof(command), "xdg-open %s", url);
		system(command);
	#elif defined(__APPLE__) /* For macOS. */
		char command[BUFSIZ]; /* Command variable. */
		snprintf(command, sizeof(command), "open %s", url);
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
