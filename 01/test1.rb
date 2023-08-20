#!/usr/bin/env ruby

$:.unshift(__dir__)
require "rcpplib"

a = Rcpplib::A.new
a.method1
