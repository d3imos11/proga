// myfunc.c
#include "bib.h"

#define PI 3.14159

void inputCircles(Circle *circles, int n) {
    for (int i = 0; i < n; i++) {
        printf("Введите координаты центра и радиус окружности %d (x0 y0 R): ", i + 1);
        scanf("%f %f %f", &circles[i].x0, &circles[i].y0, &circles[i].R);
    }
}

void computeAndPrintCircleInfo(Circle *circles, int n) {
    for (int i = 0; i < n; i++) {
        // Вычисление длины окружности
        float circumference = 2 * PI * circles[i].R;
        printf("Длина окружности %d: %.2fn", i + 1, circumference);
        
        // Проверка пересечения с осями
        if (circles[i].R >= fabs(circles[i].x0)) {
            printf("Окружность %d пересекает ось OYn", i + 1);
        }
        if (circles[i].R >= fabs(circles[i].y0)) {
            printf("Окружность %d пересекает ось OXn", i + 1);
        }
    }
}