#
# Makefile
# sagar, 2013-10-27 18:35
#

LIBS = -lglut -lGL -lGLU -lSDL -lSDL_image

objects = main.o textures.o

mario : $(objects)
	g++ -o mario $(objects) $(LIBS)

main.o : main.cpp textures.h  
	g++ -c main.cpp 

textures.o : textures.cpp textures.cpp 
	g++ -c textures.cpp 

clean : 
	rm $(objects) 
# vim:ft=make
