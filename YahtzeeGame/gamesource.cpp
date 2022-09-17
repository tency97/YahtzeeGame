//////////////////////////////////////
// 솜성이 만드는 첫번째 C 언어 게임 //
// Yahtzee 2021.03.01               //
// sms3058@naver.com                //
//////////////////////////////////////

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//#define RAND_MAX = 6;

void gotoxy(int x, int y) { // gotoxy 함수 선언
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void preset() { // 콘솔 창 셋업
	CONSOLE_CURSOR_INFO cursorInfo; // 커서를 안보이게 함
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	system("title YAHTZEE BY SOMSUNG");
	system("mode con cols=100 lines=50");
}
void makehori(int num) { // 가로줄 생성기
	for (int i = 0; i < num; i++) {
		printf("─");
	}
}
void makevert() { // 세로줄 생성기
	for (int i = 4; i < 35; i++) {
		gotoxy(4, i); printf("│");
		gotoxy(25, i); printf("│");
		gotoxy(30, i); printf(" │     │     │");
		if (!(i % 2)) {
			gotoxy(25, i);
			printf("├──────────┼─────┼─────┤");
		}
	}
}
void frame() { // 게임 프레임
	int x = 4;
	int y = 3;
	gotoxy(x, y + 0); printf("┌");
	makehori(41); printf("┬");
	makehori(22); printf("┐");
	makevert();
	gotoxy(x, y + 32); printf("└");
	makehori(41); printf("┴");
	makehori(22); printf("┘");
}
void scoreboard() { // 점수판
	int x = 26;
	int y = 5;
	char score[15][10] = {
		"Ones","Twos", "Threes", "Fours", "Fives",
		"Sixes", "Sum", "Bonus", "3 O Kind", "4 O Kind", "Full H",
		"Small St", "Large St", "Chance", "YAHTZEE!" };

	for (int i = 0; i < 15; i++) {
		gotoxy(x, y + (2 * i));
		printf("%s", score + i);
	}
}

void start();
void title() { // 타이틀창 셋업
	int x = 5;
	int y = 8;
	gotoxy(x, y + 0); printf("□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y + 1); printf("□□                    □□□□□□□□");
	gotoxy(x, y + 2); printf("□□□  □□□□□□□□  □□□□□□□");
	gotoxy(x, y + 3); printf("□□□□  □YAHTZEE 야찌□  □□□□□□");
	gotoxy(x, y + 4); printf("□□□□□  □□□□□□□□  □□□□□");
	gotoxy(x, y + 5); printf("□□□□□□  MADE BY SOMSUNG   □□□□");
	gotoxy(x, y + 6); printf("□□□□□□□  □①②③④⑤⑥□  □□□");
	gotoxy(x, y + 7); printf("□□□□□□□□                    □□");
	gotoxy(x, y + 8); printf("□□□□□□□□□□□□□□□□□□□□");

	gotoxy(x, y + 14); printf("□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y + 15); printf("□  □  □      □  □  □      □□□□");
	gotoxy(x, y + 16); printf("□  □  □  □  □  □  □□  □□□□□");
	gotoxy(x, y + 17); printf("□□  □□      □      □□  □□    □");
	gotoxy(x, y + 18); printf("□□  □□  □  □  □  □□  □□□□□");
	gotoxy(x, y + 19); printf("□□  □□  □  □  □  □□  □□□□□");
	gotoxy(x, y + 20); printf("□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y + 21); printf("□      □      □      □□□□□□  □");
	gotoxy(x, y + 22); printf("□□□  □  □□□  □□□□□□□□  □");
	gotoxy(x, y + 23); printf("□□  □□      □      □□    □□  □");
	gotoxy(x, y + 24); printf("□  □□□  □□□  □□□□□□□□□□");
	gotoxy(x, y + 25); printf("□      □      □      □□□□□□  □");
	gotoxy(x, y + 26); printf("□□□□□□□□□□□□□□□□□□□□");

	gotoxy(x + 6, y + 11); printf("PRESS ANY KEY");

	while (1) {
		if (_kbhit()) {
			while (!_kbhit()); int a = _getch(); // clear buffer
			fflush(stdin); // clear stdin's buffer
			start();
			break;
		}
	}
}

void ingame_Frame() {

}

void maingamelogic() {
	int turn = 0;
	int x = 5;
	int y = 37;
	int dicecount = 3;
	gotoxy(x, y);
	printf("A의 차례입니다.. 주사위를 굴리세요.(%d)\n", dicecount);
	int select_menu = 0;
	gotoxy(x, y + 1);
	printf("할 행동을 선택하세요. [1. 주사위 굴리기] [2. 주사위 선택하기] [3. ]");
	scanf_s("%d", &select_menu);
	switch (select_menu) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}


}

int diceroll() {
	int rolling = 0;
	while (TRUE) {
		srand((unsigned int)clock());
		rolling = rand() % 7;
		if (!rolling) { // 0이 나오면 continue
			continue;
		}
		else {
			return rolling;
			break;
		}
	}
}

int dicelogic() {
	int rollcount = 2;
	printf("주사위를 굴립니다.\n");
	for (int i = 0; i < 6; i++) {
		printf("주사위 값 :%d, 클럭 : %d\n", diceroll(), clock());
		Sleep(1300);
		return 0;
	}
}


void start() {
	system("cls");
	frame();
	scoreboard();
	maingamelogic();
}

int main() {
	preset();
	frame();
	scoreboard();
	title();

}

