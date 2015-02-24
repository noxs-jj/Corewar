if [ -z $1 ]
then
	echo "Usage: "
	exit -1
fi

var=0;
rm -rf $1/*.cor
for file in $(find "$1" -name "*.s")
do
	((var=$var + 1))
	asm_ori=$(./asm_origin $file 2>&1)
	dir=$(dirname $file 2> /dev/null)
	file2=$(basename $file 2> /dev/null)
	file2=$(echo $file2 | cut -d '.' -f 1)
	file2=$(echo "$file2.cor")
	mv "$dir/$file2" "$dir/$file2.cor" 2> /dev/null
	asm_my=$(./asm $file 2>&1)
	if ! [ -f "$dir/$file2" ] && [ -f "$dir/$file2.cor" ]
	then
		echo "error file no created: $dir/$file2.cor"
	elif [ -f "$dir/$file2" ] && ! [ -f "$dir/$file2.cor" ]
	then
		echo "error file created: $dir/$file2"
	elif ! [ -f "$dir/$file2" ] && ! [ -f "$dir/$file2.cor" ]
	then
		echo "\x1B[32mis ok!\x1B[0m"
	else
		differ=$(diff "$dir/$file2" "$dir/$file2.cor")
		if ! [ -z $differ ]
		then
			echo "\x1B[31mFail: differ\x1B[0m"
			echo $asm_ori
			echo $asm_my
		else
			echo "\x1B[32mis ok!\x1B[0m"
			rm -rf "$dir/$file2" "$dir/$file2.cor"
		fi
	fi
done
