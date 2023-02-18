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

pusw '1 2 3 4'
pusw '1 2 4 3'
pusw '2 1 3 4'
pusw '3 1 4 2'
pusw '4 3 2 1'
pusw '4 2 1 3'

pusw '5 4 3 2 1'
pusw '5 1 4 2 3'
pusw '3 1 5 4 2'

pusw '6 5 4 3 2 1'
pusw '5 2 1 3 4 6'
pusw '2 6 3 4 5 1'
