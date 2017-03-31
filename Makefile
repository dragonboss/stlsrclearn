objs=__malloc_alloc_template.o main.o
mycompiler=g++ -std=c++11
main:$(objs)
	$(mycompiler) -o main $(objs)
__malloc_alloc_template.o:__malloc_alloc_template.h
	$(mycompiler) -c __malloc_alloc_template.cpp
main.o:main.cpp
	$(mycompiler) -c main.cpp

.PHONY:clean
clean:
	rm main $(objs)
