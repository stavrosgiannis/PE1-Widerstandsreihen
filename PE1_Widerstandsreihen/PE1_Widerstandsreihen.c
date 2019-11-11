#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// frage den Benutzer nach gewuenschter E-Reihe

int read_e_series()
{
	while (1)
	{
		int n;
		printf("\n\tBitte geben Sie die Nr. der E-Reihe an: ");
		scanf("%i", &n);
		while (getchar() != '\n');

		if (n == 6 || n == 12 || n == 24 || n == 48 || n == 96 || n == 192) return n;

		printf("\n\nungueltige Eingabe (%i)!\n\n", n);
		printf("gueltige Werte: 6, 12, 24, 48, 96, 192!\n\n");
	}
}

// frage den Benutzer nach gewuenschter Dekade

int read_decade()
{
	int n;
	printf("\n\tBitte geben Sie den Dekadenfaktor an: ");
	scanf("%i", &n);
	while (getchar() != '\n');
	return n;
}

// Konstanten fuer den Zugriff in der Tabelle
// 1. Spalte: Nennwert-Toleranz
// 2. Spalte: Nennwert
// 3. Spalte: Nennwert+Toleranz
#define LOWER_BOUND 0
#define SET_VALUE 1
#define UPPER_BOUND 2

int main()
{
	printf("\n\nProgramm zur Berechnung von Widerstandsreihen\n");
	printf("--------------------------------------------------------\n");

	// lese gewuenschte E-Reihe und Dekade
	int e_series = read_e_series();
	int decade = read_decade();

	/*
	// bestimme erste die Toleranz und dann die Werte der Tabelle -
	// in jeder Zeile jeweils untere Grenze, Sollwert und obere Grenze
	double table[192][3];
	double tolerance = compute_tolerance(e_series);
	compute_values(e_series, decade, tolerance, table);
	print_table(e_series, table);

	// bestimme die Farbcodierung eines gewaehlten Widerstands
	char coding[80];
	int n = read_list_number(e_series);
	compute_coding(e_series, table[n][SET_VALUE], tolerance, coding);
	printf("Die Farbcodierung dieses Widerstands ist: %s\n", coding);
	*/
}