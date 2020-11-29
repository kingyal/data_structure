export TOP_DIR := $(shell pwd)

all:
	make -C ./chapter_2/
clean:
	make clean -C ./chapter_2/
	
