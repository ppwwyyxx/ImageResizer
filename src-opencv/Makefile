sinclude Makefile.config

OBJ_DIR 	:= obj
OPTFLAGS 	?= -O2 -Wall -Wextra
DEFINES		?= -DDEBUG
PKG_LIBS	:= opencv
INCLUDE 	:= -I.
CXX_FLAGS   += $(shell pkg-config --cflags $(PKG_LIBS)) $(INCLUDE) -std=c++11 $(OPTFLAGS) $(DEFINES)
LD_FLAGS    := $(shell pkg-config --libs $(PKG_LIBS)) -lpthread -fopenmp

SRCS     := $(shell find -L -name "*.cc" | cut -c 3-)
OBJS     := $(addprefix $(OBJ_DIR)/, $(SRCS:.cc=.o))
MAIN_SRCS := $(shell find -L -name "*.cpp" | cut -c 3-)
MAIN_OBJ  := $(addprefix $(OBJ_DIR)/, $(MAIN_SRCS:.cpp=.o))
DEPS     := $(OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

BINS     := $(MAIN_SRCS:.cpp=)

.PHONY: all clean

all: $(BINS)

clean:
	rm -rf $(BINS) $(OBJ_DIR)

$(OBJ_DIR)/%.d: %.cc
	@mkdir -p $(dir $@)
	@echo "[dep] $@ ..."
	@$(CXX) -MM -MT "$(OBJ_DIR)/$(<:.cc=.o) $(OBJ_DIR)/$(<:.cc=.d)" $(CXX_FLAGS) "$<" > "$@"

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	@echo "[cxx] $@ ..."
	@$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(BINS): %: $(OBJS) %.cpp
	@echo "[main] $@ ..."
	@$(CXX) $^ -o $@ $(CXX_FLAGS) $(LD_FLAGS)
	@echo "have a nice day!"

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
