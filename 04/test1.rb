#!/usr/bin/env ruby

$:.unshift(__dir__)
require "rcpplib"

c = Rcpplib::C.new
c.method1
c.method2
c.method3
