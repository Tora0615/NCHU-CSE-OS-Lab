low = 1
high = 10
guess = -1

target = int(input("Please enter the target number : "))

def guessNum(a,b) : 
	msg = "Please enter a number between " + str(a) + " and " + str(b) + ": "
	return int(input(msg))

while target != guess :
	guess = guessNum(low,high)

	if ( guess == high ):
		high = high -1
	elif ( guess == low):
		low = low + 1
	elif ( guess > target):
		high = guess - 1
	else :
		low = guess + 1

print("Bingo!")
