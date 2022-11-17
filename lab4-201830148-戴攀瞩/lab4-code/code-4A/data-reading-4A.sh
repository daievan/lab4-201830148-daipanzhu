# !/bin/bash                       # 指定shell类型

exec 0< test1.txt
count=1                            # 赋值语句，不加空格

while read line                    # read读到的值放在line中
do 
    count=$[ $count + 1 ]          # 注意中括号中的空格
    outputparameter3=`(echo "${line}")|./a.exe`
    sleep 1
    echo "${outputparameter3}"
done


