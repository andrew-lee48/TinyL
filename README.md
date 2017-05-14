# TinyL
TinyL project for CS 314 Fall 2015

TinyL is a simple expression language that allows assignments, and print as its only I/O operation. Every token is a single character of the input. This makes scanning rather easy, but does not allow integer constants of more than one digit, or variable names of more than one character.

Examples of valid tinyL programs:
a=3;b=5;c=/3*ab;d=+c1;!d.
a=7;b=*+1+2a58;!b.

The assignment involved completing methods in Compiler.c, Optimizer.c, and InstrUtils.c.
