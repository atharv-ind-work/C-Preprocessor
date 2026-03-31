COMPILE = cc #COMPILE is a variable
target = main.o comment.o process.o header.o macro.o

exe : ${target}
	${COMPILE} ${target} -o exe

main.o : main.c
	${COMPILE} -c main.c

comment.o : comment.c
	${COMPILE} -c comment.c

process.o : process.c
	${COMPILE} -c process.c

header.o : header.c
	${COMPILE} -c header.c

macro.o : macro.c
	${COMPILE} -c macro.c

clear :
	@echo "cleaning up..."
	@rm -ivr *.o