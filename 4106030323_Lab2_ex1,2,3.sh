#!/bin/bash

low=1
high=10
guess=-1

read -p "Please enter the target number : " target

guessNum(){
	read -p "Please enter a number between $1 and $2 : " guess
}


while [ $target -ne $guess ]

do
	guessNum $low $high
	
	if [ $guess -eq $high ]; then
		high=$((high - 1))
	elif [ $guess -eq $low ]; then
		low=$((low + 1))
	elif [ $guess -ge $target ]; then
		high=$((guess-1))
	else 
		low=$((guess+1))
	fi
done

echo "Bingo"
