SRC=$(wildcard ./src/*.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

EXESRC=$(wildcard ./exesrc/*.c)
EXEOBJ=$(patsubst %.c,%.o, $(EXESRC))
EXE_TEMP=$(patsubst %.c,%.elf, $(EXESRC))
EXE=$(subst exesrc,exe, $(EXE_TEMP))

INC=-I ./inc

.SECONDARY:

all: $(EXE) clean_obj

%.elf: $(OBJ) $(EXEOBJ)
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

run: $(EXE)
	./exe/*.elf


# PROBLEMI / PITANJA
#
#	1. mogu li brisati samo .o datoteke koje postoje (trenutno pokrenem naredbu za brisanje svih, koja se uvijek
#	   izvede, a samo ce postojati .o datoteke za .c datoteke u kojima je bilo promjena)
#	2. kada povezujem .o datoteke u pojedinu .elf datoteku u naredbu su ukljucene i sve .o datoteke iz EXEOBJ  iako nam
#	   ne trebaju, treba nam samo jedna koja se odnosi na program koji trenutno poveZujemo
#
#

