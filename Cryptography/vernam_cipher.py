import string

def encrypt(plain_text, key):
    
    plain_text = list(plain_text.lower())
    plain_text = "".join([char for char in plain_text if char in string.ascii_lowercase])

    key = list(key.lower())
    key = "".join([char for char in key if char in string.ascii_lowercase])

    if(len(plain_text) != len(key)):
        return -1

    cipher_text = ""
    for idx, letter in enumerate(plain_text):
        
        x = ord(letter) - ord('a')
        k = ord(key[idx % len(key)]) - ord('a')

        letter = chr((x + k) % 26 + ord('a'))
        cipher_text += letter
    
    return cipher_text

def decrypt(cipher_text, key):
   
    cipher_text = list(cipher_text.lower())
    cipher_text = "".join([char for char in cipher_text if char in string.ascii_lowercase])

    key = list(key.lower())
    key = "".join([char for char in key if char in string.ascii_lowercase])

    if(len(cipher_text) != len(key)):
        return -1

    plain_text = ""
    for idx, letter in enumerate(cipher_text):
        
        x = ord(letter) - ord('a')
        k = ord(key[idx % len(key)]) - ord('a')

        letter = chr((x - k) % 26 + ord('a'))
        plain_text += letter
    
    return plain_text

text = "VernamCipher"
for key in ["Alliteration", "Pennsylvania", "Intelligence"]:
    if(decrypt(encrypt(text, key), key) != text.lower()):
        assert False
else:
    print("Test Passed - Vernam Cipher !!!")
    assert True