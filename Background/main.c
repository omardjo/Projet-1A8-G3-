/** 
* @file main.c 
* @brief Testing Program. 
* @author omar
* @version 0.1 
* @date Apr 23, 2021
* 
* Testing program for background * 
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "background.h"

const int SHEET_WIDTH = 800;
const int SHEET_HEIGHT = 600;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;


int main(int argc, char *argv[])
{
    //GO *GOS;
    BGS *BG;
    SDL_Rect clip;
    SDL_Surface *ecran = NULL,*sprite=NULL;
    Mix_Music *music;
    SDL_Event event;
    int continuer = 1,spritex =0 , spritey=0, direction,bgx=0,bgy=0;/*,obx=0,oby=0;*/
    
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(600,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /* Double Buffering */

   // GOS=malloc(sizeof(GO));
    BG=malloc(sizeof(BGS));
    Init_BG(BG);
    //Init_All_Objs(GOS);	
    SDL_WM_SetCaption("jeu", NULL);
    sprite =IMG_Load("Maps/map.png");;
    clip.x =800 ;
    clip.y =600;//9600;
    clip.w = SHEET_WIDTH;
    clip.h = SHEET_HEIGHT;
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    printf("%s",Mix_GetError());
    music=Mix_LoadMUS("MotivationalMusic.mp3");
       Mix_PlayMusic(music,-1);
       //SDL_Flip(ecran);

    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */

SDL_BlitSurface(BG->Background,NULL,ecran,&BG->BGP);
//Display_BG(BG,ecran);
//Display_All_Game_Objects(GOS,ecran);
SDL_Flip(ecran);

    while (continuer)
    {     
        SDL_WaitEvent(&event);
        switch(event.type)
        { 
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: 
                        {
                        direction = 1; //Haut
                        clip.y=clip.y+10;   
scrolling(&BG->BGP,direction);
apply_surface(bgx , bgy,sprite, ecran, &BG->BGP );
/*scrolling(&GOS->SP_1,direction);
scrolling(&GOS->SP_2,direction);
scrolling(&GOS->SP_3,direction);
scrolling(&GOS->SP_4,direction);
scrolling(&GOS->GR1_P1,direction);
scrolling(&GOS->GR1_P2,direction);
scrolling(&GOS->GR1_P3,direction);
scrolling(&GOS->GR1_P4,direction);
scrolling(&GOS->RS_1,direction);
scrolling(&GOS->RS_2,direction);
scrolling(&GOS->RS_3,direction);
scrolling(&GOS->ch1_P1,direction);
scrolling(&GOS->ch1_P2,direction);
scrolling(&GOS->RG1,direction); 
                               
apply_surface(bgx , bgy,sprite, ecran, &BG->BGP );
//apply_surface(spritex ,spritey,sprite,ecran,&clip);
/*apply_surface(obx, oby,sprite, ecran, &GOS->SP_1 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_2 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_4 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P3 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P4 );
apply_surface(obx, oby,sprite, ecran, &GOS->RS_1 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_2 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->RG1 );	
apply_surface(spritex ,spritey,sprite,ecran,&clip); 
//Display_All_Game_Objects(GOS,ecran);
*/

                        break;
                        }                        
                    case SDLK_DOWN:
					    { 
                        direction = 2;//Bas
                         clip.y=clip.y-10; 
scrolling(&BG->BGP,direction);
apply_surface(bgx , bgy,sprite, ecran, &BG->BGP );
/*scrolling(&GOS->SP_1,direction);
scrolling(&GOS->SP_2,direction);
scrolling(&GOS->SP_3,direction);
scrolling(&GOS->SP_4,direction);
scrolling(&GOS->GR1_P1,direction);
scrolling(&GOS->GR1_P2,direction);
scrolling(&GOS->GR1_P3,direction);
scrolling(&GOS->GR1_P4,direction);
scrolling(&GOS->RS_1,direction);
scrolling(&GOS->RS_2,direction);
scrolling(&GOS->RS_3,direction);
scrolling(&GOS->ch1_P1,direction);
scrolling(&GOS->ch1_P2,direction);
scrolling(&BG->BGP,direction);   
*/         ;
//apply_surface(spritex ,spritey,sprite,ecran,&clip);
/*apply_surface(obx, oby,sprite, ecran, &GOS->SP_1 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_2 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_4 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P3 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P4 );
apply_surface(obx, oby,sprite, ecran, &GOS->RS_1 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_2 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->RG1 );
apply_surface(spritex ,spritey,sprite,ecran,&clip);
*/ 
//Display_All_Game_Objects(GOS,ecran);
			
                      break; }
                        
                    case SDLK_RIGHT:
					    {
                       direction = 3;//Droite
                       clip.x=clip.x+10; 
scrolling(&BG->BGP,direction);
apply_surface(bgx , bgy,sprite, ecran, &BG->BGP );
/*scrolling(&GOS->SP_1,direction);
scrolling(&GOS->SP_2,direction);
scrolling(&GOS->SP_3,direction);
scrolling(&GOS->SP_4,direction);
scrolling(&GOS->GR1_P1,direction);
scrolling(&GOS->GR1_P2,direction);
scrolling(&GOS->GR1_P3,direction);
scrolling(&GOS->GR1_P4,direction);
scrolling(&GOS->RS_1,direction);
scrolling(&GOS->RS_2,direction);
scrolling(&GOS->RS_3,direction);
scrolling(&GOS->ch1_P1,direction);
scrolling(&GOS->ch1_P2,direction);
scrolling(&GOS->RG1,direction);   */       
//apply_surface(spritex ,spritey,sprite,ecran,&clip);
/*apply_surface(obx, oby,sprite, ecran, &GOS->SP_1 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_2 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_4 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P3 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P4 );
apply_surface(obx, oby,sprite, ecran, &GOS->RS_1 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_2 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->RG1 );
apply_surface(spritex ,spritey,sprite,ecran,&clip);
//Display_All_Game_Objects(GOS,ecran);
*/
                        break;
						} 
                    case SDLK_LEFT:
					   {
                        direction = 4;//Gauche
                        clip.x=clip.x-10;
scrolling(&BG->BGP,direction);
apply_surface(bgx , bgy,sprite, ecran, &BG->BGP );
/*scrolling(&GOS->SP_1,direction);
scrolling(&GOS->SP_2,direction);
scrolling(&GOS->SP_3,direction);
scrolling(&GOS->SP_4,direction);
scrolling(&GOS->GR1_P1,direction);
scrolling(&GOS->GR1_P2,direction);
scrolling(&GOS->GR1_P3,direction);
scrolling(&GOS->GR1_P4,direction);
scrolling(&GOS->RS_1,direction);
scrolling(&GOS->RS_2,direction);
scrolling(&GOS->RS_3,direction);
scrolling(&GOS->ch1_P1,direction);
scrolling(&GOS->ch1_P2,direction);
scrolling(&GOS->RG1,direction);
*/
//apply_surface(spritex ,spritey,sprite,ecran,&clip);
/*apply_surface(obx, oby,sprite, ecran, &GOS->SP_1 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_2 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_4 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P3 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P4 );
apply_surface(obx, oby,sprite, ecran, &GOS->RS_1 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_2 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->RG1 );
apply_surface(spritex ,spritey,sprite,ecran,&clip); 
*/
//Display_All_Game_Objects(GOS,ecran);
                        break;   
				       }						
                                 
                break;
                //default:
//apply_surface(spritex ,spritey,sprite,ecran,&clip);   
/*apply_surface(obx, oby,sprite, ecran, &GOS->SP_1 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_2 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->SP_4 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P3 );
apply_surface(obx, oby,sprite, ecran, &GOS->GR1_P4 );
apply_surface(obx, oby,sprite, ecran, &GOS->RS_1 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_2 ); 
apply_surface(obx, oby,sprite, ecran, &GOS->RS_3 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P1 );
apply_surface(obx, oby,sprite, ecran, &GOS->ch1_P2 );
apply_surface(obx, oby,sprite, ecran, &GOS->RG1 );  
*/
//Display_All_Game_Objects(GOS,ecran);        
                       //			 break;
        }       
       /* if (BG->BGP.x<0||BG->BGP.x >9600)
         {        
       if (BG->BGP.y<0 ||BG->BGP.y>800)
         {
 
        freegame(BG);
        SDL_Flip(ecran);   

        }   
        }*/
 
   if (BG->BGP.x<=0)
    { 
     BG->BGP.x=0;
	}
     else
   if (BG->BGP.x >=9600)
    {
    BG->BGP.x=9600;
    }
    else
   if (BG->BGP.y<=0)
    {
    BG->BGP.y=0; 
    }
    else
   if (BG->BGP.y>=60)
    {
    BG->BGP.y=60;
    } 
	  
}
	}
    SDL_FreeSurface(sprite);
    SDL_FreeSurface(ecran);
    SDL_Quit();
    return EXIT_SUCCESS;

}
