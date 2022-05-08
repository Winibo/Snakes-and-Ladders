# Directory that contains this project
PROJECT = chutes_ladders
GTEST = test_$(PROJECT)

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= $(CXXVERSION) -g -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest

# Directories
SRC_DIR = src
GTEST_DIR = test
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

DOXY_DIR = docs/code

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileProject

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(GTEST_DIR)/output/*.dat \
	*.gcov *.gcda *.gcno *.orig ???*/*.orig \
	$(PROJECT) $(COVERAGE_RESULTS) \
	$(GTEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)  \
	$(DOXY_DIR)/html obj bin $(PROJECT).exe $(GTEST).exe

# compilation using the files in include, src, and test, but not src/project
$(GTEST): $(GTEST_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(GTEST) $(INCLUDE) \
	$(GTEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)

# compilation using the files in include, src, and src/project, but not test
compileProject: $(SRC_DIR)
	$(CXX) $(CXXVERSION) -o $(PROJECT) $(INCLUDE) $(SRC_DIR)/*.cpp

memcheck: $(PROJECT)
	valgrind --tool=memcheck --leak-check=yes $(PROJECT)

static: ${SRC_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${SRC_INCLUDE} --suppress=missingInclude

style: ${SRC_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
	${STYLE_CHECK} ${SRC_DIR}/* ${SRC_INCLUDE}/* ${PROJECT_SRC_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen $(DOXY_DIR)/doxyfile
