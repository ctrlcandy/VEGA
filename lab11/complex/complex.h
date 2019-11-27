#pragma once

/**
* Комплексное число
*/
typedef struct {
	float x;
	float y;
} Complex;

/**
* Сложение
*/
Complex add(Complex a, Complex b);

/**
* Умножение
*/
Complex mul(Complex a, Complex b);

/**
* Деление
*/
Complex div(Complex a, Complex b);

/**
* Получение модуля
*/
float mod(Complex a);

/**
* Получение аргумента
*/
float arg(Complex a);

/**
* Получение сопряжённого
*/
Complex conjugate(Complex a);

/**
* Вывод в алгебраической форме
*/
void printAlg(Complex a);

/**
* Вывод в тригонометрической форме
*/
void printTrig(Complex a);

/**
* Вывод в показательной форме
*/
void printExp(Complex a);