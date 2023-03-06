CFLAGS = `sdl-config --cflags` -g -O3 -Wall
LIBS = `sdl-config --libs` -lm -lSDL_image
SOURCES = $(wildcard *.cpp)
OBJS = $(SOURCES:%.cpp=%.o)
PROG = infographie

all: $(PROG)

affichage:
	@echo $(SOURCES)
	@echo $(PROG)

$(PROG): $(PROG).cpp $(OBJS)
	@/usr/bin/printf "\u25B6 Compilation du programme %s\n" $@
	@g++ $(CFLAGS) -o $@ $(OBJS) $(LIBS)
	@/usr/bin/printf "  Terminée\n"

%.o: %.cpp
	@/usr/bin/printf "\u25B6 Compilation de %s\n" $<
	@g++ $< $(CFLAGS) -c -o $@

clean:
	@/usr/bin/printf "\u25B6 Nettoyage du dossier\n"
	@rm -f *~ $(OBJS) $(PROG)
