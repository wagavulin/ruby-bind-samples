TARGET := libcpplib.so
SRCS := cpplib.cpp
OBJS := $(SRCS:%.cpp=%.o)
DEPS := $(SRCS:%.cpp=%.d)

CXX := g++
CXXFLAGS := -std=c++14 -g -fPIC -Wall -Wextra
LDFLAGS :=
LIBS :=

all: $(TARGET)

-include $(DEPS)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) --shared -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -MMD -MP $<

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
