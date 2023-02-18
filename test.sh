#!/bin/bash

make && make btest

pusw() {
	echo
	echo $1
	./push_swap $1 | ./checker $1
}

pusw '1'

pusw '1 2'
pusw '2 1'

pusw '1 2 3'
pusw '1 3 2'
pusw '2 1 3'
pusw '2 3 1'
pusw '3 2 1'
pusw '3 1 2'
