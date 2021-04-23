


/** 
* @file backgrounf.c 
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include "background.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    //On blitte la surface
    SDL_BlitSurface( source, clip, destination, &offset );
    SDL_Flip(destination);   
}

void scrolling(SDL_Rect *camera_pos, int d )
{
    if (d == 1) //Direction Bas
    {
        camera_pos->y -= 5;
    }
    else if (d == 2) //Direction Haut
    {
        camera_pos->y += 5; 
    }
    else if (d == 3) //Direction vers le droite
    {
        camera_pos->x += 5;
    }
    else if (d == 4) //Direction à gauche
    {
        camera_pos->x -= 5;
    }
}

/*void Init_All_Objs(GO *GOS)
{

	GOS->SP1=IMG_Load("Objects/spikes/1.png");
	GOS->SP2=IMG_Load("Objects/spikes/2.png");
	GOS->SP3=IMG_Load("Objects/spikes/3.png");
	GOS->SP4=IMG_Load("Objects/spikes/4.png");
	GOS->GR1=IMG_Load("Objects/GR_E/1.png");
	GOS->RS1=IMG_Load("Objects/rsrs/1.png");
	GOS->RS2=IMG_Load("Objects/rsrs/2.png");
	GOS->RS3=IMG_Load("Objects/rsrs/3.png");
	GOS->ch=IMG_Load("Objects/spikes/4.png");
	GOS->RG=IMG_Load("Objects/Ring/1.png");


	GOS->SP_1.x= 1619;
	GOS->SP_1.y= 539;
	GOS->SP_2.x= 2418;
	GOS->SP_2.y= 543;
	GOS->SP_3.x= 3206;
	GOS->SP_3.y= 537;
	GOS->SP_4.x= 5437;
	GOS->SP_4.y= 546;
	GOS->GR1_P1.x= 7134;
	GOS->GR1_P1.y= 504;
	GOS->GR1_P2.x= 7590;
	GOS->GR1_P2.y= 502;
	GOS->GR1_P3.x= 8133;
	GOS->GR1_P3.y= 504;
	GOS->GR1_P4.x= 8545;
	GOS->GR1_P4.y= 504;
	GOS->RS_1.x= 8855;
	GOS->RS_1.y= 491;
	GOS->RS_2.x= 8978;
	GOS->RS_2.y = 491;
	GOS->RS_3.x= 9389;
	GOS->RS_3.y= 483;
	GOS->ch1_P1.x= 9096;
	GOS->ch1_P1.y= 269;
	GOS->ch1_P2.x= 9321;
	GOS->ch1_P2.y= 269;
	GOS->RG1.x= 9532;
	GOS->RG1.y= 492;



}*/



void Init_BG(BGS *BG)
{
	BG->Background=IMG_Load("background1.png");
	BG->BGP.x=0;
	BG->BGP.y=0;
}

void Display_BG(BGS *BG,SDL_Surface *Screen)
{
	SDL_Rect Rep;

	Rep=BG->BGP;
	SDL_BlitSurface(BG->Background,NULL,Screen,&Rep);
}

/*void Display_All_Game_Objects(GO *GOS, SDL_Surface *Screen)
{
SDL_Rect Rep1,Rep2,Rep3,Rep4,Rep5,Rep6,Rep7,Rep8,Rep9,Rep10,Rep11,Rep12,Rep13,Rep14;
	Rep1=GOS->SP_1;
	Rep2=GOS->SP_2;
	Rep3=GOS->SP_3;
	Rep4=GOS->SP_4;
	Rep5=GOS->GR1_P1;
	Rep6=GOS->GR1_P2;
	Rep7=GOS->GR1_P3;
	Rep8=GOS->GR1_P4;
	Rep9=GOS->RS_1;
	Rep10=GOS->RS_2;
	Rep11=GOS->RS_3;
	Rep12=GOS->ch1_P1;
	Rep13=GOS->ch1_P2;
	Rep14=GOS->RG1;

	SDL_BlitSurface(GOS->SP1,NULL,Screen,&Rep1);
	SDL_BlitSurface(GOS->SP2,NULL,Screen,&Rep2);
	SDL_BlitSurface(GOS->SP3,NULL,Screen,&Rep3);
	SDL_BlitSurface(GOS->SP4,NULL,Screen,&Rep4);
	SDL_BlitSurface(GOS->GR1,NULL,Screen,&Rep5);
	SDL_BlitSurface(GOS->GR1,NULL,Screen,&Rep6);
	SDL_BlitSurface(GOS->GR1,NULL,Screen,&Rep7);
	SDL_BlitSurface(GOS->GR1,NULL,Screen,&Rep8);
	SDL_BlitSurface(GOS->RS1,NULL,Screen,&Rep9);
	SDL_BlitSurface(GOS->RS2,NULL,Screen,&Rep10);
	SDL_BlitSurface(GOS->RS3,NULL,Screen,&Rep11);
	SDL_BlitSurface(GOS->ch,NULL,Screen,&Rep12);
	SDL_BlitSurface(GOS->ch,NULL,Screen,&Rep13);
	SDL_BlitSurface(GOS->RG,NULL,Screen,&Rep14);




}

*/


void freegame(BGS *BG)
{
SDL_FreeSurface(BG->Background);
}
