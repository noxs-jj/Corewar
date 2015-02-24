#!/bin/sh

var=0
label=""

function my_gen_test()
{
	T_REG=$1
	T_IND=$2
	T_DIR=$3


	IFS="
"

	for line in $(grep "[a-zA-Z]" test_param)
	do
		line=$(echo "$line" | sed "s/T_REG/$T_REG/g")
		line=$(echo "$line" | sed "s/T_DIR/$T_DIR/g")
		line=$(echo "$line" | sed "s/T_IND/$T_IND/g")
		echo "$label$line" > tmp_dir/$var.s
		((var=$var + 1))
	done
	IFS=" "
}

function big_test()
{
	i=4000
	while ! [ $i -eq 0 ]
	do
		echo "live %1" >> tmp_dir/big_file.s
		((i=$i - 1))
	done
}

vpwd=$(pwd)
cd .. && make
cd "$vpwd"
cp ../asm .

rm -rf tmp_dir
mkdir tmp_dir

my_gen_test r1 %1 1
my_gen_test r2 21 %1
my_gen_test r3 12 %23
my_gen_test r4 12 %2
my_gen_test r2 %-31 48
label="toto: "
my_gen_test 12 %:toto 48
label="toto:"
my_gen_test 12 %:toto 48
label=""
my_gen_test r1 %:toto 12

big_test

./asm_cmp.sh tmp_dir
echo "TEST_FINISHED"
