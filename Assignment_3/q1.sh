
#!/bin/bash
echo "Enter a date in (DD MM YYYY) format:"

read date

echo date is $date
echo
echo "The calender for given month and year is: "
echo
cal  ${date:3}
