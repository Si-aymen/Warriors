prog:  menu.o main.o play.o background.o perso.o
	gcc main.o menu.o play.o background.o perso.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -g
play.o:play.c
	gcc -c play.c -lSDL -lSDL_image -lSDL_mixer -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_image -lSDL_mixer -g
preso.o:perso.c
	gcc -c perso.c -lSDL -lSDL_image -lSDL_mixer -g
