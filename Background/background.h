/** 
* @struct background
* @brief struct for background
*/


#ifndef BACKGROUND_H_
#define BACKGROUND_H_

typedef struct Background {
	SDL_Surface* Background;
	SDL_Rect BGP;
}BGS;

/*typedef struct Game_objects {
	SDL_Surface *SP1;//spike
	SDL_Surface *SP2;//Spike
	SDL_Surface *SP3;//Spike
	SDL_Surface *SP4;//Spike
	SDL_Surface *GR1;//Ground Object
	SDL_Surface *RS1;
	SDL_Surface *RS2;
	SDL_Surface *RS3;
	SDL_Surface *ch;//chain
	SDL_Surface *RG;//Ring 

	SDL_Rect SP_1;
	SDL_Rect SP_2;
	SDL_Rect SP_3;
	SDL_Rect SP_4;
	SDL_Rect GR1_P1;
	SDL_Rect GR1_P2;
	SDL_Rect GR1_P3;
	SDL_Rect GR1_P4;
	SDL_Rect RS_1;
	SDL_Rect RS_2;
	SDL_Rect RS_3;
	SDL_Rect ch1_P1;
	SDL_Rect ch1_P2;
	SDL_Rect RG1;


}GO;
*/
         

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );
void scrolling(SDL_Rect *camera_pos, int d );
void Init_BG(BGS *BG);
//void Init_All_Objs(GO *GOS);
void Display_BG(BGS *BG,SDL_Surface *Screen);
//void Display_All_Game_Objects(GO *GOS, SDL_Surface *Screen);
void freegame(BGS *BG);
#endif /* BACKGROUND_H_ */
