all:
	cd ./build/ && make
	mv ./build/IndieStudio ./

clean:

fclean:

re:
	rm -rf ./build
	mkdir ./build
	cd ./build/ && cmake ../ && make
	mv ./build/IndieStudio ./

.PHONY: all clean flcean re
