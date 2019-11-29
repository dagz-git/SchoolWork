import binascii
f = open("instructions","r")
data = f.readlines()
lista = []

dick =	{

	"ADD": 0,
	"SUB": 1,
	"MUL": 2,
	"DIV": 3,

}

for x in range(len(data)):	
	lista.append(data[x].split())

print(lista)



k = open("output.hex", "wb")
for i in range(len(lista)):
	oper = format(int(dick[lista[i][0]]),'04b')
	oper2 = format(int(lista[i][1]),'04b')
	bigoper = hex(int(oper+oper2,2))[2:]
	bigoper = bigoper if len(bigoper)%2 == 0 else "0"+bigoper 
	print("Lenght " + str(len(bigoper)) + " NUM: " + oper +" " +oper)
	binstr = binascii.unhexlify(bigoper)
	k.write(binstr)

k.close()

