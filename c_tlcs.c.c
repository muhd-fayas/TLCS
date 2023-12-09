#include <reg51.h>

sbit nr = P1^0;
sbit ny = P1^1;
sbit ng = P1^2;
sbit sr = P1^3;
sbit sy = P1^4;
sbit sg = P1^5;
sbit er = P2^7;
sbit ey = P2^6;
sbit eg = P2^5;
sbit wr = P2^4;
sbit wy = P2^3;
sbit wg = P2^2;

#define DELAY_GREEN 30000
#define DELAY_YELLOW 5000

void delay(unsigned int count);

void main() {
    while (1) {
        // State Green road1
        nr = ny = 0; ng = 1;
        sr = sy = 0; sg = 1;
        er = wr = 1; eg = ey = wy = wg = 0;
        delay(DELAY_GREEN);

        // State yellow road1
        ny = 1; ng = 0;
        sy = 1; sg = 0;
        delay(DELAY_YELLOW);

        // State Red road1
        nr = 1; ny = 0;
        sr = 1; sy = 0;
        ey = wy = 1; eg = wg = er=wr=0;
        delay(DELAY_YELLOW);

        // State Green road2
        er = ey = 0; eg = 1;
        wr = wy = 0; wg = 1;
        nr = sr = 1; ng = sg = 0;
        delay(DELAY_GREEN);

        // State Yellow road2
        ey = 1; eg = ng = 0;
        wy = 1; wg = sg = 0;
				nr=sr=1;
        delay(DELAY_YELLOW);

        // State Red road2
        er = 1; ey = 0;
        wr = 1; wy = 0;
        nr = sr = 0; ng= sg = 0;
				ny = sy =1;
        delay(DELAY_YELLOW);
    }
}

// for 11.0592 MHz crystal
void delay(unsigned int count) {
    unsigned int i;
    while (count) {
        i = 115;
        while (i > 0)
            i--;
        count--;
    }
}




		
		
		
		
		