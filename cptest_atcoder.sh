problemname=$1
oj dl "https://${problemname:0:-2}.contest.atcoder.jp/tasks/${problemname}"
#oj dl "https://${problemname:0:-3}.contest.atcoder.jp/tasks/${problemname}"

#g++ -Wall -std=c++14 main.cpp
# abcxxx_y形式の時
g++ -Wall -std=c++14 "${problemname:0:3}/${problemname:3:-2}/${problemname: -1:1}".cpp -I .
cp "${problemname:0:3}/${problemname:3:-2}/${problemname: -1:1}".cpp main.cpp

# dp_y形式の時
#g++ -Wall -std=c++14 "${problemname:0:2}/${problemname: -1:1}".cpp -I .
#cp "${problemname:0:2}/${problemname: -1:1}".cpp main.cpp

oj test --ignore-spaces
#oj test -c "python3 main.py"
rm -f a.out
rm -rf test

