# !/bin/bash                       # 指定shell类型

exec 0< test2.txt
count=0                           # 赋值语句，不加空格
a=0
b=0
while read line                    # read读到的值放在line中
do 
    count=$[ $count + 1 ]          # 注意中括号中的空格
    if((count%2==0)); then
    b=${line}
    outputparameter=`(echo "${a}";echo "${b}")|./a.exe`
    echo "${outputparameter}"
    else
    a=${line}
    fi
#    echo "${count}"
#    echo "${a}"
#    echo "${b}"   
#    sleep 1
done


