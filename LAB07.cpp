#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void setcolor(int fg,int bg){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, bg*16+fg);}
void setcursor(bool visible)
{
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO lpCursor;
lpCursor.bVisible = visible;
lpCursor.dwSize = 20;
SetConsoleCursorInfo(console,&lpCursor);
}
void gotoxy(int x, int y)
{
COORD c = { x, y };
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x,int y)
{
gotoxy(x,y); printf(" <-0-> ");
}
void draw_bullet(int x,int y)
{
gotoxy(x,y); printf("^");
}
void clear_bullet(int x,int y)
{
gotoxy(x,y); printf(" ");
}
void draw_star(int x,int y)
{
gotoxy(x,y); printf("*");
}
void clear_star(int x,int y)
{
gotoxy(x,y); printf(" ");
}
char cursor(int x, int y){
HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
char buf[2]; COORD c = {x,y}; DWORD num_read;
if(
!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )

return '\0';
else
return buf[0];

}
void board (int score){
    gotoxy(80,1);
    setcolor(7,0);
    printf("SCORE : %d",score);
}
int main()
{
setcursor(0);
char ch='.';
int x=38,y=20;
int bx,by,i;
int bullet = 0;
int c;
int score=0;
srand( time( NULL ) );
for (c=0;c<20;c++){ 
    draw_star(10+rand()%61,2+rand()%5);
    }
draw_ship(x,y);
do {
if (_kbhit()){
ch=_getch();
if(ch=='a') {draw_ship(--x,y);}
if(ch=='d') {draw_ship(++x,y);}
if(bullet!=1 && ch==' ') {
    bullet=1; 
    bx=x+3; 
    by=y-1;
    }
fflush(stdin);
}
if (bullet==1) {

clear_bullet(bx,by);
if(cursor(bx,by-1)=='*'){
    bullet=0;
    Beep(1000,100);
    clear_star(bx,by-1);
    draw_star(10+rand()%61,2+rand()%5);
    board(++score);
     FILE*f=fopen("data.txt","w");
    fprintf(f,"Score_1 : %d",score);
    


}
else if (by==2) { bullet=0;} else { draw_bullet(bx,--by); }
 
}
Sleep(100);
} while (ch!='x');
return 0;
}