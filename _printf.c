#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c) { return (write(1, &c, 1)); }

int print_d(int n)
{
	int digits[30];
	int i, j, written;

	i = 0;
	written = 0;

	if (n == 0)
		written += _putchar('0');

	if (n < 0)
	{
		written += _putchar('-');
		n *= -1;
	}

	while (n != 0)
	{
		digits[i] = n % 10;
		n /= 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		written += _putchar(digits[j] + '0');
	}
	return (written);
}

int print_s(char *str)
{
	int printed;
	char *string;

	string = str;

	printed = 0;
	while (*string != '\0')
	{
		printed += write(1, string, 1);
		string++;
	}

	return (printed);
}

int _printf(const char *format, ...)
{
	va_list ap;
	int chars_printed, i;
	char *current_char;

	if (format == NULL)
	{
		return (0);
	}

	current_char = (char *)format;
	va_start(ap, format);

	chars_printed = 0;
	i = 0;
	while (current_char[i] != '\0')
	{
		/* if current char is'%' */
		if (current_char[i] == '%')
		{
			i++;
			/* handle next char approprietly */
			switch (current_char[i])
			{
			case 'c':
				chars_printed += _putchar(va_arg(ap, int));
				break;
			case 's':
				chars_printed += print_s(va_arg(ap, char *));
				break;
			case '%':
				chars_printed += _putchar('%');
				break;
			case 'd':
			case 'i':
				chars_printed += print_d(va_arg(ap, int));
				break;
			default:
				break;
			}
		}
		else
		{
			_putchar(current_char[i]);
		}
		i++;
	}

	return (chars_printed);
}

