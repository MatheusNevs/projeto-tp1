# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -std=c++17

# Diretórios
INCLUDE_DIR = include
SOURCE_DIR = source
TEST_DIR = test
LIB_DIR = lib

# Diretórios específicos
DOMAIN_SRC_DIR = $(SOURCE_DIR)/domains
ENTITY_SRC_DIR = $(SOURCE_DIR)/entities
UTIL_SRC_DIR = $(LIB_DIR)/utils
TEST_SRC_DIR = $(TEST_DIR)/domains

# Arquivos de origem
DOMAIN_SOURCES = $(wildcard $(DOMAIN_SRC_DIR)/*.cpp)
ENTITY_SOURCES = $(wildcard $(ENTITY_SRC_DIR)/*.cpp)
UTIL_SOURCES = $(wildcard $(UTIL_SRC_DIR)/*.cpp)
TEST_SOURCES = $(wildcard $(TEST_SRC_DIR)/*.cpp)

# Arquivos objeto
OBJECTS = $(DOMAIN_SOURCES:.cpp=.o) $(ENTITY_SOURCES:.cpp=.o) $(UTIL_SOURCES:.cpp=.o) $(TEST_SOURCES:.cpp=.o)

# Arquivo executável
EXECUTABLE = program

# Regra padrão
all: $(EXECUTABLE)

# Linkagem final
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra para executar
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Limpeza dos objetos e executável
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
