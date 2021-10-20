
#!/bin/bash
#storing number of days in each month in variable "days"
case $2 in
01) days=31
;;
02) days=28
;;
03) days=31
;;
04) days=30
;;
05) days=31
;;
06) days=30
;;
07) days=31
;;
08) days=31
;;
09) days=30
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

#checking for invalid date
if [[ $days -le $1 ]];
then 
    
    echo "invalid date $1 for $2 month"
    exit 1
fi

echo
echo "The calender for given month and year is: "
echo
#passing month and year in cal function
cal  $2 $3
