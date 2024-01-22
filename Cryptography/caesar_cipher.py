import string

def encrypt(plain_text, key):
    
    plain_text = list(plain_text.lower())
    plain_text = "".join([char for char in plain_text if char in string.ascii_lowercase])

    cipher_text = ""
    for letter in plain_text:
        if letter in string.ascii_lowercase:
            letter = chr(((ord(letter) - ord('a')) + key) % 26 + ord('a')) 
        cipher_text += letter
    
    return cipher_text

def decrypt(cipher_text, key):

    cipher_text = list(cipher_text.lower())
    cipher_text = "".join([char for char in cipher_text if char in string.ascii_lowercase])

    plain_text = ""
    for letter in cipher_text:
        if letter in string.ascii_lowercase:
            letter = chr(((ord(letter) - ord('a')) - key) % 26 + ord('a')) 
        plain_text += letter
    
    return plain_text


text = "Hello world !!!, TESTING Caesar Cipher !!!"
for key in range(100):
    if(decrypt(encrypt(text, key), key) != text.lower()):
        assert False
else:
    print("Test Passed - Caesar Cipher !!!")
    assert True