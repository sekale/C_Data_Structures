
def rom_number_converter(roman_number):
	#print(roman_number)
	roman_number_hashtable = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C': 100, 'D' : 500, 'M' : 1000}
	i = 0
	current_number = 0
	while (i <= len(roman_number) - 1):

		if(i + 1 >= len(roman_number)):
			current_number = current_number + roman_number_hashtable[roman_number[i]]
			#print('here')
			i = i + 1

		else:
			if(roman_number_hashtable[roman_number[i]] >= roman_number_hashtable[roman_number[i+1]]):
				#print('here1' + roman_number[i])
				current_number = current_number + roman_number_hashtable[roman_number[i]]
				i = i + 1
			else:
				#print('here2' + roman_number[i])
				current_number += roman_number_hashtable[roman_number[i+1]] - roman_number_hashtable[roman_number[i]]
				i = i + 2

	return current_number

	#print(current_number)
		
if __name__ == "__main__":
	list_names = []
	#rom_number_converter('DCXXI')
