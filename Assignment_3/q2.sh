
echo "Enter valid operator add,sub,div and exp"

read operation
add(){
    
    echo $(($1 + $2))
}
sub(){
    echo subtracting..
    echo $(($1 - $2))
}
div(){
    echo dividing..
    echo $(($1 / $2))
}
exp(){
    echo calculating exponential..
    echo $(($1 ** $2))
}
echo "Enter numbers space seperated"
read num1 num2

case "$operation" in
    "add")    
            
            add $num1 $num2;;
    "sub")
        sub $num1 $num2;;
    "div")
        div $num1 $num2;;
    "exp")
        exp $num1 $num2;; 
esac 
