if ! $(sudo -l &> /dev/null); then
    echo "Error: root privileges are needed to run this script"
    exit $E_NOTROOT
fi

TARGET_DIR="/usr/local"

mkdir -p $TARGET_DIR
cp ./src/main $TARGET_DIR/bin/guess_number
cp -r ./src/ru $TARGET_DIR/bin/
mkdir -p $TARGET_DIR/share/man/man1
cp ./doxygen-doc/man/man1/guess_number.1 $TARGET_DIR/share/man/man1/guess_number.1



