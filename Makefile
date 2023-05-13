all:
	gcc bufferof.c -o exploit
	mkdir libnss_X
	gcc -g -fPIC -shared shell_tool.c -o libnss_X/X.so.2
