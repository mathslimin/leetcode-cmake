if [ -z "$1" ] || [ -z "$2" ]
then
	echo 'ERROR: need paramter `./new.sh  <tag name> <problem name>`'
	exit 1 
fi
DIRNAME=$(dirname $0)
path="$DIRNAME/problems/$1/$2"
echo $path
if [ -d $path ]
then
	echo "ERROR: directory $path has existed"
	exit 1
fi
cp -r "$DIRNAME/problem_template" $path
mv "$path/TTT.c" "$path/$2.c"
sed -i "s/TTT/$2/g" "$path/$2.c"
sed -i "s/TTT/$2/g" "$path/CMakeLists.txt"

