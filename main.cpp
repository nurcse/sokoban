#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <MMsystem.h>
#include <dos.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int move1, move2, move3;
int starting()
{
    int i, j, k, fx=450,fy=50, sx=500,sy=150, tx=400,ty=150, triangle[]={fx,fy, sx,sy, tx,ty, fx,fy};
    char out[30], *start = "start.jpg", select, *instruction1="instrc.jpg", *instruction2 = "instr.jpg", *about="me.jpg";
    setcolor(WHITE);
    drawpoly(4, triangle);

    for(i=1 ; i<=90 ; i++)
    {
        if(i<=30)
        {
            setcolor(WHITE);
            fx -= 5; fy+=10; sx-=5; sy+=10; tx-=5; ty+=10;
            triangle[0] = fx;
            triangle[1] = fy;
            triangle[2] = sx;
            triangle[3] = sy;
            triangle[4] = tx;
            triangle[5] = ty;
            triangle[6] = fx;
            triangle[7] = fy;
            drawpoly(4, triangle);
        }
        else if(i<=60)
        {
            //setcolor(CYAN);
            fx += 10; sx+=10; tx+=10;
            triangle[0] = fx;
            triangle[1] = fy;
            triangle[2] = sx;
            triangle[3] = sy;
            triangle[4] = tx;
            triangle[5] = ty;
            triangle[6] = fx;
            triangle[7] = fy;
            drawpoly(4, triangle);
        }
        else
        {
            //setcolor(CYAN);
            fx -= 5; fy-=10; sx-=5; sy-=10; tx-=5; ty-=10;
            triangle[0] = fx;
            triangle[1] = fy;
            triangle[2] = sx;
            triangle[3] = sy;
            triangle[4] = tx;
            triangle[5] = ty;
            triangle[6] = fx;
            triangle[7] = fy;
            drawpoly(4, triangle);
        }
        delay(30);
    }
    delay(50);
    setcolor(CYAN);
    settextstyle(10, 0, 8);
    outtextxy(150, 460, "TRIANGLE ARTs");
    delay(1700);

    clearviewport();
    setcolor(WHITE);
    fx = 110; fy=145; sx=480; sy=215;
    readimagefile(start, 100, 100, 600, 550);

    while(1)
    {
        rectangle(fx,fy, sx,sy);
        if(kbhit())
        {
            select = getch();
            if(select==80)   //press down
            {
                setcolor(BLACK);
                rectangle(fx,fy, sx,sy);
                if(fy==445)
                {
                    fy = 70;
                    sy = 140;
                }
                setcolor(WHITE);
                fy += 75;
                sy += 75;
                rectangle(fx,fy, sx,sy);
            }
            else if(select==72)    //press up
            {
                setcolor(BLACK);
                rectangle(fx,fy, sx,sy);
                if(fy==145)
                {
                    fy = 520;
                    sy = 590;
                }
                setcolor(WHITE);
                fy -= 75;
                sy -= 75;
                rectangle(fx,fy, sx,sy);
            }
            else if(select==13)  //press enter
            {
                if(fy==145)  //new game
                    return 1;
                else if(fy==145+75)  // instruction
                {
                    readimagefile(instruction1, 100, 70, 750, 600);
                    settextstyle(3, 0, 5);
                    setcolor(RED);
                    outtextxy(250, 550, " Press enter to next ...");
                    while(getch() != 13)
                    {
                    }
                    clearviewport();
                    readimagefile(instruction2, 100, 20, 800, 570);
                    settextstyle(3, 0, 5);

                    outtextxy(200, 580, " Press Esc to Main menu ...");
                    while(getch() != 27)
                    {
                    }
                    clearviewport();
                    setcolor(WHITE);
                    readimagefile(start, 100, 100, 600, 550);
                }
                else if(fy==(145+75+75))  // highest scores
                {
                    clearviewport();
                    freopen("Score.txt", "r", stdin);
                    setcolor(LIGHTGREEN);
                    settextstyle(3, 0, 6);
                    outtextxy(280, 30, " HIGH SCORES :");
                    k=100;
                    while(scanf("%s", out)!=EOF)
                    {
                        settextstyle(3, 0, 4);
                        setcolor(LIGHTBLUE);
                        scanf("%d", &j);
                        sprintf(out, "%s :  %d", out, j);
                        outtextxy(140, k, out);
                        k+=40;
                    }
                    settextstyle(3, 0, 4);
                    setcolor(RED);
                    outtextxy(450, 580, "Press  Esc  for back ...");
                    while(getch() != 27)
                    {
                    }
                    clearviewport();
                    setcolor(WHITE);
                    readimagefile(start, 100, 100, 600, 550);
                }
                else if(fy==(145+75+75+75))  // about
                {
                    clearviewport();
                    readimagefile(about, 650,80, 880, 315);
                    setcolor(CYAN);
                    settextstyle(3, 0, 4);
                    outtextxy(50, 80, "Mohammad Nur Uddin");
                    outtextxy(50, 115, "Dept :  Computer  Science ");
                    outtextxy(160, 150, " &  Engineering");
                    outtextxy(50, 185, "Reg : 2011331025");
                    outtextxy(50, 220, "CSE, 100 -  Project");
                    setcolor(CYAN);
                    outtextxy(50, 255, "Shahjalal  University");
                    outtextxy(180, 290, "of");
                    outtextxy(50, 325, "Science  &  Technology");

                    settextstyle(3, 0, 3);
                    setcolor(GREEN);
                    outtextxy(50, 420, "Language C++, ");
                    outtextxy(50, 460, "for graphics used  CS6,  Graphics.h");

                    settextstyle(3, 0, 4);
                    setcolor(RED);
                    outtextxy(450, 580, "Press  Esc  for back ...");
                    while(getch() != 27)
                    {
                    }
                    clearviewport();
                    setcolor(WHITE);
                    readimagefile(start, 100, 100, 600, 550);
                }
                else  // exit
                    return 0;
            }
        }
    }
}

int level1(void)
{
    int i, px, py, b1x, b1y, b2x, b2y, mx, my, x, y;
    char select, ch[30], *box = "level2.jpg", *dmnd= "diamond.bmp", *dmnd2="diamond2.bmp", *brd="bird b.jpg", *top="top.jpg";
    char *push="push.wav", *retry="retry.jpg";

    readimagefile(retry, 100, 550, 250, 600);

    readimagefile(box, 400, 150, 700, 500);
    readimagefile(dmnd, 500, 250, 550, 300);
    readimagefile(dmnd2, 550, 250, 600, 300);
    readimagefile(brd, 450, 250, 500, 300);
    settextstyle(1,0,5);
    setcolor(YELLOW);
    outtextxy(40, 200, "Move :0");
    px=450;
    py=250;
    b1x=500;
    b1y=250;
    b2x=550;
    b2y=250;
    while(1)
    {
        if(ismouseclick(WM_MOUSEMOVE))
        {
        getmouseclick(WM_MOUSEMOVE, x, y);
        if(x<=250&&x>=100 && y<=600&&y>=550)
        {
            readimagefile(retry, 95, 545, 255, 605);
        }
        else
        {
            readimagefile(retry, 100, 550, 250, 600);
        }
        }

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if(mx>=95&&mx<=255 && my>=545&&my<=605)
            {
                cleardevice();
                return 1;
            }
        }

        if(kbhit())
        {
            select = getch();
            sndPlaySound(push,SND_ASYNC);
            delay(10);
            //outtextxy(200,100, ch);

            if(select==72)    //press up
            {
                move1++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move1);
                outtextxy(240, 200, ch);
                if(px<=550)
                {
                    if(py==200)
                        continue;
                    else if(py==b1y+50&&px==b1x || py==b2y+50&&px==b2x)
                    {
                        if(py==b1y+50 && px==b1x)
                        {
                            if(b1y==200)
                                continue;
                            else if(b1y==b2y+50 && b1x==b2x)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py-=2,b1y-=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==200)
                                continue;
                            else if(b2y==b1y+50 && b2x==b1x)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py-=2,b2y-=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py-=2)
                        {
                            readimagefile(brd, px, py, px+50, py+50);
                        }
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else
                {
                    if(py==250)
                        continue;
                    else if(py==b1y+50&&px==b1x || py==b2y+50&&px==b2x)
                    {
                        if(py==b1y+50 && px==b1x)
                        {
                            if(b1y==250)
                                continue;
                            else if(b1y==b2y+50 && b1x==b2x)
                                continue;
                            else
                            {
                                if(py==400)
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b1y-=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 600, 400, 650, 450);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b1y-=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==250)
                                continue;
                            else if(b2y==b1y+50 && b2x==b1x)
                                continue;
                            else
                            {
                                if(py==400)
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b2y-=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 600, 400, 650, 450);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b2y-=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        if(py==400)
                        {
                            for(i=1 ; i<=50 ; i+=2,py-=2)
                            {
                                readimagefile(brd, px, py, px+50, py+50);
                            }
                            readimagefile(top, 600, 400, 650, 450);
                        }
                        else
                        {
                            for(i=1 ; i<=50 ; i+=2,py-=2)
                            {
                                readimagefile(brd, px, py, px+50, py+50);
                            }
                        }
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
            }

            else if(select==77)    //press right
            {
                move1++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move1);
                outtextxy(240, 200, ch);
                if(py==200)
                {
                    if(px==550)
                        continue;
                    else if(px+50==b1x&&py==b1y || px+50==b2x&&py==b2y)
                    {
                        if(px+50==b1x&&py==b1y)
                        {
                            if(b1x==550)
                                continue;
                            else if(b1x+50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                if(px==450)
                                {
                                    for(i=1 ; i<=50 ; i+=2,b1x+=2,px+=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 450, 200, 500, 250);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,b1x+=2,px+=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==550)
                                continue;
                            else if(b2x+50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                if(px==450)
                                {
                                    for(i=1 ; i<=50 ; i+=2,b2x+=2,px+=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 450, 200, 500, 250);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,b2x+=2,px+=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        if(px==450)
                        {
                            for(i=1 ; i<=50 ; i+=2,px+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 450, 200, 500, 250);
                        }
                        else
                            for(i=1 ; i<=50 ; i+=2,px+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else
                {
                    if(px==600)
                        continue;
                    else if(px+50==b1x&&py==b1y || px+50==b2x&&py==b2y)
                    {
                        if(px+50==b1x&&py==b1y)
                        {
                            if(b1x==600)
                                continue;
                            else if(b1x+50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b1x+=2,px+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==600)
                                continue;
                            else if(b2x+50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b2x+=2,px+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,px+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
            }
            else if(select==80)   //press down
            {
                move1++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move1);
                outtextxy(240, 200, ch);
                if(px==450)
                {
                    if(py==250)
                        continue;
                    else if(py==b1y-50&&px==b1x || py==b2y-50&&px==b2x)
                        continue;
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        readimagefile(top, 450, 200, 500, 250);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else if(px==500)
                {
                    if(py==300)
                        continue;
                    else if(py==b1y-50&&px==b1x || py==b2y-50&&px==b2x)
                    {
                        if(py==b1y-50&&px==b1x)
                        {
                            if(b1y==300)
                                continue;
                            else if(b1x==b2x&&b1y+50==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b1y+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==300)
                                continue;
                            else if(b1x==b2x&&b2y+50==b1y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b2y+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else if(px==550)
                {
                    if(py==350)
                        continue;
                    else if(py==b1y-50&&px==b1x || py==b2y-50&&px==b2x)
                    {
                        if(py==b1y-50&&px==b1x)
                        {
                            if(b1y==350)
                                continue;
                            else if(b1x==b2x&&b1y+50==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b1y+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==350)
                                continue;
                            else if(b1x==b2x&&b2y+50==b1y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b2y+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else
                {
                    if(py==400)
                        continue;
                    else if(py==b1y-50&&px==b1x || py==b2y-50&&px==b2x)
                    {
                        if(py==b1y-50&&px==b1x)
                        {
                            if(b1y==400)
                                continue;
                            else if(b1x==b2x&&b1y+50==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b1y+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==400)
                                continue;
                            else if(b1x==b2x&&b2y+50==b1y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b2y+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
            }
            else if(select==75)    //press left
            {
                move1++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move1);
                outtextxy(240, 200, ch);
                if(py==400)
                    continue;
                else if(py<=250)
                {
                    if(px==450)
                        continue;
                    else if(px-50==b1x&&py==b1y || px-50==b2x&&py==b2y)
                    {
                        if(px-50==b1x&&py==b1y)
                        {
                            if(b1x==450)
                                continue;
                            else if(b1x-50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b1x-=2,px-=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==450)
                                continue;
                            else if(b2x-50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b2x-=2,px-=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,px-=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else if(py==300)
                {
                    if(px==500)
                        continue;
                    else if(px-50==b1x&&py==b1y || px-50==b2x&&py==b2y)
                    {
                        if(px-50==b1x&&py==b1y)
                        {
                            if(b1x==500)
                                continue;
                            else if(b1x-50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b1x-=2,px-=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==500)
                                continue;
                            else if(b2x-50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b2x-=2,px-=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,px-=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
                else
                {
                    if(px==550)
                        continue;
                    else if(px-50==b1x&&py==b1y || px-50==b2x&&py==b2y)
                        continue;
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,px-=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==450&&b1y==200&&b2x==600&&b2y==400 || b2x==450&&b2y==200&&b1x==600&&b1y==400)
                            break;
                    }
                }
            }
        }
    }
    return 0;
}

int level2(void)
{
    //initwindow(900, 650, "Gaming Zone");
    int plgn[] = {525,300, 550,325, 525,350, 500,325, 525,300};
    int i, px, py, b1x, b1y, b2x, b2y, mx, my, x, y;
    char select, *push="push.wav", *retry="retry.jpg", ch[40];
    setcolor(LIGHTBLUE);

    setfillstyle(2, 13);

    readimagefile(retry, 100, 550, 250, 600);

    bar(400, 150, 600, 200);
    bar(550, 200, 600, 300);
    bar(600, 250, 700, 300);
    bar(650, 300, 700, 450);
    bar(550, 400, 650, 450);
    bar(400, 450, 600, 500);
    bar(400, 200, 450, 450);


    for(i=2 ; i<=20; i++)
        circle(525, 225, i);
    for(i=2 ; i<=20; i++)
        circle(475, 325, i);
    setfillstyle(1, 10);
    bar(450, 300, 500, 350);
    bar(550, 350, 600, 400);

    b1x = 450;
    b1y = 300;
    b2x = 550;
    b2y = 350;
    px = 525;
    py = 300;

    setcolor(BLACK);
    setfillstyle(1, WHITE);
    fillpoly(5, plgn);

    settextstyle(1,0,5);
    setcolor(YELLOW);
    outtextxy(40, 200, "Move :0");

    while(1)
    {
        if(ismouseclick(WM_MOUSEMOVE))
        {
        getmouseclick(WM_MOUSEMOVE, x, y);
        if(x<=250&&x>=100 && y<=600&&y>=550)
        {
            readimagefile(retry, 95, 545, 255, 605);
        }
        else
        {
            readimagefile(retry, 100, 550, 250, 600);
        }
        }

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if(mx>=95&&mx<=255 && my>=545&&my<=605)
            {
                cleardevice();
                return 1;
            }
        }

        if(kbhit())
        {
            select = getch();
            sndPlaySound(push,SND_ASYNC);
            delay(10);
            if(select==77)  //press right
            {
                move2++;
                setcolor(YELLOW);
                settextstyle(1,0,5);
                sprintf(ch, "%d", move2);
                outtextxy(240, 200, ch);
                setcolor(BLACK);

                if(py<300 || py>=400)
                {
                    if(px==525)
                        continue;
                    else
                    {
                        if(px+25==b1x&&py==b1y || px+25==b2x&&py==b2y)
                            continue;
                        else
                        {
                            setfillstyle(1, BLACK);
                            plgn[0]=px;
                            plgn[1]=py;
                            plgn[2]=px+25;
                            plgn[3]=py+25;
                            plgn[4]=px;
                            plgn[5]=py+50;
                            plgn[6]=px-25;
                            plgn[7]=py+25;
                            plgn[8]=px;
                            plgn[9]=py;
                            fillpoly(5, plgn);

                            setfillstyle(1, WHITE);
                            px += 50;
                            plgn[0]=px;
                            plgn[1]=py;
                            plgn[2]=px+25;
                            plgn[3]=py+25;
                            plgn[4]=px;
                            plgn[5]=py+50;
                            plgn[6]=px-25;
                            plgn[7]=py+25;
                            plgn[8]=px;
                            plgn[9]=py;
                            fillpoly(5, plgn);
                            if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                break;
                        }
                    }
                }
                else
                {
                    if(px+25==650)
                        continue;
                    else if(px+25==b1x&&py==b1y || px+25==b2x&&py==b2y)
                    {
                        if(px+25==b1x && py==b1y)
                        {
                            if(b1x+50>=650)
                                continue;
                            else if(b1x+50==b2x)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b1x, b1y, b1x+50, b1y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b1x += 50;
                                bar(b1x, b1y, b1x+50, b1y+50);

                                if(px==475 && py==300)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(475, 325, i);
                                    setcolor(BLACK);
                                }

                                setfillstyle(1, WHITE);
                                px += 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                        else if(px+25==b2x && py==b2y)
                        {
                            if(b2x+50>=650)
                                continue;
                            else if(b2x+50==b1x)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b2x, b2y, b2x+50, b2y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b2x += 50;
                                bar(b2x, b2y, b2x+50, b2y+50);

                                if(px==475 && py==300)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(475, 325, i);
                                    setcolor(BLACK);
                                }

                                setfillstyle(1, WHITE);
                                px += 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        setfillstyle(1, BLACK);
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);

                        if(px==475 && py==300)
                        {
                            setcolor(LIGHTBLUE);
                            for(i=2 ; i<=20; i++)
                                circle(475, 325, i);
                            setcolor(BLACK);
                        }

                        setfillstyle(1, WHITE);
                        px += 50;
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);
                        if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                            break;
                    }
                }
            }
            else if(select==75)   //press left
            {
                move2++;
                setcolor(YELLOW);
                settextstyle(1,0,5);
                sprintf(ch, "%d", move2);
                outtextxy(240, 200, ch);
                setcolor(BLACK);
                if(px==475)
                    continue;
                else
                {
                    if(px-25==b1x+50&&py==b1y || px-25==b2x+50&&py==b2y)
                    {
                        if(px-25==b1x+50 && py==b1y)
                        {
                            if(b1x==450)
                                continue;
                            else if(b2x+50==b1x && b1y==b2y)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b1x, b1y, b1x+50, b1y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b1x -= 50;
                                bar(b1x, b1y, b1x+50, b1y+50);

                                setfillstyle(1, WHITE);
                                px -= 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==450)
                                continue;
                            else if(b1x+50 == b2x && b1y==b2y)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b2x, b2y, b2x+50, b2y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b2x -= 50;
                                bar(b2x, b2y, b2x+50, b2y+50);

                                setfillstyle(1, WHITE);
                                px -= 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        setfillstyle(1, BLACK);
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);

                        if(px==525 && py==200)
                        {
                            setcolor(LIGHTBLUE);
                            for(i=2 ; i<=20; i++)
                                circle(525, 225, i);
                            setcolor(BLACK);
                        }

                        setfillstyle(1, WHITE);
                        px -= 50;
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);
                        if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                            break;
                    }
                }
            }
            else if(select==72)  //press up
            {
                move2++;
                setcolor(YELLOW);
                settextstyle(1,0,5);
                sprintf(ch, "%d", move2);
                outtextxy(240, 200, ch);
                setcolor(BLACK);
                if(py>=300 && py<400 && px>=550)
                {
                    if(py==300)
                        continue;
                    else if(py==b1y+50&&px-25==b1x || py==b2y+50&&px-25==b2x)
                        continue;
                    else
                    {
                        setfillstyle(1, BLACK);
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);

                        setfillstyle(1, WHITE);
                        py -= 50;
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);
                        if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                            break;
                    }
                }
                else
                {
                    if(py==200)
                        continue;
                    else if(py==b1y+50&&px-25==b1x || py==b2y+50&&px-25==b2x)
                    {
                        if(py==b1y+50&&px-25==b1x)
                        {
                            if(b1y==200)
                                continue;
                            else if(b1y==b2y+50 && b1x==b2x)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b1x, b1y, b1x+50, b1y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b1y -= 50;
                                bar(b1x, b1y, b1x+50, b1y+50);

                                if(px==475 && py==300 || px==475 && py==350)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(475, 325, i);
                                    setcolor(BLACK);
                                }

                                setfillstyle(1, WHITE);
                                py -= 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==200)
                                continue;
                            else if(b2y==b1y+50 && b2x==b1x)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b2x, b2y, b2x+50, b2y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b2y -= 50;
                                bar(b2x, b2y, b2x+50, b2y+50);

                                if(px==475 && py==300 || px==475 && py==350)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(475, 325, i);
                                    setcolor(BLACK);
                                }

                                setfillstyle(1, WHITE);
                                py -= 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        setfillstyle(1, BLACK);
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);

                        if(px==475 && py==300 || px==475 && py==350)
                        {
                            setcolor(LIGHTBLUE);
                            for(i=2 ; i<=20; i++)
                                circle(475, 325, i);
                            setcolor(BLACK);
                        }

                        setfillstyle(1, WHITE);
                        py -= 50;
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);
                        if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                            break;
                    }
                }
            }

            else if(select==80)   //press down
            {
                move2++;
                setcolor(YELLOW);
                settextstyle(1,0,5);
                sprintf(ch, "%d", move2);
                outtextxy(240, 200, ch);
                setcolor(BLACK);
                if(py>=300 && py<400 && px>=550)
                {
                    if(py==350)
                        continue;
                    else
                    {
                        if(py+50==b1y&&px-25==b1x || py+50==b2y&&px-25==b2x)
                            continue;
                        else
                        {
                            setfillstyle(1, BLACK);
                            plgn[0]=px;
                            plgn[1]=py;
                            plgn[2]=px+25;
                            plgn[3]=py+25;
                            plgn[4]=px;
                            plgn[5]=py+50;
                            plgn[6]=px-25;
                            plgn[7]=py+25;
                            plgn[8]=px;
                            plgn[9]=py;
                            fillpoly(5, plgn);

                            setfillstyle(1, WHITE);
                            py += 50;
                            plgn[0]=px;
                            plgn[1]=py;
                            plgn[2]=px+25;
                            plgn[3]=py+25;
                            plgn[4]=px;
                            plgn[5]=py+50;
                            plgn[6]=px-25;
                            plgn[7]=py+25;
                            plgn[8]=px;
                            plgn[9]=py;
                            fillpoly(5, plgn);
                            if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                break;
                        }
                    }
                }
                else
                {
                    if(py==400)
                        continue;
                    else if(py+50==b1y&&px-25==b1x || py+50==b2y&&px-25==b2x)
                    {
                        if(py+50==b1y && px-25==b1x)
                        {
                            if(b1y==400)
                                continue;
                            else if(b1y+50==b2y && b1x==b2x)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b1x, b1y, b1x+50, b1y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b1y += 50;
                                bar(b1x, b1y, b1x+50, b1y+50);

                                if(px==525 && py==200)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(525, 225, i);
                                    setcolor(BLACK);
                                }
                                else if(px==475 && py==300 || px==475 && py==250)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(475, 325, i);
                                    setcolor(BLACK);
                                }

                                setfillstyle(1, WHITE);
                                py += 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==400)
                                continue;
                            else if(b2y+50==b1y && b2x==b1x)
                                continue;
                            else
                            {
                                setfillstyle(1, BLACK);
                                bar(b2x, b2y, b2x+50, b2y+50);
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);

                                setfillstyle(1, 10);
                                b2y += 50;
                                bar(b2x, b2y, b2x+50, b2y+50);

                                if(px==525 && py==200)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(525, 225, i);
                                    setcolor(BLACK);
                                }
                                else if(px==475 && py==300 || px==475 && py==250)
                                {
                                    setcolor(LIGHTBLUE);
                                    for(i=2 ; i<=20; i++)
                                        circle(475, 325, i);
                                    setcolor(BLACK);
                                }

                                setfillstyle(1, WHITE);
                                py += 50;
                                plgn[0]=px;
                                plgn[1]=py;
                                plgn[2]=px+25;
                                plgn[3]=py+25;
                                plgn[4]=px;
                                plgn[5]=py+50;
                                plgn[6]=px-25;
                                plgn[7]=py+25;
                                plgn[8]=px;
                                plgn[9]=py;
                                fillpoly(5, plgn);
                                if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        setfillstyle(1, BLACK);
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);

                        if(px==525 && py==200)
                        {
                            setcolor(LIGHTBLUE);
                            for(i=2 ; i<=20; i++)
                                circle(525, 225, i);
                            setcolor(BLACK);
                        }
                        else if(px==475 && py==300 || px==475 && py==250)
                        {
                            setcolor(LIGHTBLUE);
                            for(i=2 ; i<=20; i++)
                                circle(475, 325, i);
                            setcolor(BLACK);
                        }

                        setfillstyle(1, WHITE);
                        py += 50;
                        plgn[0]=px;
                        plgn[1]=py;
                        plgn[2]=px+25;
                        plgn[3]=py+25;
                        plgn[4]=px;
                        plgn[5]=py+50;
                        plgn[6]=px-25;
                        plgn[7]=py+25;
                        plgn[8]=px;
                        plgn[9]=py;
                        fillpoly(5, plgn);
                        if(b1x==450&&b1y==300 && b2x==500&&b2y==200 || b2x==450&&b2y==300 && b1x==500&&b1y==200)
                            break;
                    }
                }
            }
        }
    }
    return 0;
}

int level3(void)
{
    int i, px, py, b1x, b1y, b2x, b2y, mx, my, x, y;
    char select, *dmnd= "diamond.bmp", *dmnd2="diamond2.bmp", *brd="bird b.jpg", *top="top.jpg";
    char *box2 = "level3.jpg", *push="push.wav", *retry="retry.jpg", ch[40];

    readimagefile(retry, 100, 550, 250, 600);

    readimagefile(box2, 400, 150, 750, 500);
    readimagefile(brd, 500, 250, 550, 300);
    readimagefile(dmnd, 500, 300, 550, 350);
    readimagefile(dmnd2, 550, 300, 600, 350);
    px=500;
    py=250;
    b1x=500;
    b1y=300;
    b2x=550;
    b2y=300;

    settextstyle(1,0,5);
    setcolor(YELLOW);
    outtextxy(40, 200, "Move :0");

    while(1)
    {
        if(ismouseclick(WM_MOUSEMOVE))
        {
        getmouseclick(WM_MOUSEMOVE, x, y);
        if(x<=250&&x>=100 && y<=600&&y>=550)
        {
            readimagefile(retry, 95, 545, 255, 605);
        }
        else
        {
            readimagefile(retry, 100, 550, 250, 600);
        }
        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if(mx>=95&&mx<=255 && my>=545&&my<=605)
            {
                cleardevice();
                return 1;
            }
        }

        if(kbhit())
        {
            select = getch();
            sndPlaySound(push,SND_ASYNC);
            delay(10);
            if(select==72)   //press up
            {
                move3++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move3);
                outtextxy(240, 200, ch);
                if(px<=550)
                {
                    if(py==200)
                        continue;
                    else if(py==b1y+50&&px==b1x || py==b2y+50&&px==b2x)
                    {
                        if(py==b1y+50 && px==b1x)
                        {
                            if(b1y==200)
                                continue;
                            else if(b1y==b2y+50 && b1x==b2x)
                                continue;
                            else
                            {
                                if(px==500 && py==350)
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b1y-=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 500, 350, 550, 400);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b1y-=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==200)
                                continue;
                            else if(b2y==b1y+50 && b2x==b1x)
                                continue;
                            else
                            {
                                if(px==500 && py==350)
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b2y-=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 500, 350, 550, 400);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,py-=2,b2y-=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        if(px==500 && py==350)
                        {
                            for(i=1 ; i<=50 ; i+=2,py-=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 500, 350, 550, 400);
                        }
                        else
                        {
                            for(i=1 ; i<=50 ; i+=2,py-=2)
                                readimagefile(brd, px, py, px+50, py+50);
                        }
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
                else
                {
                    if(py==350)
                        continue;
                    else if(py==b1y+50&&px==b1x || py==b2y+50&&px==b2x)
                        continue;
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py-=2)
                        {
                            readimagefile(brd, px, py, px+50, py+50);
                        }
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
            }
            else if(select==77)   //press right
            {
                move3++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move3);
                outtextxy(240, 200, ch);
                if(py<=300)
                {
                    if(px==550)
                        continue;
                    else if(px+50==b1x&&py==b1y || px+50==b2x&&py==b2y)
                    {
                        if(px+50==b1x&&py==b1y)
                        {
                            if(b1x==550)
                                continue;
                            else if(b1x+50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b1x+=2,px+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==550)
                                continue;
                            else if(b2x+50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b2x+=2,px+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,px+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
                else
                {
                    if(px==650)
                        continue;
                    else if(px+50==b1x&&py==b1y || px+50==b2x&&py==b2y)
                    {
                        if(px+50==b1x&&py==b1y)
                        {
                            if(b1x==650)
                                continue;
                            else if(b1x+50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                if(px==500 && py==350)
                                {
                                    for(i=1 ; i<=50 ; i+=2,b1x+=2,px+=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 500, 350, 550, 400);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,b1x+=2,px+=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==650)
                                continue;
                            else if(b2x+50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                if(px==500 && py==350)
                                {
                                    for(i=1 ; i<=50 ; i+=2,b2x+=2,px+=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 500, 350, 550, 400);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,b2x+=2,px+=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        if(px==500 && py==350)
                        {
                            for(i=1 ; i<=50 ; i+=2,px+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 500, 350, 550, 400);
                        }
                        else if(px==600 && py==350)
                        {
                            for(i=1 ; i<=50 ; i+=2,px+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 600, 350, 650, 400);
                        }
                        else
                        {
                            for(i=1 ; i<=50 ; i+=2,px+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                        }
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
            }
            else if(select==80)   //press down
            {
                move3++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move3);
                outtextxy(240, 200, ch);
                if(px==450)
                {
                    if(py==300)
                        continue;
                    else if(py==b1y-50&&px==b1x || py==b2y-50&&px==b2x)
                    {
                        if(py==b1y-50&&px==b1x)
                        {
                            if(b1y==300)
                                continue;
                            else if(b1x==b2x&&b1y+50==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b1y+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==300)
                                continue;
                            else if(b1x==b2x&&b2y+50==b1y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b2y+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,py+=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
                else
                {
                    if(py==400)
                        continue;
                    else if(py==b1y-50&&px==b1x || py==b2y-50&&px==b2x)
                    {
                        if(py==b1y-50&&px==b1x)
                        {
                            if(b1y==400)
                                continue;
                            else if(b1x==b2x&&b1y+50==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b1y+=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2y==400)
                                continue;
                            else if(b1x==b2x&&b2y+50==b1y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,py+=2,b2y+=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        if(px==500 && py==350)
                        {
                            for(i=1 ; i<=50 ; i+=2,py+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 500, 350, 550, 400);
                        }
                        else if(px==600 && py==350)
                        {
                            for(i=1 ; i<=50 ; i+=2,py+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 600, 350, 650, 400);
                        }
                        else
                        {
                            for(i=1 ; i<=50 ; i+=2,py+=2)
                                readimagefile(brd, px, py, px+50, py+50);
                        }
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
            }
            else if(select==75)    //press left
            {
                move3++;
                settextstyle(1,0,5);
                sprintf(ch, "%d", move3);
                outtextxy(240, 200, ch);
                if(py<=300)
                {
                    if(px==450)
                        continue;
                    else if(px-50==b1x&&py==b1y || px-50==b2x&&py==b2y)
                    {
                        if(px-50==b1x&&py==b1y)
                        {
                            if(b1x==450)
                                continue;
                            else if(b1x-50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b1x-=2,px-=2)
                                {
                                    readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==450)
                                continue;
                            else if(b2x-50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                for(i=1 ; i<=50 ; i+=2,b2x-=2,px-=2)
                                {
                                    readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                    readimagefile(brd, px, py, px+50, py+50);
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        for(i=1 ; i<=50 ; i+=2,px-=2)
                            readimagefile(brd, px, py, px+50, py+50);
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
                else
                {
                    if(px==500)
                        continue;
                    else if(px-50==b1x&&py==b1y || px-50==b2x&&py==b2y)
                    {
                        if(px-50==b1x&&py==b1y)
                        {
                            if(b1x==500)
                                continue;
                            else if(b1x-50==b2x&&b1y==b2y)
                                continue;
                            else
                            {
                                if(px==600 && py==350)
                                {
                                    for(i=1 ; i<=50 ; i+=2,b1x-=2,px-=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 600, 350, 650, 400);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,b1x-=2,px-=2)
                                    {
                                        readimagefile(dmnd, b1x, b1y, b1x+50, b1y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                        else
                        {
                            if(b2x==500)
                                continue;
                            else if(b2x-50==b1x&&b1y==b2y)
                                continue;
                            else
                            {
                                if(px==600 && py==350)
                                {
                                    for(i=1 ; i<=50 ; i+=2,b2x-=2,px-=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                    readimagefile(top, 600, 350, 650, 400);
                                }
                                else
                                {
                                    for(i=1 ; i<=50 ; i+=2,b2x-=2,px-=2)
                                    {
                                        readimagefile(dmnd2, b2x, b2y, b2x+50, b2y+50);
                                        readimagefile(brd, px, py, px+50, py+50);
                                    }
                                }
                                if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                                    break;
                            }
                        }
                    }
                    else
                    {
                        if(px==600 && py==350)
                        {
                            for(i=1 ; i<=50 ; i+=2,px-=2)
                                readimagefile(brd, px, py, px+50, py+50);
                            readimagefile(top, 600, 350, 650, 400);
                        }
                        else
                        {
                            for(i=1 ; i<=50 ; i+=2,px-=2)
                                readimagefile(brd, px, py, px+50, py+50);
                        }
                        if(b1x==500&&b1y==350&&b2x==600&&b2y==350 || b2x==500&&b2y==350&&b1x==600&&b1y==350)
                            break;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    initwindow(900, 650, "Gaming Zone");

    int bkclr, i, j, flag=1, score, ot[20];
    char nam[30], out[20][30], temp[30];

    setcolor(LIGHTBLUE);
    i = starting();
    if(i==0)
        return 0;
    clearviewport();

    while(flag)
    {
        flag = level1();
    }
    flag = 1;

    delay(200);
    cleardevice();
    setcolor(LIGHTCYAN);
    settextstyle(4, 0, 6);
    outtextxy(200, 200, " LEVEL ");
    outtextxy(100, 300, "COMPLETE   *_*");

    setcolor(LIGHTGREEN);
    settextstyle(1, 0, 3);
    outtextxy(350, 550, "Press Enter For Next Level...");
    while(getch() != 13)
    {
    }
    cleardevice();

    while(flag)
    {
        flag = level2();
    }
    flag = 1;

    delay(200);
    cleardevice();
    setcolor(LIGHTCYAN);
    settextstyle(4, 0, 6);
    outtextxy(200, 200, " LEVEL ");
    outtextxy(100, 300, "COMPLETE   *_*");

    setcolor(LIGHTGREEN);
    settextstyle(1, 0, 3);
    outtextxy(350, 550, "Press Enter For Next Level...");
    while(getch() != 13)
    {
    }
    cleardevice();

    while(flag)
    {
        flag = level3();
    }

    score = move1+move2+move3;
    clearviewport();
    settextstyle(4, 0, 4);
    outtextxy(200, 200, "Enter Your Name: ");
    i=0;
    while(1)
    {
        temp[i] = getch();
        if(temp[i]==13)
            break;
        temp[i+1] = '\0';
        outtextxy(450, 300, temp);
        nam[i] = temp[i];
        i++;
    }
    nam[i] = '\0';
    i=0;
    freopen("Score.txt", "r", stdin);

    while(scanf("%s", out[i])!=EOF)
    {
        scanf("%d", &ot[i]);
        i++;
    }
    freopen("Score.txt", "w", stdout);
    for(j=i-1 ; j>=0 ; j--)
    {
        if(score<ot[j])
        {
            ot[j+1] = ot[j];
            strcpy(out[j+1], out[j]);
        }
        else
        {
            strcpy(out[j+1], nam);
            ot[j+1] = score;
            break;
        }
    }
    if(i==0)
    {
        strcpy(out[0], nam);
        ot[0] = score;
        printf("%s %d\n", out[0], ot[0]);
    }
    else if(i<10)
    {
        for(j=0 ; j<=i ; j++)
            printf("%s %d\n", out[j], ot[j]);
    }
    else
    {
        for(i=0 ; i<10 ; i++)
            printf("%s %d\n", out[i], ot[i]);
    }
    setcolor(11);

    delay(200);
    cleardevice();
    setcolor(LIGHTCYAN);
    settextstyle(4, 0, 6);
    outtextxy(200, 200, "  GAME");
    outtextxy(100, 300, "COMPLETE   *_*");

    setcolor(LIGHTGREEN);
    settextstyle(1, 0, 3);
    outtextxy(450, 550, "Press Esc to exit...");
    while(getch() != 27)
    {
    }
    closegraph();
    return 0;
}
