struct player{
	int x, y, direction;
	int contrTime;
	char sign;
};

void showCords(struct player *p1, PrintConsole *topScreen, PrintConsole *bottomScreen, int x, int y){
	consoleSelect(bottomScreen);
	printf("\x1b[%d;%dHX = %d Y = %d     ",y,x,p1->x,p1->y);
	consoleSelect(topScreen);
}

void moveUp(struct player *p1){
	printf("\x1b[%d;%dH ",p1->y,p1->x);
	p1->y--;
	printf("\x1b[%d;%dH%c",p1->y,p1->x,p1->sign);
}

void moveDown(struct player *p1){
	printf("\x1b[%d;%dH ",p1->y,p1->x);
	p1->y++;
	printf("\x1b[%d;%dH%c",p1->y,p1->x,p1->sign);
}

void moveLeft(struct player *p1){
	printf("\x1b[%d;%dH ",p1->y,p1->x);
	p1->x--;
	printf("\x1b[%d;%dH%c",p1->y,p1->x,p1->sign);
}

void moveRight(struct player *p1){
	printf("\x1b[%d;%dH ",p1->y,p1->x);
	p1->x++;
	printf("\x1b[%d;%dH%c",p1->y,p1->x,p1->sign);
}

void changeUp(struct player *p1){
	p1 -> direction = 0;
}

void changeDown(struct player *p1){
	p1 -> direction = 2;
}

void changeLeft(struct player *p1){
	p1 -> direction = 3;
}

void changeRight(struct player *p1){
	p1 -> direction = 1;
}

void updateTime(struct player *p1){
	p1 -> contrTime++;
}