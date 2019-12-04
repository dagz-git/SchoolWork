import binascii
f = open("inst.asm","r")
data = f.readlines()
lista = []

dic = {

	"ADD" : 0,
	"SUB" : 1,
	"MUL" : 2,
	"DIV" : 3
}

lista = [ data[x].split() for x in range(len(data)) ]

k = open("output.hex", "wb")
for i in range(len(lista)):
	
	oper = format(int(dic[lista[i][0]]),'04b')
	oper2 = format(int(lista[i][1]),'04b')

	bigoper = hex(int(oper+oper2,2))[2:]
	bigoper = bigoper if len(bigoper)%2 == 0 else "0"+bigoper 
	
	print(f'Data: {lista[i]} Length: {len(bigoper)} NUM: {oper} {oper2} HEX NUM: {bigoper}')
	
	binstr = binascii.unhexlify(bigoper)
	k.write(binstr)

k.close()

