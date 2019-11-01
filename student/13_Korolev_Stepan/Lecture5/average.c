#include "average.h"
#include <stdarg.h>

double average(int count, ...) {

	va_list ap;
	double sum = 0;
	va_start(ap, count); /* Требуется последний известный аргумент (чтобы получить адрес первого неизвестного) */

	for (int j = 0; j < count; j++) {

		sum += va_arg(ap, int); /* Увеличивает ap до следующего аргумента. */

	}

	va_end(ap);


	return sum / count;

}