import datetime

meses = {
    "January": 1,
    "February": 2,
    "March": 3,
    "April": 4,
    "May": 5,
    "June": 6,
    "July": 7,
    "August": 8,
    "September": 9,
    "October": 10,
    "November": 11,
    "December": 12
}


n = int(input())

for i in range(n):
    ano, mes, dia = input().split("-")
    ano = int(ano)
    dia = int(dia)
    mes = meses[mes]
    dias_mais = int(input())
    
    date = datetime.datetime(ano, mes, dia)
    resultado = date + datetime.timedelta(days=dias_mais)
    print(f"Case {i+1}: {resultado.strftime('%Y-%B-%d')}")