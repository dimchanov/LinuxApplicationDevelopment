TARGET_DIR="build"

mkdir -p $TARGET_DIR
cp ./src/main $TARGET_DIR/guess_number
cp -r ./src/ru $TARGET_DIR/
mkdir -p $TARGET_DIR/share/man/man1
cp ./doxygen-doc/man/man1/guess_number.1 $TARGET_DIR/share/man/man1/guess_number.1



