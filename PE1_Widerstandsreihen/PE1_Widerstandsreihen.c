#define _CRT_SECURE_NO_WARNINGS 1

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

double compute_tolerance(int INPUT_E_SERIES) {
	switch (INPUT_E_SERIES) {
	case 6:
		return 0.20;
	case 12:
		return 0.10;
	case 24:
		return 0.05;
	case 48:
		return 0.02;
	case 96:
		return 0.01;
	case 192:
		return 0.005;
	}

	return 1;
}

int print_table(double INPUT_TABLE[192][3], int INPUT_E_SERIES, double INPUT_TOLERANCE) {
	printf("\n\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	printf("\t|%28s - %-13d|\n", "Widerstandsreihe E", INPUT_E_SERIES);

	printf("\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	printf("\t|%8c%4.1f%s | %6s %7c %7c%4.1f%s |\n", '-', (INPUT_TOLERANCE * 100), "%", "R", '|', '+', (INPUT_TOLERANCE * 100), "%");

	printf("\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	for (int i = 0; i <= INPUT_E_SERIES; i++) {
		printf("\t| %012.5f | %012.5f | %012.5f |\n", INPUT_TABLE[i][0], INPUT_TABLE[i][1], INPUT_TABLE[i][2]);
	}

	printf("\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	return 0;
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
	do
	{
		printf("\n\nProgramm zur Berechnung von Widerstandsreihen\n");
		printf("--------------------------------------------------------\n");

		// lese gewuenschte E-Reihe und Dekade
		double e_series = read_e_series();
		int decade = read_decade();

		// bestimme erste die Toleranz und dann die Werte der Tabelle -
		// in jeder Zeile jeweils untere Grenze, Sollwert und obere Grenze
		double table[192][3];
		double tolerance = compute_tolerance(e_series);
		//compute_values(e_series, decade, tolerance, table);
		//print_table(e_series, table);

		for (int i = 0; i <= e_series; i++) {
			table[i][1] = (pow(pow(10, 1 / e_series), i)) * (pow(10, decade));
			table[i][0] = table[i][1] - (table[i][1] * tolerance);
			table[i][2] = table[i][1] + (table[i][1] * tolerance);
		}

		if (print_table(table, e_series, tolerance) != 0) {
			printf("[FEHLER] Die Tabelle konnte nicht angezeigt werden!");
		}

		// bestimme die Farbcodierung eines gewaehlten Widerstands
		char coding[80];
		/*int n = read_list_number(e_series);
		compute_coding(e_series, table[n][SET_VALUE], tolerance, coding);
		printf("Die Farbcodierung dieses Widerstands ist: %s\n", coding);*/

		printf("\n\nerneute Berechnung? (j/n)\n");
	} while (getchar() == 'j' || getchar() == 'J');
}