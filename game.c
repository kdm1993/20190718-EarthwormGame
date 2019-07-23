#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

	void CursorView(char show)//커서숨기기
	{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
	}
	int game_x[100], game_y[100], z=4, tail=1, regame_x[100], regame_y[100];
	int x, start=0;
	int star_x, star_y;
	int gamestart = 0;
	gotoxy(int x, int y)//gotoxy함수를 호출해올 기본함수.
		{   
		  COORD pos = {x, y};
		  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
	int main(void) {
		int key;
		int left = 0, right = 1, up = 0, down = 0;
		CursorView(0);
		star_x = rand()%50;
		star_y = rand()%30;
		game_x[0] = 30;
		game_y[0] = 12;
		Gameprint();
		Star();
		Teduri();
		gotoxy(30, 11);
		printf("지 렁 이 게 임");
		gotoxy(23, 15);
		printf("시작하려면 -Enter-를 누르세요");
		while(1) 
		{
			Sleep(100);
			if(kbhit() == 1)
			{
				key = getch();
				if(key == 13 && gamestart == 0)
				{
					system("cls");
					Teduri();
					gamestart = 1;
				}
				if(key ==224) 
				{
					key = getch();
					if(key==75 && right == 0) 
					{ //왼쪽 화살표
						z = 1;
						left = 1;
						right = 0;
						up = 0;
						down = 0;
					} 
					else if(key==72 && down == 0) 
					{ // 위쪽 화살표 
						z = 2;
						left = 0;
						right = 0;
						up = 1;
						down = 0;
					} 
					else if(key==80 && up == 0) 
					{ // 아래쪽 화살표 
						z = 3;
						left = 0;
						right = 0;
						up = 0;
						down = 1;
					} 
					else if(key==77 && left == 0) 
					{ // 오른쪽 화살표 
						z = 4;
						left = 0;
						right = 1;
						up = 0;
						down = 0;
					}
				}
			}
			GameOver();
			Gameprint();
			Star();
		}	
	}
	int Gameprint()
		{
			if(gamestart == 1)
			{
				int sub=0;
				start = 1;
				for(x=0; x<tail; x++)
				{
					if(sub==0)
					{
						regame_x[x] = game_x[x];
						regame_y[x] = game_y[x];
						gotoxy(game_x[x], game_y[x]);
						printf(" ");
						if(tail-x==1)
						{
							sub = 1;
							x = 0;
						}
					}
					if(sub==1)
					{
						game_x[x+1] = regame_x[x];
						game_y[x+1] = regame_y[x];
						if(z == 1 && start == 1)
						{
							game_x[0]--;
						}
						else if(z == 2 && start == 1)
						{
							game_y[0]--;
						}
						else if(z == 3 && start == 1)
						{
							game_y[0]++;
						}
						else if(z == 4 && start == 1)
						{
							game_x[0]++;
						}
						gotoxy(game_x[x], game_y[x]);
						printf("0");					
						start = 0;
					}		
				}	
			}	
		}
	int GameOver()
	{
		for(x=1; x<100; x++)
		{
			if((x<78 && x==game_x[0] && (game_y[0] == 1 || game_y[0] == 23) 
			|| (x<24 && x==game_y[0] && (game_x[0] == 1 || game_x[0] == 77)))
			|| game_y[x] == game_y[0] && game_x[x] == game_x[0])
			{
				system("cls");
				Teduri();
				gotoxy(26, 9);
				printf("------- Game Over -------");
				gotoxy(30, 12);
				printf("몸통 개수 : %d개", tail);
				gotoxy(23, 15);
				printf("재시작하려면 -Enter-를 누르세요");
				tail = 1;
				z = 4;
				star_x = rand()%50;
				star_y = rand()%30;
				game_x[0] = 30;
				game_y[0] = 12;
				gamestart = 0;
			}
		}
	}
	int Star()
	{
		if(gamestart == 1)
		{
			gotoxy(star_x, star_y);
			printf("☆");
			if((star_x == game_x[0] || star_x+1 == game_x[0]) && star_y == game_y[0])
			{
				if(tail<100)
				{
					tail++;	
				}	
				star_x = rand()%75+2;
				star_y = rand()%20+2;
				gotoxy(star_x, star_y);
				printf("☆");
			}
		}
	}
	int Teduri()
	{
		for(x=0; x<79; x++)
		{
			gotoxy(x,0);
			printf("0");
			gotoxy(x,1);
			printf("0");
			gotoxy(x,23);
			printf("0");
			gotoxy(x,24);
			printf("0");
			if(x<25)
			{
				gotoxy(0,x);
				printf("0");
				gotoxy(1,x);
				printf("0");
				gotoxy(78,x);
				printf("0");
				gotoxy(79,x);
				printf("0");
			}
		}
	} 
