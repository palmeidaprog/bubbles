#!/bin/bash
rm Makefile
cp Makefile.mac Makefile
make
lldb ./bin/bubbles