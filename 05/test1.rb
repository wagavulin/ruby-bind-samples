#!/usr/bin/env ruby

$:.unshift(__dir__)
require "rcpplib"

a = Rcpplib::A.new
p a.b.x
a.b.x = 20
p "expected: 20, actual: #{a.b.x}"

b = Rcpplib::B.new
b.x = 30
a.b = b
p "expected: 30, actual: #{a.b.x}"
b.x = 40
p "expected: 40, actual: #{a.b.x}"
