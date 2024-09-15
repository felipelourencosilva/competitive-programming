while True:
    text = input().strip()
    if text == "DONE":
        break
    
    text = text.replace(" ", "").replace(".", "").replace("!", "").replace(",", "").replace("?", "").lower()
    
    i = 0
    j = len(text) - 1
    flag = True
    
    while i < j:
        if text[i] != text[j]:
            print("Uh oh..")
            flag = False
            break
        i += 1
        j -= 1
            
    if flag:
        print("You won't be eaten!")