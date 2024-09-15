while True:
    horas, minutos = [int(x) for x in input().split(":")]
    
    if not horas and not minutos:
        break
    
    graus = abs(((horas % 12) * 30 + (minutos / 60) * 30)-(minutos*6))
    
    graus = min(graus, 360-graus)
    print(f"{graus:.3f}")