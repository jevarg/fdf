TARGETS = 	fdf
CC		= 	g++
CFLAGS 	= 	-g -Werror -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS = 	-lSDL2
INCDIR	=	inc/

fdf: 	src/main.cpp \
	 	src/Window.cpp \
	 	src/Input.cpp \
		src/Map.cpp \
		src/Fdf.cpp

	$(CC) $^ $(CFLAGS) $(LDFLAGS) -I $(INCDIR) -o $@

clean:
	rm $(TARGETS)

re: clean fdf
