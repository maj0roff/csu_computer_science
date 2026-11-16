#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prediction.h"

#define MAX_DAYS 10000

int main()
{
    FILE* inputFile;
    if ((inputFile = fopen("../input.txt", "r")) == NULL) { printf("\nError opening file\n"); return 1; }

    Day* days = (Day*)malloc(sizeof(Day) * MAX_DAYS);

    int N = 0;
    while (N < MAX_DAYS && fscanf(inputFile, "%d %lf", &days[N].day, &days[N].temperature) == 2)
        N++;
    fclose(inputFile);

    if (N == 0) { printf("No data\n"); free(days); return 1; }

    double Sx = 0, Sy = 0, Sxx = 0, Sxy = 0, Syy = 0;
    for (int i = 0; i < N; i++)
    {
        double x = days[i].day;
        double y = days[i].temperature;
        Sx  += x;
        Sy  += y;
        Sxx += x * x;
        Sxy += x * y;
        Syy += y * y;
    }

    double num = N * Sxy - Sx * Sy;
    double denA = N * Sxx - Sx * Sx;
    double denR = denA * (N * Syy - Sy * Sy);

    double a = num / denA;
    double b = (Sy - a * Sx) / N;
    double R = num / sqrt(denR);

    int nextDay = N + 1;
    double prediction = a * nextDay + b;

    FILE* outputFile = fopen("../output.txt", "w");
    if (outputFile == NULL) { printf("Error opening output file\n"); free(days); return 1; }

    fprintf(outputFile, "a=%.3f\n", a);
    fprintf(outputFile, "b=%.3f\n", b);
    fprintf(outputFile, "R=%.3f\n", R);
    fprintf(outputFile, "Prediction for day %d: %.2f\n", nextDay, prediction);
    if (fabs(R) >= 0.7)
        fprintf(outputFile, "Trend: strong\n");
    else
        fprintf(outputFile, "Trend: weak\n");

    fclose(outputFile);
    free(days);
    return 0;
}
