import string

def encrypt(plain_text, key):
    
    cipher_text = ['' for _ in range(key)]
    
    dir = 1
    rail = 0

    for char in plain_text:
        cipher_text[rail] += char
        rail += dir

        if rail == 0 or rail == key-1:
            dir *= -1

    cipher_text = "".join(cipher_text)

    return cipher_text

    
def decrypt(cipher_text, key):
   
    rail_text = ['' for _ in range(key)]
    dir = 1
    rail = 0

    for _ in cipher_text:
        rail_text[rail] += " "
        rail += dir

        if rail == 0 or rail == key-1:
            dir *= -1
    
    idx = 0
    for i, texts in enumerate(rail_text):
        rail_text[i] = list(cipher_text[idx: idx+len(rail_text[i])])
        idx += len(rail_text[i])

    plain_text = ""
    dir = 1
    rail = 0

    for _ in cipher_text:
        plain_text += rail_text[rail].pop(0)
        rail += dir

        if rail == 0 or rail == key-1:
            dir *= -1

    return plain_text

text = "Hello World, Testing Rail Fence Cipher !!!"
for key in range(2, len(text)+10):
    if decrypt(encrypt(text, key), key) != text:
        assert False
else:
    assert True
    print("Test Passed - Rail Fence Cipher !!!")