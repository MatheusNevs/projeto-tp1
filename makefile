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
TEST_SRC_DIR = $(TEST_DIR)
TEST_DOMAIN_SRC_DIR = $(TEST_DIR)/domains
TEST_ENTITY_SRC_DIR = $(TEST_DIR)/entities

# Arquivos de origem
DOMAIN_SOURCES = $(wildcard $(DOMAIN_SRC_DIR)/*.cpp)
ENTITY_SOURCES = $(wildcard $(ENTITY_SRC_DIR)/*.cpp)
UTIL_SOURCES = $(wildcard $(UTIL_SRC_DIR)/*.cpp)

TEST_SOURCES = $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_DOMAIN_SOURCES = $(wildcard $(TEST_DOMAIN_SRC_DIR)/*.cpp)
TEST_ENTITY_SOURCES = $(wildcard $(TEST_ENTITY_SRC_DIR)/*.cpp)

# Arquivos objeto
DOMAIN_TEST_OBJECTS = $(DOMAIN_SOURCES:.cpp=.o) $(UTIL_SOURCES:.cpp=.o) $(TEST_SOURCES:.cpp=.o) $(TEST_DOMAIN_SOURCES:.cpp=.o)
ENTITY_TEST_OBJECTS = $(DOMAIN_SOURCES:.cpp=.o) $(ENTITY_SOURCES:.cpp=.o) $(UTIL_SOURCES:.cpp=.o) $(TEST_SOURCES:.cpp=.o) $(TEST_ENTITY_SOURCES:.cpp=.o) 

# Arquivo executável
TEST_DOMAIN_EXE = test_domain
TEST_ENTITY_EXE = test_entity

# Regra padrão
all: $(TEST_DOMAIN_EXE) $(TEST_ENTITY_EXE)

# Linkagem final 1
$(TEST_DOMAIN_EXE): $(DOMAIN_TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Linkagem final 2
$(TEST_ENTITY_EXE): $(ENTITY_TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra para executar 1
run: $(TEST_DOMAIN_EXE) $(TEST_ENTITY_EXE)
	./$(TEST_DOMAIN_EXE)
	./$(TEST_ENTITY_EXE)

# Limpeza dos objetos e executável
clean:
	rm -rf *.o *.exe *.gc* *.rpt docs

#Criação da documentação HTML
doxygen: Doxyfile
	rm -rf doxygenpages
	doxygen