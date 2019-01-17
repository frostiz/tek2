#!/bin/bash

binary="./nanotekspice"

if [ ! -f "$binary" ]
then
    echo "Binary '"$binary"' not found"
    exit 84
fi

function check_result
{
    echo -n "$2: "
    test=`cat log | tail -n 2 | head -n 1 | grep -Eo '[[:alpha:]].*'`
    if [ "$test" == "$1" ]
    then
	echo -e "\033[32mOK\033[0m"
    else
	echo -e "\033[31mKO\033[0m"
	echo "EXPECTED:"
	echo $1
	echo "GOT:"
	echo $test
    fi
}

function check_result_dlatch
{
    echo "$3"
    nout=$1
    out=$2
    my_nout=`cat log | head -n 1`
    my_out=`cat log | head -n 2 | tail -n 1`

    if [ "$my_nout" == "$nout" ]
    then
        echo -e "TEST NOUT: \033[32mOK\033[0m"
    else
        echo -e "TEST NOUT: \033[31mKO\033[0m"
        echo "EXPECTED:"
        echo "$nout"
        echo "GOT"
        echo "$my_nout"
    fi

    if [ "$my_out" == "$out" ]
    then
        echo -e "TEST OUT: \033[32mOK\033[0m"
    else
        echo -e "TEST OUT: \033[31mKO\033[0m"
        echo "EXPECTED:"
        echo "$out"
        echo "GOT"
        echo "$my_out"
    fi
}

function test_and
{
    echo "Testing component 4081:"
    echo -e "simulate\ndisplay" | "$binary" components/and.nts a=0 b=0 > log
    check_result "s=0" " - 0 && 0"
    echo -e "simulate\ndisplay" | "$binary" components/and.nts a=1 b=1 > log
    check_result "s=1" " - 1 && 1"
    echo -e "simulate\ndisplay" | "$binary" components/and.nts a=0 b=1 > log
    check_result "s=0" " - 0 && 1"
    echo -e "simulate\ndisplay" | "$binary" components/and.nts a=0 b=-1 > log
    check_result "s=0" " - 0 && UNDEFINED"
    echo -e "simulate\ndisplay" | "$binary" components/and.nts a=1 b=-1 > log
    check_result "s=U" " - 1 && UNDEFINED"
}

function test_or
{
    echo "Testing component 4071:"
    echo -e "simulate\ndisplay" | "$binary" components/or.nts a=0 b=0 > log
    check_result "s=0" " - 0 || 0"
    echo -e "simulate\ndisplay" | "$binary" components/or.nts a=1 b=1 > log
    check_result "s=1" " - 1 || 1"
    echo -e "simulate\ndisplay" | "$binary" components/or.nts a=0 b=1 > log
    check_result "s=1" " - 0 || 1"
    echo -e "simulate\ndisplay" | "$binary" components/or.nts a=0 b=-1 > log
    check_result "s=U" " - 0 || UNDEFINED"
    echo -e "simulate\ndisplay" | "$binary" components/or.nts a=1 b=-1 > log
    check_result "s=1" " - 1 || UNDEFINED"
}

function test_xor
{
    echo "Testing component 4030:"
    echo -e "simulate\ndisplay" | "$binary" components/xor.nts a=0 b=0 > log
    check_result "s=0" " - 0 ^ 0"
    echo -e "simulate\ndisplay" | "$binary" components/xor.nts a=1 b=1 > log
    check_result "s=0" " - 1 ^ 1"
    echo -e "simulate\ndisplay" | "$binary" components/xor.nts a=0 b=1 > log
    check_result "s=1" " - 0 ^ 1"
    echo -e "simulate\ndisplay" | "$binary" components/xor.nts a=0 b=-1> log
    check_result "s=U" " - 0 ^ UNDEFINED"
    echo -e "simulate\ndisplay" | "$binary" components/xor.nts a=1 b=-1 > log
    check_result "s=U" " - 1 ^ UNDEFINED"
}

function test_nor
{
    echo "Testing component 4001:"
    echo -e "simulate\ndisplay" | "$binary" components/nor.nts a=0 b=0 > log
    check_result "s=1" " - ~(0 | 0)"
    echo -e "simulate\ndisplay" | "$binary" components/nor.nts a=1 b=1 > log
    check_result "s=0" " - ~(1 | 1)"
    echo -e "simulate\ndisplay" | "$binary" components/nor.nts a=0 b=1 > log
    check_result "s=0" " - ~(0 | 1)"
    echo -e "simulate\ndisplay" | "$binary" components/nor.nts a=0 b=-1 > log
    check_result "s=U" " - ~(0 | UNDEFINED)"
    echo -e "simulate\ndisplay" | "$binary" components/nor.nts a=1 b=-1 > log
    check_result "s=0" " - ~(1 | UNDEFINED)"
}

function test_nand
{
    echo "Testing component 4011:"
    echo -e "simulate\ndisplay" | "$binary" components/nand.nts a=0 b=0 > log
    check_result "s=1" " - ~(0 & 0)"
    echo -e "simulate\ndisplay" | "$binary" components/nand.nts a=1 b=1 > log
    check_result "s=0" " - ~(1 & 1)"
    echo -e "simulate\ndisplay" | "$binary" components/nand.nts a=0 b=1 > log
    check_result "s=1" " - ~(0 & 1)"
    echo -e "simulate\ndisplay" | "$binary" components/nand.nts a=0 b=-1 > log
    check_result "s=U" " - ~(0 & UNDEFINED)"
    echo -e "simulate\ndisplay" | "$binary" components/nand.nts a=1 b=-1 > log
    check_result "s=0" " - ~(1 & UNDEFINED)"
}

function test_not
{
    echo "Testing component 4069:"
    echo -e "simulate\ndisplay" | "$binary" components/not-undefined.nts a=-1 > log
    check_result "s=U" " - not UNDEFINED"
    echo -e "simulate\ndisplay" | "$binary" components/not-undefined.nts a=0 > log
    check_result "s=1" " - not 0"
    echo -e "simulate\ndisplay" | "$binary" components/not-undefined.nts a=1 > log
    check_result "s=0" " - not 1"
}

test_and
test_or
test_xor
test_nor
test_nand
test_not

touch log2
rm log log2
#find . -name "*.nts" | while read file; do
 #   echo "Processing $file"
  #  
#done
