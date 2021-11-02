SRC=$(wildcard ./src/*.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

EXESRC=$(wildcard ./exesrc/*.c)
EXEOBJ=$(patsubst %.c,%.o, $(EXESRC))
EXE_TEMP=$(patsubst %.c,%.elf, $(EXESRC))
EXE=$(subst exesrc,exe, $(EXE_TEMP))

INC=-I ./inc

.SECONDARY:

all: $(EXE)

./exe/%.elf: $(OBJ) ./exesrc/%.o
	gcc $^ -o $@ -lm

%.o: %.c
	gcc ${INC} -c $< -o $@

clean_obj:
	rm -f ${OBJ} ${EXEOBJ}

clean_exe:
	rm -f ${EXE}

print:
	@echo ${EXE}
	@echo ${SRC}
	@echo ${EXESRC}
	@echo ${OBJ}
	@echo ${EXEOBJ}

run:
	for f in ${EXE} ; do $$f; done


# PROBLEMI / PITANJA
#
#	1. mogu li brisati samo .o datoteke koje postoje (trenutno pokrenem naredbu za brisanje svih, koja se uvijek
#	   izvede, a samo ce postojati .o datoteke za .elf datoteke u kojima je bilo promjena)


