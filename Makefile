CC = gcc
LIBS = -lm
#Pega todos os arquivos dentro de source!
SRCS = $(wildcard source/*.c)
TARGET = programa

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(LIBS)
	@echo "Pronto! Para rodar o TP, digite: ./$(TARGET)"

clean:
	rm -f $(TARGET)
	@echo "Limpo!"

.PHONY: all clean