#ifndef __ITOA_H
#define __ITOA_H

int itoa(int val, char* buf) {
    const int radix = 10;

    char* p;
    int a;
    int len;
    char* b;
    char temp;
    p = buf;

    if (val < 0){
        *p++ = '-';
        val = 0 - val;
    }

    b = p;

    do {
        a = val % radix;
        val /= radix;
        *p++ = a + '0';
	} while (val > 0);
	len = (int)(p - buf);

    *p-- = 0;
	do {
		temp = *p;
		*p = *b;
		*b = temp;
		--p;
		++b;
    } while (b < p);
    return len;
}

#endif