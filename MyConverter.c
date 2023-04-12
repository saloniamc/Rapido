/*
    AUTHOR:- SALONI@CPA
    DATE :- 29 DEC 2022
    TIME:- 3.45 PM
    GOAL:- MYCOVERTER

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NR_MAX_TRIES 3

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

#define LENGTH 1
#define WEIGHT 2
#define ENERGY 3
#define TEMPERATURE 4
#define FREQUENCY 5
#define EXIT 6

#define MILLIMETER 1
#define CENTIMETER 2
#define METER 3
#define KILOMETER 4
#define INCH 5
#define FOOT 6
#define YARD 7
#define MILE 8

#define MAIN_MENU 9
#define EXIT_APP 10

#define MICROGRAMS 1
#define MILLIGRAMS 2
#define GRAMS 3
#define OUNCES 4
#define POUNDS 5
#define KILOGRAMS 6
#define STONES 7
#define METRIC_TONS 8

#define WATT_HOUR 1
#define KILOWATT_HOUR 2
#define MEGAWATT_HOUR 3
#define BTU 4
#define JOULES 5
#define KILOJOULES 6
#define MEGAJOULES 7
#define GIGAJOULES 8

#define FAHRENHEIT 1
#define RANKINE 2
#define CELSIUS 3
#define KELVIN 4
#define TEMP_MAIN_MENU 5
#define TEMP_EXIT 6

#define HERTZ 1
#define KILOHERTZ 2
#define MEGAHERTZ 3
#define GIGAHERTZ 4
#define TERAHERTZ 5
#define FREQ_MAIN_MENU 6
#define FREQ_EXIT 7

void length_converter(void);
void weight_converter(void);
void energy_converter(void);
void temperature_converter(void);
void frequency_converter(void);
void main_menu(void);

/* FOR LENGTH  */
double millimeter_to_centimeter(double);
double millimeter_to_meter(double);
double millimeter_to_kilometer(double);
double millimeter_to_inch(double);
double millimeter_to_foot(double);
double millimeter_to_yard(double);
double millimeter_to_mile(double);

double centimeter_to_millimeter(double);
double meter_to_millimeter(double);
double kilometer_to_millimeter(double);
double inch_to_millimeter(double);
double foot_to_millimeter(double);
double yard_to_millimeter(double);
double mile_to_millimeter(double);

/* FOR WEIGHT */
double gram_to_microgram(double);
double gram_to_milligram(double);
double gram_to_ounce(double);
double gram_to_pound(double);
double gram_to_kilogram(double);
double gram_to_stone(double);
double gram_to_metricTon(double);

double microgram_to_gram(double);
double milligram_to_gram(double);
double ounce_to_gram(double);
double pound_to_gram(double);
double kilogram_to_gram(double);
double stone_to_gram(double);
double metricTon_to_gram(double);

/* FOR ENERGY */
double joules_to_wattHour(double);
double joules_to_kiloWattHour(double);
double joules_to_megaWattHour(double);
double joules_to_btu(double);
double joules_to_kiloJoules(double);
double joules_to_megaJoules(double);
double joules_to_gigaJoules(double);

double wattHour_to_joules(double);
double kiloWattHour_to_joules(double);
double megaWattHour_to_joules(double);
double btu_to_joules(double);
double kiloJoules_to_joules(double);
double megaJoules_to_joules(double);
double gigaJoules_to_joules(double);

/* FOR TEMPERATURE */
double celsius_to_fahrenheit(double);
double celsius_to_rankine(double);
double celsius_to_kelvin(double);

double fahrenheit_to_celsius(double);
double rankine_to_celsius(double);
double kelvin_to_celsius(double);

/* FOR FREQUENCY */
double hertz_to_kilohertz(double);
double hertz_to_megahertz(double);
double hertz_to_gigahertz(double);
double hertz_to_teragertz(double);

double kilohertz_to_hertz(double);
double megahertz_to_hertz(double);
double gigahertz_to_hertz(double);
double terahertz_to_hertz(double);

int get_conversion_type(const char *prompt, int valid_choice_start, int valid_choice_end);
void enter_into_conversion(int conversion_type);

void do_length_conversion(int from_choice, int to_choice, double input_number);
void do_weight_conversion(int from_choice, int to_choice, double input_number);
void do_energy_conversion(int from_choice, int to_choice, double input_number);
void do_temperature_conversion(int from_choice, int to_choice, double input_number);
void do_frequency_conversion(int from_choice, int to_choice, double input_number);

void exit_application(void);

/* Main function */
int main(void)
{
    printf("\nWelcome to My-Converter!\n");
    main_menu();

    return 0;
}

void main_menu(void)
{
    int conversion_type;
    while (TRUE)
    {
        puts("----------------------------------------\n");
        printf("1:Length\n2:Weight\n3:Energy\n4:Temperature\n");
        printf("5:Frequency\n6:Exit\n");
        conversion_type = get_conversion_type("Enter your choice:", 1, 6);

        if (conversion_type == EXIT)
        {
            exit_application();
        }

        enter_into_conversion(conversion_type);
    }
}

int get_conversion_type(const char *prompt, int valid_choice_start, int valid_choice_end)
{
    int number_of_tries;
    int conv_choice;
    int flag = FALSE;

    for (number_of_tries = 0; number_of_tries < NR_MAX_TRIES; ++number_of_tries)
    {
        printf(prompt);
        scanf_s("%d", &conv_choice);

        if (conv_choice >= valid_choice_start && conv_choice <= valid_choice_end)
        {
            flag = TRUE;
            break;
        }
        puts("Please enter a valid choice\n");
    }

    if (flag == FALSE)
    {
        exit_application();
    }
    return (conv_choice);
}

void enter_into_conversion(int conversion_type)
{
    if (conversion_type == LENGTH)
    {
        length_converter();
    }
    else if (conversion_type == WEIGHT)
    {
        weight_converter();
    }
    else if (conversion_type == ENERGY)
    {
        energy_converter();
    }
    else if (conversion_type == TEMPERATURE)
    {
        temperature_converter();
    }
    else if (conversion_type == FREQUENCY)
    {
        frequency_converter();
    }
}

/* DIVING INTO LENGTH CONVERTER */
void length_converter(void)
{
    int from_choice;
    int to_choice;
    double input_number = 0.0;

    while (TRUE)
    {
        puts("----------------------------------------");
        printf("1:Millimeter(mm)\n2:Centimeter(cm)\n3:Meter(m)\n4:kilometer(km)\n");
        printf("5:Inch(in)\n6:Foot(ft)\n7:Yard(yd)\n8:Mile(mi)\n9:Go back to main menu\n10:Exit\n");
        printf("\n");
        from_choice = get_choice("Convert From:", 1, 10);
        if (from_choice == MAIN_MENU)
        {
            main_menu();
        }
        if (from_choice == EXIT_APP)
        {
            exit_application();
        }
        printf("Enter Magnitude:");
        scanf_s("%lf", &input_number);

        to_choice = get_choice("Convert To:", 1, 10);
        if (to_choice == MAIN_MENU)
        {
            main_menu();
        }
        if (to_choice == EXIT_APP)
        {
            exit_application();
        }
        do_length_conversion(from_choice, to_choice, input_number);
    }

    _getch();
    exit(EXIT_SUCCESS);
}

/* DIVING INTO WEIGHT CONVERTER */
void weight_converter(void)
{
    int from_choice;
    int to_choice;
    double input_number = 0.0;

    while (TRUE)
    {
        puts("----------------------------------------");
        printf("1:Microgram(mcg)\n2:Milligram(mg)\n3:Gram(g)\n4:Ounce(oz)\n");
        printf("5:Pound(lb)\n6:Kilogram(kg)\n7:Stones(st)\n8:Metric ton(t)\n9:Go back to main menu\n10:Exit\n");
        printf("\n");
        from_choice = get_choice("Convert From:", 1, 10);
        if (from_choice == MAIN_MENU)
        {
            main_menu();
        }

        if (from_choice == EXIT_APP)
        {
            exit_application();
        }

        printf("Enter Magnitude:");
        scanf_s("%lf", &input_number);

        to_choice = get_choice("Convert To:", 1, 10);
        if (to_choice == MAIN_MENU)
        {
            main_menu();
        }
        if (to_choice == EXIT_APP)
        {
            exit_application();
        }
        do_weight_conversion(from_choice, to_choice, input_number);
    }

    _getch();
    exit(EXIT_SUCCESS);
}

/* DIVING INTO ENERGY CONVERTER */
void energy_converter(void)
{
    int from_choice;
    int to_choice;
    double input_number = 0.0;

    while (TRUE)
    {
        puts("----------------------------------------");
        printf("1:Watt-hour(Wh)\n2:kiloWatt-hour(kWh)\n3:MegaWatt-hour(MWh)\n4:British Thermal Unit(BTU)\n");
        printf("5:Joules(J)\n6:Kilojoules(kJ)\n7:Megajoules(MJ)\n8:Gigajoules(GJ)\n9:Go back to main menu\n10:Exit\n");
        printf("\n");
        from_choice = get_choice("Convert From:", 1, 10);
        if (from_choice == MAIN_MENU)
        {
            main_menu();
        }

        if (from_choice == EXIT_APP)
        {
            exit_application();
        }

        printf("Enter Magnitude:");
        scanf_s("%lf", &input_number);

        to_choice = get_choice("Convert To:", 1, 10);
        if (to_choice == MAIN_MENU)
        {
            main_menu();
        }
        if (to_choice == EXIT_APP)
        {
            exit_application();
        }
        do_energy_conversion(from_choice, to_choice, input_number);
    }

    _getch();
    exit(EXIT_SUCCESS);
}

/* DIVING INTO TEMPERATURE CONVERTER */
void temperature_converter(void)
{
    int from_choice;
    int to_choice;
    double input_number = 0.0;

    while (TRUE)
    {
        puts("----------------------------------------");
        printf("1:Fahrenheit(%cF)\n2:Rankine(%cR)\n3:Celsius(%cC)\n4:kelvin(K)\n5:Go back to main menu\n6:Exit\n", 248, 248, 248);
        printf("\n");
        from_choice = get_choice("Convert From:", 1, 6);
        if (from_choice == TEMP_MAIN_MENU)
        {
            main_menu();
        }
        if (from_choice == TEMP_EXIT)
        {
            exit_application();
        }

        printf("Enter Magnitude:");
        scanf_s("%lf", &input_number);

        to_choice = get_choice("Convert To:", 1, 6);
        if (to_choice == TEMP_MAIN_MENU)
        {
            main_menu();
        }
        if (to_choice == TEMP_EXIT)
        {
            exit_application();
        }
        do_temperature_conversion(from_choice, to_choice, input_number);
    }

    _getch();
    exit(EXIT_SUCCESS);
}

/* DIVING INTO FREQUENCY CONVERTER */
void frequency_converter(void)
{
    int from_choice;
    int to_choice;
    double input_number = 0.0;

    while (TRUE)
    {
        puts("----------------------------------------");
        printf("1:Hertz(Hz)\n2:Kilohertz(kHz)\n3:Megahertz(MHz)\n4:Gigahertz(GHz)\n5:Terahertz(THz)\n6:Go back to main menu\n7:Exit\n");
        printf("\n");
        from_choice = get_choice("Convert From:", 1, 7);
        if (from_choice == FREQ_MAIN_MENU)
        {
            main_menu();
        }
        if (from_choice == FREQ_EXIT)
        {
            exit_application();
        }

        printf("Enter Magnitude:");
        scanf_s("%lf", &input_number);

        to_choice = get_choice("Convert To:", 1, 7);
        if (to_choice == FREQ_MAIN_MENU)
        {
            main_menu();
        }
        if (to_choice == FREQ_EXIT)
        {
            exit_application();
        }
        do_frequency_conversion(from_choice, to_choice, input_number);
    }

    _getch();
    exit(EXIT_SUCCESS);
}

/* Frequency Converter*/
void do_frequency_conversion(int from_temp_choice, int to_temp_choice, double input_number)
{
    char *input_unit = NULL;
    char *output_unit = NULL;
    double output_number = 0.0;

    if (from_temp_choice == HERTZ && to_temp_choice == HERTZ)
    {
        output_number = input_number;
        input_unit = "Hz";
        output_unit = "Hz";
    }

    else if (from_temp_choice == HERTZ && to_temp_choice == KILOHERTZ)
    {
        output_number = hertz_to_kilohertz(input_number);
        input_unit = "Hz";
        output_unit = "kHz";
    }
    else if (from_temp_choice == HERTZ && to_temp_choice == MEGAHERTZ)
    {
        output_number = hertz_to_megahertz(input_number);
        input_unit = "Hz";
        output_unit = "MHz";
    }
    else if (from_temp_choice == HERTZ && to_temp_choice == GIGAHERTZ)
    {
        output_number = hertz_to_gigahertz(input_number);
        input_unit = "Hz";
        output_unit = "GHz";
    }
    else if (from_temp_choice == HERTZ && to_temp_choice == TERAHERTZ)
    {
        output_number = hertz_to_teragertz(input_number);
        input_unit = "Hz";
        output_unit = "THz";
    }
    else if (from_temp_choice == KILOHERTZ && to_temp_choice == HERTZ)
    {
        output_number = kilohertz_to_hertz(input_number);
        input_unit = "kHz";
        output_unit = "Hz";
    }
    else if (from_temp_choice == KILOHERTZ && to_temp_choice == KILOHERTZ)
    {
        output_number = input_number;
        input_unit = "kHz";
        output_unit = "KHz";
    }
    else if (from_temp_choice == KILOHERTZ && to_temp_choice == MEGAHERTZ)
    {
        output_number = hertz_to_megahertz(kilohertz_to_hertz(input_number));
        input_unit = "kHz";
        output_unit = "MHz";
    }
    else if (from_temp_choice == KILOHERTZ && to_temp_choice == GIGAHERTZ)
    {
        output_number = hertz_to_gigahertz(kilohertz_to_hertz(input_number));
        input_unit = "kHz";
        output_unit = "GHz";
    }
    else if (from_temp_choice == KILOHERTZ && to_temp_choice == TERAHERTZ)
    {
        output_number = hertz_to_teragertz(kilohertz_to_hertz(input_number));
        input_unit = "kHz";
        output_unit = "THz";
    }
    else if (from_temp_choice == MEGAHERTZ && to_temp_choice == HERTZ)
    {
        output_number = megahertz_to_hertz(input_number);
        input_unit = "MHz";
        output_unit = "Hz";
    }
    else if (from_temp_choice == MEGAHERTZ && to_temp_choice == KILOHERTZ)
    {
        output_number = hertz_to_kilohertz(megahertz_to_hertz(input_number));
        input_unit = "MHz";
        output_unit = "kHz";
    }
    else if (from_temp_choice == MEGAHERTZ && to_temp_choice == MEGAHERTZ)
    {
        output_number = input_number;
        input_unit = "MHz";
        output_unit = "MHz";
    }
    else if (from_temp_choice == MEGAHERTZ && to_temp_choice == GIGAHERTZ)
    {
        output_number = hertz_to_gigahertz(megahertz_to_hertz(input_number));
        input_unit = "MHz";
        output_unit = "GHz";
    }
    else if (from_temp_choice == MEGAHERTZ && to_temp_choice == TERAHERTZ)
    {
        output_number = hertz_to_teragertz(megahertz_to_hertz(input_number));
        input_unit = "MHz";
        output_unit = "THz";
    }
    else if (from_temp_choice == GIGAHERTZ && to_temp_choice == HERTZ)
    {
        output_number = gigahertz_to_hertz(input_number);
        input_unit = "GHz";
        output_unit = "Hz";
    }
    else if (from_temp_choice == GIGAHERTZ && to_temp_choice == KILOHERTZ)
    {
        output_number = hertz_to_kilohertz(gigahertz_to_hertz(input_number));
        input_unit = "GHz";
        output_unit = "kHz";
    }
    else if (from_temp_choice == GIGAHERTZ && to_temp_choice == MEGAHERTZ)
    {
        output_number = hertz_to_megahertz(gigahertz_to_hertz(input_number));
        input_unit = "GHz";
        output_unit = "MHz";
    }
    else if (from_temp_choice == GIGAHERTZ && to_temp_choice == GIGAHERTZ)
    {
        output_number = input_number;
        input_unit = "GHz";
        output_unit = "GHz";
    }
    else if (from_temp_choice == GIGAHERTZ && to_temp_choice == TERAHERTZ)
    {
        output_number = hertz_to_teragertz(gigahertz_to_hertz(input_number));
        input_unit = "GHz";
        output_unit = "THZ";
    }
    else if (from_temp_choice == TERAHERTZ && to_temp_choice == HERTZ)
    {
        output_number = terahertz_to_hertz(input_number);
        input_unit = "THz";
        output_unit = "Hz";
    }
    else if (from_temp_choice == TERAHERTZ && to_temp_choice == KILOHERTZ)
    {
        output_number = hertz_to_kilohertz(terahertz_to_hertz(input_number));
        input_unit = "THz";
        output_unit = "kHz";
    }
    else if (from_temp_choice == TERAHERTZ && to_temp_choice == MEGAHERTZ)
    {
        output_number = hertz_to_megahertz(terahertz_to_hertz(input_number));
        input_unit = "THz";
        output_unit = "MHz";
    }
    else if (from_temp_choice == TERAHERTZ && to_temp_choice == GIGAHERTZ)
    {
        output_number = hertz_to_gigahertz(terahertz_to_hertz(input_number));
        input_unit = "THz";
        output_unit = "GHz";
    }
    else if (from_temp_choice == TERAHERTZ && to_temp_choice == TERAHERTZ)
    {
        output_number = input_number;
        input_unit = "THz";
        output_unit = "THz";
    }

    printf("%lf(%s) = %lf(%s)", input_number, input_unit, output_number, output_unit);
}

double hertz_to_kilohertz(double ff)
{
    return (ff / 1000);
}
double hertz_to_megahertz(double ff)
{
    return (ff / 1e+6);
}
double hertz_to_gigahertz(double ff)
{
    return (ff / 1e+9);
}
double hertz_to_teragertz(double ff)
{
    return (ff / 1e+12);
}

double kilohertz_to_hertz(double ff)
{
    return (ff * 1000);
}
double megahertz_to_hertz(double ff)
{
    return (ff * 1e+6);
}
double gigahertz_to_hertz(double ff)
{
    return (ff * 1e+9);
}
double terahertz_to_hertz(double ff)
{
    return (ff * 1e+12);
}

/* Temperature Conversion */
void do_temperature_conversion(int from_temp_choice, int to_temp_choice, double input_number)
{
    char *input_unit = NULL;
    char *output_unit = NULL;
    double output_number = 0.0;

    if (from_temp_choice == FAHRENHEIT && to_temp_choice == FAHRENHEIT)
    {
        output_number = input_number;
        input_unit = "F";
        output_unit = "F";
    }
    else if (from_temp_choice == FAHRENHEIT && to_temp_choice == RANKINE)
    {
        output_number = celsius_to_rankine(fahrenheit_to_celsius(input_number));
        input_unit = "F";
        output_unit = "R";
    }
    else if (from_temp_choice == FAHRENHEIT && to_temp_choice == CELSIUS)
    {
        output_number = fahrenheit_to_celsius(input_number);
        input_unit = "F";
        output_unit = "C";
    }
    else if (from_temp_choice == FAHRENHEIT && to_temp_choice == KELVIN)
    {
        output_number = celsius_to_kelvin(fahrenheit_to_celsius(input_number));
        input_unit = "F";
        output_unit = "K";
    }
    else if (from_temp_choice == RANKINE && to_temp_choice == FAHRENHEIT)
    {
        output_number = celsius_to_fahrenheit(rankine_to_celsius(input_number));
        input_unit = "R";
        output_unit = "F";
    }
    else if (from_temp_choice == RANKINE && to_temp_choice == RANKINE)
    {
        output_number = input_number;
        input_unit = "R";
        output_unit = "R";
    }
    else if (from_temp_choice == RANKINE && to_temp_choice == CELSIUS)
    {
        output_number = rankine_to_celsius(input_number);
        input_unit = "R";
        output_unit = "C";
    }
    else if (from_temp_choice == RANKINE && to_temp_choice == KELVIN)
    {
        output_number = celsius_to_kelvin(rankine_to_celsius(input_number));
        input_unit = "R";
        output_unit = "K";
    }
    else if (from_temp_choice == CELSIUS && to_temp_choice == FAHRENHEIT)
    {
        output_number = celsius_to_fahrenheit(input_number);
        input_unit = "C";
        output_unit = "F";
    }
    else if (from_temp_choice == CELSIUS && to_temp_choice == RANKINE)
    {
        output_number = celsius_to_rankine(input_number);
        input_unit = "C";
        output_unit = "R";
    }
    else if (from_temp_choice == CELSIUS && to_temp_choice == CELSIUS)
    {
        output_number = input_number;
        input_unit = "C";
        output_unit = "C";
    }
    else if (from_temp_choice == CELSIUS && to_temp_choice == KELVIN)
    {
        output_number = celsius_to_kelvin(input_number);
        input_unit = "C";
        output_unit = "K";
    }
    else if (from_temp_choice == KELVIN && to_temp_choice == FAHRENHEIT)
    {
        output_number = celsius_to_fahrenheit(kelvin_to_celsius(input_number));
        input_unit = "K";
        output_unit = "F";
    }
    else if (from_temp_choice == KELVIN && to_temp_choice == RANKINE)
    {
        output_number = celsius_to_rankine(kelvin_to_celsius(input_number));
        input_unit = "K";
        output_unit = "R";
    }
    else if (from_temp_choice == KELVIN && to_temp_choice == CELSIUS)
    {
        output_number = kelvin_to_celsius(input_number);
        input_unit = "K";
        output_unit = "C";
    }
    else if (from_temp_choice == KELVIN && to_temp_choice == KELVIN)
    {
        output_number = input_number;
        input_unit = "K";
        output_unit = "K";
    }

    if (from_temp_choice == KELVIN && to_temp_choice == KELVIN)
        printf("%lf(%s) = %lf(%s)\n", input_number, input_unit, output_number, output_unit);
    else if (from_temp_choice == KELVIN)
        printf("%lf(%s) = %lf(%c%s)\n", input_number, input_unit, output_number, 248, output_unit);
    else if (to_temp_choice == KELVIN)
        printf("%lf(%c%s) = %lf(%s)\n", input_number, 248, input_unit, output_number, output_unit);
    else
        printf("%lf(%c%s) = %lf(%c%s)\n", input_number, 248, input_unit, output_number, 248, output_unit);
}

/* Temperature functions*/
double celsius_to_fahrenheit(double tt)
{
    return ((tt * 9 / 5) + 32);
}
double celsius_to_rankine(double tt)
{
    return ((tt * 9 / 5) + 491.67);
}
double celsius_to_kelvin(double tt)
{
    return (tt + 273.15);
}

double fahrenheit_to_celsius(double tt)
{
    return ((tt - 32) * 5 / 9);
}
double rankine_to_celsius(double tt)
{
    return ((tt - 491.67) * 5 / 9);
}
double kelvin_to_celsius(double tt)
{
    return (tt - 273.15);
}

/* Energy Conversion */
void do_energy_conversion(int from_energy_choice, int to_energy_choice, double input_number)
{
    char *input_unit = NULL;
    char *output_unit = NULL;
    double output_number = 0.0;

    if (from_energy_choice == WATT_HOUR && to_energy_choice == WATT_HOUR)
    {
        output_number = input_number;
        input_unit = "Wh";
        output_unit = "Wh";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "kWh";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "MWh";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "BTU";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == JOULES)
    {
        output_number = joules_to_kiloWattHour(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "J";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "kJ";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "MJ";
    }
    else if (from_energy_choice == WATT_HOUR && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_gigaJoules(wattHour_to_joules(input_number));
        input_unit = "Wh";
        output_unit = "GJ";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(kiloWattHour_to_joules(input_number));
        input_unit = "kWh";
        output_unit = "Wh";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = input_number;
        input_unit = "kWh";
        output_unit = "kWh";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(kiloWattHour_to_joules(input_number));
        input_unit = "kWh";
        output_unit = "MWh";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(kiloWattHour_to_joules(input_number));
        input_unit = "kWh";
        output_unit = "BTU";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == JOULES)
    {
        output_number = kiloWattHour_to_joules(input_number);
        input_unit = "kWh";
        output_unit = "J";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(kiloWattHour_to_joules(input_number));
        input_unit = "kWh";
        output_unit = "kJ";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(kiloWattHour_to_joules(input_number));
        input_unit = "kWh";
        output_unit = "MJ";
    }
    else if (from_energy_choice == KILOWATT_HOUR && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_megaJoules(kiloWattHour_to_joules(input_number));
        input_unit = "kWh";
        output_unit = "GJ";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(megaWattHour_to_joules(input_number));
        input_unit = "MWh";
        output_unit = "Wh";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(megaWattHour_to_joules(input_number));
        input_unit = "MWh";
        output_unit = "kWh";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = input_number;
        input_unit = "MWh";
        output_unit = "MWh";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(megaWattHour_to_joules(input_number));
        input_unit = "MWh";
        output_unit = "BTU";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == JOULES)
    {
        output_number = megaWattHour_to_joules(input_number);
        input_unit = "MWh";
        output_unit = "J";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(megaJoules_to_joules(input_number));
        input_unit = "MWh";
        output_unit = "kJ";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(megaWattHour_to_joules(input_number));
        input_unit = "MWh";
        output_unit = "MJ";
    }
    else if (from_energy_choice == MEGAWATT_HOUR && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_gigaJoules(megaWattHour_to_joules(input_number));
        input_unit = "MWh";
        output_unit = "GJ";
    }
    else if (from_energy_choice == BTU && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(btu_to_joules(input_number));
        input_unit = "BTU";
        output_unit = "Wh";
    }
    else if (from_energy_choice == BTU && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(btu_to_joules(input_number));
        input_unit = "BTU";
        output_unit = "kWh";
    }
    else if (from_energy_choice == BTU && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(btu_to_joules(input_number));
        input_unit = "BTU";
        output_unit = "MWh";
    }
    else if (from_energy_choice == BTU && to_energy_choice == BTU)
    {
        output_number = input_number;
        input_unit = "BTU";
        output_unit = "BTU";
    }
    else if (from_energy_choice == BTU && to_energy_choice == JOULES)
    {
        output_number = btu_to_joules(input_number);
        input_unit = "BTU";
        output_unit = "J";
    }
    else if (from_energy_choice == BTU && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(btu_to_joules(input_number));
        input_unit = "BTU";
        output_unit = "kJ";
    }
    else if (from_energy_choice == BTU && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(btu_to_joules(input_number));
        input_unit = "BTU";
        output_unit = "MJ";
    }
    else if (from_energy_choice == BTU && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_gigaJoules(btu_to_joules(input_number));
        input_unit = "BTU";
        output_unit = "GJ";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(input_number);
        input_unit = "J";
        output_unit = "Wh";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(input_number);
        input_unit = "J";
        output_unit = "kWh";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(input_number);
        input_unit = "J";
        output_unit = "MWh";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(input_number);
        input_unit = "J";
        output_unit = "BTU";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == JOULES)
    {
        output_number = input_number;
        input_unit = "J";
        output_unit = "J";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(input_number);
        input_unit = "J";
        output_unit = "kJ";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(input_number);
        input_unit = "J";
        output_unit = "MJ";
    }
    else if (from_energy_choice == JOULES && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_gigaJoules(input_number);
        input_unit = "J";
        output_unit = "GJ";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(kiloJoules_to_joules(input_number));
        input_unit = "kJ";
        output_unit = "Wh";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(kiloJoules_to_joules(input_number));
        input_unit = "kJ";
        output_unit = "kWh";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(kiloJoules_to_joules(input_number));
        input_unit = "kJ";
        output_unit = "MWh";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(kiloJoules_to_joules(input_number));
        input_unit = "kJ";
        output_unit = "BTU";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == JOULES)
    {
        output_number = kiloJoules_to_joules(input_number);
        input_unit = "kJ";
        output_unit = "J";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == KILOJOULES)
    {
        output_number = input_number;
        input_unit = "kJ";
        output_unit = "kJ";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(kiloJoules_to_joules(input_number));
        input_unit = "kJ";
        output_unit = "MJ";
    }
    else if (from_energy_choice == KILOJOULES && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_gigaJoules(kiloJoules_to_joules(input_number));
        input_unit = "kJ";
        output_unit = "GJ";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(megaJoules_to_joules(input_number));
        input_unit = "MJ";
        output_unit = "Wh";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(megaWattHour_to_joules(input_number));
        input_unit = "MJ";
        output_unit = "kWh";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(megaJoules_to_joules(input_number));
        input_unit = "MJ";
        output_unit = "MWh";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(megaJoules_to_joules(input_number));
        input_unit = "MJ";
        output_unit = "BTU";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == JOULES)
    {
        output_number = megaJoules_to_joules(input_number);
        input_unit = "MJ";
        output_unit = "J";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(megaJoules_to_joules(input_number));
        input_unit = "MJ";
        output_unit = "kJ";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == MEGAJOULES)
    {
        output_number = input_number;
        input_unit = "MJ";
        output_unit = "MJ";
    }
    else if (from_energy_choice == MEGAJOULES && to_energy_choice == GIGAJOULES)
    {
        output_number = joules_to_gigaJoules(megaJoules_to_joules(input_number));
        input_unit = "MJ";
        output_unit = "GJ";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == WATT_HOUR)
    {
        output_number = joules_to_wattHour(gigaJoules_to_joules(input_number));
        input_unit = "GJ";
        output_unit = "Wh";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == KILOWATT_HOUR)
    {
        output_number = joules_to_kiloWattHour(gigaJoules_to_joules(input_number));
        input_unit = "GJ";
        output_unit = "kWh";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == MEGAWATT_HOUR)
    {
        output_number = joules_to_megaWattHour(gigaJoules_to_joules(input_number));
        input_unit = "GJ";
        output_unit = "MWh";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == BTU)
    {
        output_number = joules_to_btu(gigaJoules_to_joules(input_number));
        input_unit = "GJ";
        output_unit = "BTU";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == JOULES)
    {
        output_number = gigaJoules_to_joules(input_number);
        input_unit = "GJ";
        output_unit = "J";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == KILOJOULES)
    {
        output_number = joules_to_kiloJoules(gigaJoules_to_joules(input_number));
        input_unit = "GJ";
        output_unit = "kJ";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == MEGAJOULES)
    {
        output_number = joules_to_megaJoules(gigaJoules_to_joules(input_number));
        input_unit = "GJ";
        output_unit = "MJ";
    }
    else if (from_energy_choice == GIGAJOULES && to_energy_choice == GIGAJOULES)
    {
        output_number = input_number;
        input_unit = "GJ";
        output_unit = "GJ";
    }

    printf("%lf(%s) = %lf(%s)\n", input_number, input_unit, output_number, output_unit);
}

/* ENERGY FUNCTIONS */
double joules_to_wattHour(double ee)
{
    return (ee / 3600);
}
double joules_to_kiloWattHour(double ee)
{
    return (ee / 3.6e+6);
}
double joules_to_megaWattHour(double ee)
{
    return (ee / 3.6e+9);
}
double joules_to_btu(double ee)
{
    return (ee / 1055.05585);
}
double joules_to_kiloJoules(double ee)
{
    return (ee / 1000);
}
double joules_to_megaJoules(double ee)
{
    return (ee / 1e+6);
}
double joules_to_gigaJoules(double ee)
{
    return (ee / 1e+9);
}

double wattHour_to_joules(double ee)
{
    return (ee * 3600);
}
double kiloWattHour_to_joules(double ee)
{
    return (ee * 3.6e+6);
}
double megaWattHour_to_joules(double ee)
{
    return (ee * 3.6e+9);
}
double btu_to_joules(double ee)
{
    return (ee * 1055.05585);
}
double kiloJoules_to_joules(double ee)
{
    return (ee * 1000);
}
double megaJoules_to_joules(double ee)
{
    return (ee * 1e+6);
}
double gigaJoules_to_joules(double ee)
{
    return (ee * 1e+9);
}

/* Weight Conversion*/
void do_weight_conversion(int from_weight_choice, int to_weight_choice, double input_number)
{
    char *input_unit = NULL;
    char *output_unit = NULL;
    double output_number = 0.0;

    if (from_weight_choice == MICROGRAMS && to_weight_choice == MICROGRAMS)
    {
        output_number = input_number;
        input_unit = "mcg";
        output_unit = "mcg";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(microgram_to_gram(input_number));
        input_unit = "mcg";
        output_unit = "mg";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == GRAMS)
    {
        output_number = microgram_to_gram(input_number);
        input_unit = "mcg";
        output_unit = "g";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(microgram_to_gram(input_number));
        input_unit = "mcg";
        output_unit = "oz";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(microgram_to_gram(input_number));
        input_unit = "mcg";
        output_unit = "lb";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(microgram_to_gram(input_number));
        input_unit = "mcg";
        output_unit = "kg";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(microgram_to_gram(input_number));
        input_unit = "mcg";
        output_unit = "st";
    }
    else if (from_weight_choice == MICROGRAMS && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(microgram_to_gram(input_number));
        input_unit = "mcg";
        output_unit = "t";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(milligram_to_gram(input_number));
        input_unit = "mg";
        output_unit = "mcg";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == MILLIGRAMS)
    {
        output_number = input_number;
        input_unit = "mg";
        output_unit = "mg";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == GRAMS)
    {
        output_number = milligram_to_gram(input_number);
        input_unit = "mg";
        output_unit = "g";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(milligram_to_gram(input_number));
        input_unit = "mg";
        output_unit = "oz";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(milligram_to_gram(input_number));
        input_unit = "mg";
        output_unit = "lb";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(milligram_to_gram(input_number));
        input_unit = "mg";
        output_unit = "kg";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(milligram_to_gram(input_number));
        input_unit = "mg";
        output_unit = "st";
    }
    else if (from_weight_choice == MILLIGRAMS && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(milligram_to_gram(input_number));
        input_unit = "mg";
        output_unit = "t";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(input_number);
        input_unit = "g";
        output_unit = "mcg";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(input_number);
        input_unit = "g";
        output_unit = "mg";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == GRAMS)
    {
        output_number = input_number;
        input_unit = "g";
        output_unit = "g";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(input_number);
        input_unit = "g";
        output_unit = "oz";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(input_number);
        input_unit = "g";
        output_unit = "lb";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(input_number);
        input_unit = "g";
        output_unit = "kg";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(input_number);
        input_unit = "g";
        output_unit = "st";
    }
    else if (from_weight_choice == GRAMS && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(input_number);
        input_unit = "g";
        output_unit = "t";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(ounce_to_gram(input_number));
        input_unit = "oz";
        output_unit = "mcg";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(ounce_to_gram(input_number));
        input_unit = "oz";
        output_unit = "mg";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == GRAMS)
    {
        output_number = ounce_to_gram(input_number);
        input_unit = "oz";
        output_unit = "g";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == OUNCES)
    {
        output_number = input_number;
        input_unit = "oz";
        output_unit = "oz";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(ounce_to_gram(input_number));
        input_unit = "oz";
        output_unit = "lb";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(ounce_to_gram(input_number));
        input_unit = "oz";
        output_unit = "kg";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(ounce_to_gram(input_number));
        input_unit = "oz";
        output_unit = "st";
    }
    else if (from_weight_choice == OUNCES && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(ounce_to_gram(input_number));
        input_unit = "oz";
        output_unit = "t";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(pound_to_gram(input_number));
        input_unit = "lb";
        output_unit = "mcg";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(pound_to_gram(input_number));
        input_unit = "lb";
        output_unit = "mg";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == GRAMS)
    {
        output_number = pound_to_gram(input_number);
        input_unit = "lb";
        output_unit = "g";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(pound_to_gram(input_number));
        input_unit = "lb";
        output_unit = "oz";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == POUNDS)
    {
        output_number = input_number;
        input_unit = "lb";
        output_unit = "lb";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(pound_to_gram(input_number));
        input_unit = "lb";
        output_unit = "kg";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(pound_to_gram(input_number));
        input_unit = "lb";
        output_unit = "st";
    }
    else if (from_weight_choice == POUNDS && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(pound_to_gram(input_number));
        input_unit = "kg";
        output_unit = "t";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(kilogram_to_gram(input_number));
        input_unit = "kg";
        output_unit = "mcg";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(kilogram_to_gram(input_number));
        input_unit = "kg";
        output_unit = "mg";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == GRAMS)
    {
        output_number = kilogram_to_gram(input_number);
        input_unit = "kg";
        output_unit = "g";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(kilogram_to_gram(input_number));
        input_unit = "kg";
        output_unit = "oz";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(kilogram_to_gram(input_number));
        input_unit = "kg";
        output_unit = "lb";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == KILOGRAMS)
    {
        output_number = input_number;
        input_unit = "kg";
        output_unit = "kg";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(kilogram_to_gram(input_number));
        input_unit = "kg";
        output_unit = "st";
    }
    else if (from_weight_choice == KILOGRAMS && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(kilogram_to_gram(input_number));
        input_unit = "kg";
        output_unit = "t";
    }
    else if (from_weight_choice == STONES && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(stone_to_gram(input_number));
        input_unit = "st";
        output_unit = "mcg";
    }
    else if (from_weight_choice == STONES && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(stone_to_gram(input_number));
        output_unit = "mg";
    }
    else if (from_weight_choice == STONES && to_weight_choice == GRAMS)
    {
        output_number = stone_to_gram(input_number);
        input_unit = "st";
        output_unit = "g";
    }
    else if (from_weight_choice == STONES && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(stone_to_gram(input_number));
        input_unit = "st";
        output_unit = "oz";
    }
    else if (from_weight_choice == STONES && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(stone_to_gram(input_number));
        input_unit = "st";
        output_unit = "lb";
    }
    else if (from_weight_choice == STONES && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(stone_to_gram(input_number));
        input_unit = "st";
        output_unit = "kg";
    }
    else if (from_weight_choice == STONES && to_weight_choice == STONES)
    {
        output_number = input_number;
        input_unit = "st";
        output_unit = "st";
    }
    else if (from_weight_choice == STONES && to_weight_choice == METRIC_TONS)
    {
        output_number = gram_to_metricTon(stone_to_gram(input_number));
        input_unit = "st";
        output_unit = "t";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == MICROGRAMS)
    {
        output_number = gram_to_microgram(metricTon_to_gram(input_number));
        input_unit = "t";
        output_unit = "mcg";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == MILLIGRAMS)
    {
        output_number = gram_to_milligram(metricTon_to_gram(input_number));
        input_unit = "t";
        output_unit = "mg";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == GRAMS)
    {
        output_number = metricTon_to_gram(input_number);
        input_unit = "t";
        output_unit = "g";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == OUNCES)
    {
        output_number = gram_to_ounce(metricTon_to_gram(input_number));
        input_unit = "t";
        output_unit = "oz";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == POUNDS)
    {
        output_number = gram_to_pound(metricTon_to_gram(input_number));
        input_unit = "t";
        output_unit = "lb";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == KILOGRAMS)
    {
        output_number = gram_to_kilogram(metricTon_to_gram(input_number));
        input_unit = "t";
        output_unit = "kg";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == STONES)
    {
        output_number = gram_to_stone(metricTon_to_gram(input_number));
        input_unit = "t";
        output_unit = "st";
    }
    else if (from_weight_choice == METRIC_TONS && to_weight_choice == METRIC_TONS)
    {
        output_number = input_number;
        input_unit = "t";
        output_unit = "t";
    }

    printf("%lf(%s) = %lf(%s)\n", input_number, input_unit, output_number, output_unit);
}

/* Weight Functions */
double gram_to_microgram(double ww)
{
    return (ww * 10e+5);
}
double gram_to_milligram(double ww)
{
    return (ww * 1000);
}
double gram_to_ounce(double ww)
{
    return (ww / 28.34952);
}
double gram_to_pound(double ww)
{
    return (ww / 453.59237);
}
double gram_to_kilogram(double ww)
{
    return (ww / 1000);
}
double gram_to_stone(double ww)
{
    return (ww * 157473e-9);
}
double gram_to_metricTon(double ww)
{
    return (ww / 10e+5);
}
double microgram_to_gram(double ww)
{
    return (ww / 10e+5);
}
double milligram_to_gram(double ww)
{
    return (ww / 1000);
}
double ounce_to_gram(double ww)
{
    return (ww * 28.34952);
}
double pound_to_gram(double ww)
{
    return (ww * 453.59237);
}
double kilogram_to_gram(double ww)
{
    return (ww * 1000);
}
double stone_to_gram(double ww)
{
    return (ww / 157473e-9);
}
double metricTon_to_gram(double ww)
{
    return (ww * 10e+5);
}

/* Length Conversion*/
void do_length_conversion(int from_length_choice, int to_length_choice, double input_number)
{
    char *input_unit = NULL;
    char *output_unit = NULL;
    double output_number = 0.0;

    if (from_length_choice == MILLIMETER && to_length_choice == MILLIMETER)
    {
        output_number = input_number;
        input_unit = "mm";
        output_unit = "mm";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(input_number);
        input_unit = "mm";
        output_unit = "cm";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(input_number);
        input_unit = "mm";
        output_unit = "m";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(input_number);
        input_unit = "mm";
        output_unit = "km";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(input_number);
        input_unit = "mm";
        output_unit = "in";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(input_number);
        input_unit = "mm";
        output_unit = "ft";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(input_number);
        input_unit = "mm";
        output_unit = "yd";
    }
    else if (from_length_choice == MILLIMETER && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(input_number);
        input_unit = "mm";
        output_unit = "mi";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == MILLIMETER)
    {
        output_number = centimeter_to_millimeter(input_number);
        input_unit = "cm";
        output_unit = "mm";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == CENTIMETER)
    {
        output_number = input_number;
        input_unit = "cm";
        output_unit = "cm";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "m";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "km";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "in";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "in";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "ft";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "yd";
    }
    else if (from_length_choice == CENTIMETER && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(centimeter_to_millimeter(input_number));
        input_unit = "cm";
        output_unit = "mi";
    }
    else if (from_length_choice == METER && to_length_choice == MILLIMETER)
    {
        output_number = meter_to_millimeter(input_number);
        input_unit = "m";
        output_unit = "mm";
    }
    else if (from_length_choice == METER && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(meter_to_millimeter(input_number));
        input_unit = "m";
        output_unit = "cm";
    }
    else if (from_length_choice == METER && to_length_choice == METER)
    {
        output_number = input_number;
        input_unit = "m";
        output_unit = "m";
    }
    else if (from_length_choice == METER && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(meter_to_millimeter(input_number));
        input_unit = "m";
        output_unit = "km";
    }
    else if (from_length_choice == METER && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(meter_to_millimeter(input_number));
        input_unit = "m";
        output_unit = "in";
    }
    else if (from_length_choice == METER && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(meter_to_millimeter(input_number));
        input_unit = "m";
        output_unit = "ft";
    }
    else if (from_length_choice == METER && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(meter_to_millimeter(input_number));
        input_unit = "m";
        output_unit = "yd";
    }
    else if (from_length_choice == METER && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(meter_to_millimeter(input_number));
        input_unit = "m";
        output_unit = "mi";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == MILLIMETER)
    {
        output_number = kilometer_to_millimeter(input_number);
        input_unit = "km";
        output_unit = "mm";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(kilometer_to_millimeter(input_number));
        input_unit = "km";
        output_unit = "cm";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(kilometer_to_millimeter(input_number));
        input_unit = "km";
        output_unit = "m";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == KILOMETER)
    {
        output_number = input_number;
        input_unit = "km";
        output_unit = "km";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(kilometer_to_millimeter(input_number));
        input_unit = "km";
        output_unit = "in";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(kilometer_to_millimeter(input_number));
        input_unit = "km";
        output_unit = "ft";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(kilometer_to_millimeter(input_number));
        input_unit = "km";
        output_unit = "yd";
    }
    else if (from_length_choice == KILOMETER && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(kilometer_to_millimeter(input_number));
        input_unit = "km";
        output_unit = "mi";
    }
    else if (from_length_choice == INCH && to_length_choice == MILLIMETER)
    {
        output_number = inch_to_millimeter(input_number);
        input_unit = "in";
        output_unit = "mm";
    }
    else if (from_length_choice == INCH && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(inch_to_millimeter(input_number));
        input_unit = "in";
        output_unit = "cm";
    }
    else if (from_length_choice == INCH && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(inch_to_millimeter(input_number));
        input_unit = "in";
        output_unit = "m";
    }
    else if (from_length_choice == INCH && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(inch_to_millimeter(input_number));
        input_unit = "in";
        output_unit = "km";
    }
    else if (from_length_choice == INCH && to_length_choice == INCH)
    {
        output_number = input_number;
        input_unit = "in";
        output_unit = "in";
    }
    else if (from_length_choice == INCH && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(inch_to_millimeter(input_number));
        input_unit = "in";
        output_unit = "ft";
    }
    else if (from_length_choice == INCH && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(inch_to_millimeter(input_number));
        input_unit = "in";
        output_unit = "yd";
    }
    else if (from_length_choice == INCH && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(inch_to_millimeter(input_number));
        input_unit = "in";
        output_unit = "mi";
    }
    else if (from_length_choice == FOOT && to_length_choice == MILLIMETER)
    {
        output_number = foot_to_millimeter(input_number);
        input_unit = "ft";
        output_unit = "mm";
    }
    else if (from_length_choice == FOOT && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(foot_to_millimeter(input_number));
        input_unit = "ft";
        output_unit = "cm";
    }
    else if (from_length_choice == FOOT && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(foot_to_millimeter(input_number));
        input_unit = "ft";
        output_unit = "m";
    }
    else if (from_length_choice == FOOT && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(foot_to_millimeter(input_number));
        input_unit = "ft";
        output_unit = "km";
    }
    else if (from_length_choice == FOOT && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(foot_to_millimeter(input_number));
        input_unit = "ft";
        output_unit = "in";
    }
    else if (from_length_choice == FOOT && to_length_choice == FOOT)
    {
        output_number = input_number;
        input_unit = "ft";
        output_unit = "ft";
    }
    else if (from_length_choice == FOOT && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(foot_to_millimeter(input_number));
        input_unit = "ft";
        output_unit = "yd";
    }
    else if (from_length_choice == FOOT && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(foot_to_millimeter(input_number));
        input_unit = "ft";
        output_unit = "mi";
    }
    else if (from_length_choice == YARD && to_length_choice == MILLIMETER)
    {
        output_number = yard_to_millimeter(input_number);
        input_unit = "yd";
        output_unit = "mm";
    }
    else if (from_length_choice == YARD && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(yard_to_millimeter(input_number));
        input_unit = "yd";
        output_unit = "cm";
    }
    else if (from_length_choice == YARD && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(yard_to_millimeter(input_number));
        input_unit = "yd";
        output_unit = "m";
    }
    else if (from_length_choice == YARD && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(yard_to_millimeter(input_number));
        input_unit = "yd";
        output_unit = "km";
    }
    else if (from_length_choice == YARD && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(yard_to_millimeter(input_number));
        input_unit = "yd";
        output_unit = "in";
    }
    else if (from_length_choice == YARD && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(yard_to_millimeter(input_number));
        input_unit = "yd";
        output_unit = "ft";
    }
    else if (from_length_choice == YARD && to_length_choice == YARD)
    {
        output_number = input_number;
        input_unit = "yd";
        output_unit = "yd";
    }
    else if (from_length_choice == YARD && to_length_choice == MILE)
    {
        output_number = millimeter_to_mile(yard_to_millimeter(input_number));
        input_unit = "yd";
        output_unit = "mi";
    }
    else if (from_length_choice == MILE && to_length_choice == MILLIMETER)
    {
        output_number = mile_to_millimeter(input_number);
        input_unit = "mi";
        output_unit = "mm";
    }
    else if (from_length_choice == MILE && to_length_choice == CENTIMETER)
    {
        output_number = millimeter_to_centimeter(mile_to_millimeter(input_number));
        input_unit = "mi";
        output_unit = "cm";
    }
    else if (from_length_choice == MILE && to_length_choice == METER)
    {
        output_number = millimeter_to_meter(mile_to_millimeter(input_number));
        input_unit = "mi";
        output_unit = "m";
    }
    else if (from_length_choice == MILE && to_length_choice == KILOMETER)
    {
        output_number = millimeter_to_kilometer(mile_to_millimeter(input_number));
        input_unit = "mi";
        output_unit = "km";
    }
    else if (from_length_choice == MILE && to_length_choice == INCH)
    {
        output_number = millimeter_to_inch(mile_to_millimeter(input_number));
        input_unit = "mi";
        output_unit = "in";
    }
    else if (from_length_choice == MILE && to_length_choice == FOOT)
    {
        output_number = millimeter_to_foot(mile_to_millimeter(input_number));
        input_unit = "mi";
        output_unit = "ft";
    }
    else if (from_length_choice == MILE && to_length_choice == YARD)
    {
        output_number = millimeter_to_yard(mile_to_millimeter(input_number));
        input_unit = "mi";
        output_unit = "yd";
    }
    else if (from_length_choice == MILE && to_length_choice == MILE)
    {
        output_number = input_number;
        input_unit = "mi";
        output_unit = "mi";
    }

    printf("%lf(%s) = %lf(%s)\n", input_number, input_unit, output_number, output_unit);
}

/* LENGTH FUNCTIONS */
double millimeter_to_centimeter(double mm)
{
    return (mm / 10.0);
}

double millimeter_to_meter(double mm)
{
    return (mm / 1000.0);
}

double millimeter_to_kilometer(double mm)
{
    return (mm / 1000000.0);
}

double millimeter_to_inch(double mm)
{
    return (mm / 25.4);
}

double millimeter_to_foot(double mm)
{
    return (mm / 304.8);
}

double millimeter_to_yard(double mm)
{
    return (mm / 914.4);
}

double millimeter_to_mile(double mm)
{
    return (mm / 1.609e+6);
}

double centimeter_to_millimeter(double cm)
{
    return (cm * 10.0);
}

double meter_to_millimeter(double m)
{
    return (m * 1000.0);
}

double kilometer_to_millimeter(double km)
{
    return (km * 1000000.0);
}

double inch_to_millimeter(double inch)
{
    return (inch * 25.4);
}

double foot_to_millimeter(double ft)
{
    return (ft * 304.8);
}

double yard_to_millimeter(double yd)
{
    return (yd * 914.4);
}

double mile_to_millimeter(double mi)
{
    return (mi * 1.609e+6);
}

/*GET CHOICE*/

int get_choice(const char *prompt, int valid_response_start, int valid_response_end)
{
    int number_of_tries;
    int choice;
    int flag = FALSE;

    for (number_of_tries = 0; number_of_tries < NR_MAX_TRIES; ++number_of_tries)
    {
        printf(prompt);
        scanf_s("%d", &choice);
        if (choice >= valid_response_start && choice <= valid_response_end)
        {
            flag = TRUE;
            break;
        }
        printf("Please Enter a valid choice\n");
    }

    if (flag == FALSE)
    {
        exit_application();
    }

    return (choice);
}

void exit_application(void)
{
    printf("\n");
    puts("Thank you for using the application...");
    _getch();
    exit(EXIT_SUCCESS);
}
