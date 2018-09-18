all: source/RePC.cpp source/pc_lib.cpp source/pc_lib.h
	gcc source/RePC.cpp  source/pc_lib.cpp -o debug/RePC
	debug/RePC
clean:
	rm -rf debug/*
