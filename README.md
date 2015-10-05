# Mango

Repository for the Mango programming language as part of a blog series. The posts can be found [here](http://www.vnev.me). 

## Building and running
 
To build, just run:

    make

which should produce an executable called `mangoc` in the same directory. Run `mangoc` on the example file by doing

    ./mangoc example/test.mango



We're using `clang` to run the compile. To use `gcc` or `cc`, change `clang` to `gcc`/`cc` in the Makefile.
