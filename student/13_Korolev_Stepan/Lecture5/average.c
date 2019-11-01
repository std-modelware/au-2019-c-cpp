#include "average.h"
#include <math.h>
#include <stdarg.h>

double average(int count, ...) {

	va_list ap;
	double sum = 0;
	va_start(ap, count); /* Требуется последний известный аргумент (чтобы получить адрес первого неизвестного) */

	for (int j = 0; j < count; j++) {

		sum += pow(va_arg(ap, int), 2); /* Увеличивает ap до следующего аргумента. */

	}

	va_end(ap);


	return sqrt(sum);

}
