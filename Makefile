.PHONY: app clean cleanall run

CMD := g++
LIB := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FLAGS := -std=c++17 -O3
RM := rm -rf
SRC := src/
OBJ := obj/
BIN := ./
SRCS := $(wildcard $(SRC)*.cpp)
OBJS := $(patsubst $(SRC)%.cpp,$(OBJ)%.o,$(SRCS))
APP := $(BIN)Asteroids
MKDIR = mkdir

app: $(APP)

$(APP): $(OBJS) | $(BIN)
	$(CMD) -o $@ $^ $(LIB) $(FLAGS)
	@echo "Finished app compilation"

$(OBJ)%.o: $(SRC)%.cpp | $(OBJ)
	$(MKDIR) -p $(@D)
	$(CMD) -o $@ -c $< $(FLAGS)
	@echo "Finished building object file for $<"

$(BIN) $(OBJ):
	$(MKDIR) $@

clean:
	$(RM) $(OBJ)*.o
	@echo "Removed object files"

cleanall: clean
	$(RM) $(APP)
	@echo "Removed compiled file"

run: app
	@echo "Starting program"
	$(APP)
