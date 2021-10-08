
#Enter valid operator add,sub,div and exp"
array=("$@")
#storing all command line input in array

add(){
    
    echo $(($1 + $2))
}
sub(){
    
    echo $(($1 - $2))
}
div(){
    
    echo $(($1 / $2))
}
exp(){
    
    echo $(($1 ** $2))
}
# "For more than two numbers, result of previous two will be operated with next"
#storing array[0] i.e. first argument in operation
operation=${array[0]}
unset array[0]
#unsetting array[0]
#storing array[1] i.e. first operands num1
num1=${array[1]}
unset array[1]





case "$operation" in
    #repitedly updating num1 by storing result of next element and num1 
    "add")    

            for i in ${array[@]}; do
                num1=$(add $num1 $i)
            done
            echo $num1 ;;
    "sub")
        for i in ${array[@]}; do
                num1=$(sub $num1 $i)
            done
            echo $num1 ;;
        
    "div")
        for i in ${array[@]}; do
                num1=$(div $num1 $i)
            done
            echo $num1 ;;
        
    "exp")
        for i in ${array[@]}; do
                num1=$(exp $num1 $i)
            done
            echo $num1 ;;
    *) 
        echo "Enter valid operator add sub div or exp" 
        exit 1
        
esac 
