SRC = $(wildcard *.cpp ./source/*.cpp)
INCLUDE_PATH = -I./include/
RM := del
CC := g++

main: $(SRC)
	$(CC) $(INCLUDE_PATH) $(SRC) -o $@
	@echo make sucess

.PHONY:
show:
	@echo $(SRC)

.PHONY:
clean:
	$(RM) .\source\*.o
	$(RM) .\*.o
	$(RM) .\*.exe