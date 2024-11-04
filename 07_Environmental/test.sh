# getline
make clean
make gitclean
autoreconf -fisv
./configure
make

# 1
echo -n 'asdfghjkl' | md5sum | cut -d ' ' -f 1 > a.out
echo -n -e "\n" >> a.out
echo 'MD5 "asdfghjkl' | ./rhasher | cut -d ' ' -f 2 > b.out
cmp a.out b.out
# 2
md5sum ./rhasher.c | cut -d ' ' -f 1 > a.out
echo -n -e "\n" >> a.out
echo 'MD5 rhasher.c' | ./rhasher | cut -d ' ' -f 2 > b.out
cmp a.out b.out
# 3
echo -n 'asdfghjkl' | sha1sum | cut -d ' ' -f 1 > a.out
echo -n -e "\n" >> a.out
echo 'SHA1 "asdfghjkl' | ./rhasher | cut -d ' ' -f 2 > b.out
cmp a.out b.out
# 4
sha1sum ./rhasher.c | cut -d ' ' -f 1 > a.out
echo -n -e "\n" >> a.out
echo 'SHA1 rhasher.c' | ./rhasher | cut -d ' ' -f 2 > b.out
cmp a.out b.out


