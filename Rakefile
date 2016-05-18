require 'rake'

MRUBY_ROOT = File.expand_path('mruby')
MRBC       = "#{MRUBY_ROOT}/bin/mrbc"
LIB_MRUBY  = "#{MRUBY_ROOT}/build/host/lib/libmruby.a"
LIB_SRC  = "src/stub.c"

CMPL = 'gcc'
ENV['MRUBY_CONFIG'] ||= File.expand_path('mruby_config.rb')

STD_FLAGS  = %W[-std=c99]
GCC_FLAGS  = %W[-Imruby/include]
MRBC_FLAGS = %W[-Blib]

desc "Build mruby and Ruby src files"
task :build do
  sh 'git submodule update --init --recursive'
  cd('mruby') { sh 'make' }
  sh MRBC, *MRBC_FLAGS, 'lib/lib.rb'
  sh "mv lib/*.c src/"
  sh CMPL, *STD_FLAGS, *GCC_FLAGS, LIB_SRC, '-o', 'bin', LIB_MRUBY
end

desc "Run compiled binary file"
task :run do
  sh './bin'
end

desc "Remove all created files"
task :clean do
  sh 'rm bin'
  sh 'rm src/lib.c'
end

task :default => :run
