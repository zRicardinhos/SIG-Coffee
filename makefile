CC = gcc
CFLAGS = -Wall -std=c99 -I./src/modules



SRC_DIR = .
MODULES_DIR = src/modules
DATA_DIR = data


SRC = $(SRC_DIR)/main.c \
      $(MODULES_DIR)/clientes/clientes.c \
      $(MODULES_DIR)/funcionarios/funcionarios.c \
      $(MODULES_DIR)/comidas/comidas.c \
      $(MODULES_DIR)/financeiro/financeiro.c \
      $(MODULES_DIR)/pedidos/pedidos.c \
      $(MODULES_DIR)/utils/validacoes.c \
      $(MODULES_DIR)/utils/interface.c


TARGET = sig-coffee


all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


clean:
	rm -f $(TARGET)
	rm -rf $(DATA_DIR)/*.dat


data-dir:
	mkdir -p $(DATA_DIR)


run: all data-dir
	./$(TARGET)


debug: CFLAGS += -g
debug: clean all


install-deps:
	sudo apt-get install build-essential # Para sistemas baseados em Debian/Ubuntu


help:
	@echo "Opções disponíveis:"
	@echo "  make all       - Compila o projeto (padrão)"
	@echo "  make clean     - Remove arquivos gerados"
	@echo "  make run       - Compila e executa o programa"
	@echo "  make debug     - Compila com símbolos de debug"
	@echo "  make data-dir  - Cria o diretório de dados"
	@echo "  make install-deps - Instala dependências do sistema"

.PHONY: all clean run debug data-dir install-deps help