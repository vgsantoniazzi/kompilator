C=clang
DOXYGEN=doxygen
SOURCE=src/lexer.c src/math.c src/kompilator.c
LANG_EXECUTABLE=bin/kompilator
ASSEMBLY_FILE=bin/output.asm
PROGRAM_FILE=bin/output

FORMAT_EXECUTABLE=bin/format
SYSTEM_PATH=/usr/local/bin

all: clean
	@$(C) $(SOURCE) -o $(LANG_EXECUTABLE)
	@$(LANG_EXECUTABLE)

format:
	@$(FORMAT_EXECUTABLE)

install:
	@cp $(EXECUTABLE) $(SYSTEM_PATH)

docs: docs.delete docs.generate

docs.delete:
	@rm -Rf docs/

docs.generate:
	@$(DOXYGEN)


clean:
	@rm -f $(LANG_EXECUTABLE) $(ASSEMBLY_FILE) $(PROGRAM_FILE)
