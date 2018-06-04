#include <stdio.h>
#include <3ds.h>

#include "player.h"

//up - 50x30; down - 40x30

int main(int argc, char **argv){
	gfxInitDefault();

	PrintConsole topScreen, bottomScreen;

	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleInit(GFX_TOP, &topScreen);

	consoleSelect(&topScreen);

	struct player p1;

	p1.y = 12;
	p1.x = 12;
	p1.contrTime = 0;
	p1.direction = 2;
	p1.sign = 'o';

	printf("\x1b[%d;%dH%c",p1.y,p1.x,p1.sign);

	int diff = 20;

	while(aptMainLoop()){
		hidScanInput();

		u32 kDown = hidKeysDown();

		showCords(&p1, &topScreen, &bottomScreen, 0, 0);

		if(kDown & KEY_START) break;
		if((kDown & KEY_DUP)) changeUp(&p1);
		if((kDown & KEY_DDOWN)) changeDown(&p1);
		if((kDown & KEY_DLEFT)) changeLeft(&p1);
		if((kDown & KEY_DRIGHT)) changeRight(&p1);

		if((kDown & KEY_L) && diff > 0) diff -= 5;
		if((kDown & KEY_R) && diff < 20) diff += 5;

		if(p1.contrTime >= diff){
			if(p1.direction==0 && p1.y > 1) moveUp(&p1);
			else if(p1.direction==1 && p1.x < 50) moveRight(&p1);
			else if(p1.direction==2 && p1.y < 30) moveDown(&p1);
			else if(p1.direction==3 && p1.x > 1) moveLeft(&p1);
			p1.contrTime = 0;
		}

		updateTime(&p1);

		consoleSelect(&bottomScreen);
		printf("\x1b[2;1H%d  ", p1.contrTime);
		printf("\x1b[3;1H%d", p1.direction);
		printf("\x1b[4;1H%d  ", diff);
		consoleSelect(&topScreen);

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
