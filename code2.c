#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main()
{
    int i=0,wait=-1,t=10,menu=0,x,y,loop=0,ps=0,ps2=0;
      TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING); // Initialisation de la SDL
    SDL_Surface *ecran =NULL, *temp,*anim[143],*menu2[10],*text,*image200=NULL,*image=NULL,*image2=NULL,*image3=NULL,*image4=NULL,*image5=NULL,*image6=NULL,*image7=NULL,*image8=NULL,*image50=NULL,*image60=NULL,*image70=NULL,*image80=NULL;
 
    ecran=SDL_SetVideoMode(800, 564, 32, SDL_HWSURFACE); // Ouverture de la fenêtre
    SDL_Rect postemp,positionim,positionim2,positionim3,positionim4,position1,position2,position3,position4,position5,position6;
    SDL_Color color;
    char convxy[30],load[25],load2[25];
 for(i=756;i<900;i++){sprintf(load,"animbg/a_00%d.png",i);
 anim[i-756]=IMG_Load(load);}
     TTF_Font* font;
    font=TTF_OpenFont("HORROR VISION DEMO.ttf",30);
    positionim.x = 434;
    positionim.y = 318 ;
    positionim2.x =434 ;
    positionim2.y = 376;
    positionim3.x =434;
    positionim3.y = 434 ;
    positionim4.x =434;
    positionim4.y = 492;
    position1.x = 300;
    position1.y = 196 ;
    position2.x = 520;
    position2.y = 196;
    position3.x =236;
    position3.y = 196;
    position4.x =248;
    position4.y = 290;
    position5.x = 474;
    position5.y = 290 ;
    position6.x =327 ;
    position6.y = 375;
    
    
    
    image= IMG_Load("menu/1.png");
    image2= IMG_Load("menu/3.png");
    image3= IMG_Load("menu/5.png");
    image4= IMG_Load("menu/7.png");
    image5= IMG_Load("menu/2.png") ;
    image6= IMG_Load("menu/4.png"); 
    image7= IMG_Load("menu/6.png"); 
    image8= IMG_Load("menu/8.png");
    image50= IMG_Load("menu/20.png") ;
    image60= IMG_Load("menu/40.png"); 
    image70= IMG_Load("menu/60.png"); 
    image80= IMG_Load("menu/80.png");
    image200= IMG_Load("1/bac2.png");
    for(i=1;i<11;i++){sprintf(load2,"1/%d.png",i);
   menu2[i]=IMG_Load(load2);}
    
	color.r=250;
	color.g=250;
	color.b=250;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }

    Mix_Music *musique;//pointeur musique jeux

    musique = Mix_LoadMUS("hit.mp3");//musique jeux
    Mix_PlayMusic(musique, -1);//repeter la music de jeux (boucle infinie)

    Mix_Chunk *MB,*MB2;//pointeur music boutton(chunk se defere de formart) chunk pour format wav ; Music pour format mp3
    MB = Mix_LoadWAV("selectmony.wav");// clique de bouton
 MB2 = Mix_LoadWAV("click.wav");
    SDL_Event event;//clavier et souris
    int continuer = 1;//si continuer=1 il reste dans la boucle while ; si 0 il quite la boucle

while (continuer)
   { 
	   if(menu==0){
		   
SDL_BlitSurface(anim[loop], NULL, ecran, NULL);//affichage de menu
loop++;if(loop==143){loop=0;}
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_BlitSurface(image2,NULL,ecran,&positionim2);
        SDL_BlitSurface(image3,NULL,ecran,&positionim3);
	SDL_BlitSurface(image4,NULL,ecran,&positionim4);
	
while(SDL_PollEvent(&event)){
       switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN :
        switch(event.key.keysym.sym){
			 case SDLK_ESCAPE:
			continuer = 0;
			break;
			}
           break;
        case SDL_MOUSEBUTTONDOWN :
    if(event.button.button==SDL_BUTTON_LEFT){
							x=event.button.x;
							y= event.button.y;
		if (x >446 && y >333 && x < 749 && y <383)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
		{Mix_PlayChannel(2, MB2, 0); }
              else if (x >453 && y >397 && x <750 && y <440)
                { Mix_PlayChannel(2, MB2, 0);}
               else if (x >455 &&y >450 &&x <752  && y <496)
		{ Mix_PlayChannel(2, MB2, 0);}
                else if (x >456&& y >505 && x < 756 && y <556)
                { Mix_PlayChannel(2, MB2, 0);}
          
    if (x >446 && y >333 && x < 749 && y <383)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
                    SDL_BlitSurface(image50,NULL, ecran, &positionim);//new tech3el
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms)
					wait=t;
					temp=image50;
					postemp=positionim;
          }else if (x >453 && y >397 && x <750 && y <440)
                {
                    SDL_BlitSurface(image60,NULL, ecran, &positionim2);//settings tech3el
                    wait=t;
					temp=image60;
					postemp=positionim2;}
               else if (x >455 &&y >450 &&x <752  && y <496)
{
                    SDL_BlitSurface(image70,NULL, ecran, &positionim3);//credit tech3el
					wait=t;
					temp=image70;
					postemp=positionim3;}
                else if (x >456&& y >505 && x < 756 && y <556 )
            {SDL_BlitSurface(image80,NULL, ecran, &positionim4);//quit tech3el
                    wait=t;
					temp=image80;
					postemp=positionim4; }
			
              }
        
           break;
        case SDL_MOUSEMOTION :
                  {
					  x=event.motion.x;
					  y=event.motion.y;

            }break;
      }
      }
                      if (x >446 && y >333 && x < 749 && y <383&&(ps==0))//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
              {ps=1;
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms)
                    Mix_PlayChannel(1, MB, 0); 
     }else if (x >453 && y >397 && x <750 && y <440 &&(ps==0))
                {ps=1;
              Mix_PlayChannel(1, MB, 0);
}
               else if (x >455 &&y >450 &&x <752  && y <496&&(ps==0))
{   ps=1;    
				Mix_PlayChannel(1, MB, 0);
                }
                else if (x >456&& y >505 && x < 756 && y <556&&(ps==0) )
                {ps=1;
                    Mix_PlayChannel(1, MB, 0);
                  }
    ////////////////////////////////////////////////////////////////////////
                               if (x >446 && y >333 && x < 749 && y <383)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
                    SDL_BlitSurface(image5,NULL, ecran, &positionim);//new tech3el
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms) 
     }else if (x >453 && y >397 && x <750 && y <440)
                {
                    SDL_BlitSurface(image6,NULL, ecran, &positionim2);//settings tech3el
   
}
               else if (x >455 &&y >450 &&x <752  && y <496)
{
                    SDL_BlitSurface(image7,NULL, ecran, &positionim3);//credit tech3el

                }
                else if (x >456&& y >505 && x < 756 && y <556 )
                {
                    SDL_BlitSurface(image8,NULL, ecran, &positionim4);//quit tech3el
                         }else{ps=0;}
         
if(wait>0){wait--;
 SDL_BlitSurface(temp,NULL, ecran, &postemp);
}if(wait==0){if(temp==image80){continuer=0;}}
if(wait==0){if(temp==image50){menu=1;wait=-1;}}
if(wait==0){if(temp==image60){menu=2;wait=-1;}}
      }else if(menu==1){
        SDL_BlitSurface(anim[loop], NULL, ecran, NULL);//affichage de menu
loop++;if(loop==143){loop=0;}
while(SDL_PollEvent(&event)){
       switch(event.type)
        {
        
        case SDL_KEYDOWN :
        switch(event.key.keysym.sym){
			
			case SDLK_h:
			menu = 0;
			
			break;
			case SDLK_ESCAPE:
			continuer = 0;
			break;
			
			}
           break;
		  
 }}}
		  else if(menu==2)
		  {
		  SDL_BlitSurface(image200, NULL, ecran, NULL);//affichage de menu
       SDL_BlitSurface(menu2[6],NULL,ecran,&position1);
       SDL_BlitSurface(menu2[7],NULL,ecran,&position2);
       SDL_BlitSurface(menu2[9],NULL,ecran,&position3);
       SDL_BlitSurface(menu2[3],NULL,ecran,&position4);
       SDL_BlitSurface(menu2[1],NULL,ecran,&position6);
       SDL_BlitSurface(menu2[4],NULL,ecran,&position5);
       while(SDL_PollEvent(&event)){
       switch(event.type)
        {
        
        case SDL_KEYDOWN :
        switch(event.key.keysym.sym){
			case SDLK_h:
			menu = 0;
			
			break;
			case SDLK_ESCAPE:
			continuer = 0;
			break;
			case SDLK_PLUS:
			
                    SDL_BlitSurface(menu2[8],NULL, ecran, &position2);
                   
					break;
			}
			case SDL_MOUSEBUTTONDOWN :
    if(event.button.button==SDL_BUTTON_LEFT){
							x=event.button.x;
							y= event.button.y;
		if (x >520 && y >196 && x < 570 && y <238)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
		{Mix_PlayChannel(2, MB2, 0); }
              else if (x >236 && y >196 && x <284 && y <238)
                { Mix_PlayChannel(2, MB2, 0);}
               else if (x >474 &&y >290 &&x <542 && y <334)
		{ Mix_PlayChannel(2, MB2, 0);}
                else if (x >327 && y >375 && x < 481 && y <426)
                { Mix_PlayChannel(2, MB2, 0);}
          
    if (x >520 && y >196 && x < 570 && y <238)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
                    SDL_BlitSurface(menu2[8],NULL, ecran, &position2);//new tech3el
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms)
					
          }else if (x >236 && y >196 && x <284 && y <238)
                {
                    SDL_BlitSurface(menu2[10],NULL, ecran, &position3);}
               else if (x >474 &&y >290 &&x <542 && y <334)
{
                    SDL_BlitSurface(menu2[5],NULL, ecran, &position5);}
                else if (x >327 && y >375 && x < 481 && y <426 )
            {SDL_BlitSurface(menu2[2],NULL, ecran, &position6);
			
              }
        
			
			
           }break;
		  
		  }}
		  
		  }
		  

sprintf(convxy,"WELCOME x=%d y=%d",x,y);
text=TTF_RenderText_Solid(font,convxy,color);//convertire un message vers une image
 SDL_BlitSurface(text,NULL, ecran,NULL);
SDL_Flip(ecran);
SDL_Delay(40);
}
for(i=0;i<143;i++)
SDL_FreeSurface(anim[i]); 
for(i=1;i<10;i++)
SDL_FreeSurface(menu2[10]); 

 SDL_FreeSurface(text);  
SDL_FreeSurface(ecran);
SDL_FreeSurface(image);
SDL_FreeSurface(image2);
SDL_FreeSurface(image3);
SDL_FreeSurface(image4);
SDL_FreeSurface(image5);
SDL_FreeSurface(image6);
SDL_FreeSurface(image7);
SDL_FreeSurface(image8);
SDL_FreeSurface(image200);

 Mix_FreeMusic(musique);//free espace memoire
    Mix_CloseAudio();//tsakr e sout
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit(); // Arrêt de la SDL
    return 0;
}

