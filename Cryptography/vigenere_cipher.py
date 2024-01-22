import string

def encrypt(plain_text, key):
    
    plain_text = list(plain_text.lower())
    plain_text = "".join([char for char in plain_text if char in string.ascii_lowercase])

    key = key.lower()

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

    key = key.lower()

    plain_text = ""
    for idx, letter in enumerate(cipher_text):
        
        x = ord(letter) - ord('a')
        k = ord(key[idx % len(key)]) - ord('a')

        letter = chr((x - k) % 26 + ord('a'))
        plain_text += letter
    
    return plain_text

text = "VigenereCipher"
for key in ["hello", "random", "test", "qwert"]:
    if(decrypt(encrypt(text, key), key) != text.lower()):
        assert False
else:
    print("Test Passed - Vigenere Cipher !!!")
    assert True