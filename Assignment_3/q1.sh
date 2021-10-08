
#!/bin/bash
case $2 in
1) days=31
;;
2) days=28
;;
3) days=31
;;
4) days=30
;;
5) days=31
;;
6) days=30
;;
7) days=31
;;
8) days=31
;;
9) days=30
;;
10) days=31
;;
11) days=30
;;
12) days=31
;;
*) days=-1
;;
esac

if [[ $days -ne $1 ]];
then 
    
    echo "invalid date $1 for $2 month"
    exit 1
fi

echo
echo "The calender for given month and year is: "
echo
cal  $2 $3
