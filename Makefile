app: precomp
	g++ -c main.cpp player.cpp enemy.cpp bg.cpp display.cpp pool.cpp bullet.cpp items.cpp menustate.cpp button.cpp boss.cpp
	g++ main.o player.o enemy.o bg.o display.o pool.o bullet.o items.o menustate.o button.o boss.o -o app -lsfml-graphics -lsfml-window -lsfml-system
	./app

precomp:
	touch app
	rm app

clean:
	rm *.o

