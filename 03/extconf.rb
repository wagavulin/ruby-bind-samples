require 'mkmf'

$CXXFLAGS += " -std=c++14 "
$CPPFLAGS = " -I./cpplib"
$LDFLAGS += " -L./cpplib -Wl,-rpath,'$$ORIGIN/cpplib'"
$libs = " -lcpplib"
create_makefile('rcpplib')
