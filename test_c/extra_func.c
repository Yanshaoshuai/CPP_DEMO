#include "test.h"
/**
 *
 * @param buffer
 * @return
 */
int len(char *buffer) {
    int i = 0;
    while (buffer[i] != '\0') {
        i++;
    }
    return i;
}
/**
 *
 * @param buffer
 */
void reverse(char *buffer) {
    int i, j;
    char tmp;
    for (i = 0, j = len(buffer) - 1; i < j; i++, j--) {
        tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
    }
}

/**
 *
 * @param number
 * @param buffer
 * @param radix
 */
char* itoa(int number, char *buffer, int radix) {
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int rem, i = 0;
    short sign = number > 0;
    do {
        buffer[i++] = (rem = number % radix) < 10
                      ? rem + '0'
                      : alphabet[rem - 10];
    } while ((number /= radix) > 0);
    if (!sign) {
        buffer[i++] = '-';
    }
    buffer[i++] = '\0';
    reverse(buffer);
    return buffer;
}