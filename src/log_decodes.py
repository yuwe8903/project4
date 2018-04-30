
# saved all the data from terminal to log.txt
with open('log.txt', 'r') as log_file:
	log_read = log_file.read()
	print(log_read)
