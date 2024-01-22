import string

def encrypt(plain_text, key):
    
    key = [(char, idx) for idx, char in enumerate(key.lower())]
    key.sort(key = lambda x : x[0])

    n = len(key)
    
    cipher_list = ["" for _ in range(n)]
    for idx, char in enumerate(plain_text):
        cipher_list[idx % n] += char

    cipher_text = ""
    for char, idx in key:
        cipher_text += cipher_list[idx]

    return cipher_text

    
def decrypt(cipher_text, key):

    key = [[char, idx, 0, None] for idx, char in enumerate(key.lower())]
    
    n = len(key)
    for idx in range(len(cipher_text)):
        key[idx % n][2] += 1

    key.sort(key = lambda x : x[0])
    
    index = 0
    for idx in range(n):
        key[idx][3] = list(cipher_text[index: index + key[idx][2]])
        index += key[idx][2]

    key.sort(key = lambda x : x[1])

    plain_text = ""
    for idx in range(len(cipher_text)):
        plain_text += key[idx % n][3].pop(0)
   
    return plain_text

text = "Hello World, Testing Columnar Transposition !!!"
keys = ["dough", "provincial", "master", "adventure"]

for key in keys:
    if decrypt(encrypt(text, key), key) != text:
        assert False
else:
    assert True
    print("Test Passed - Rail Columnar Transposition !!!")