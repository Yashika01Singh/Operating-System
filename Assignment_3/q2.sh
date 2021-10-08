
#Enter valid operator add,sub,div and exp"
array=("$@")


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

operation=${array[0]}
unset array[0]


num1=${array[1]}
unset array[1]





case "$operation" in
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
