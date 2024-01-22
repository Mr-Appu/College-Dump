import string

def get_matrix(key):

    matrix = {}
    idx = 0

    for char in key + string.ascii_lowercase:
        
        if char in 'ij' and char not in matrix:
            matrix['i'] = (idx//5, idx%5)
            matrix['j'] = (idx//5, idx%5)
            idx += 1

        if char not in matrix:
            matrix[char] = (idx//5, idx%5)
            idx += 1

    inverse_matrix = {t:char for char, t in matrix.items()}

    return matrix, inverse_matrix

def get_digraph(plain_text):

    di_graph = []

    plain_text = list(plain_text)
    while(plain_text):
        
        first = plain_text.pop(0) if plain_text else None
        second = plain_text.pop(0) if plain_text else None

        if first == second:
            di_graph.append(first + "x") # Filler letter - x
            plain_text.insert(0, second)
            continue

        if second == None:
            di_graph.append(first + "x") # Filler letter - x
            continue

        di_graph.append(first + second)

    return di_graph

def encrypt(plain_text, key):

    plain_text = list(plain_text.lower())
    plain_text = "".join([char for char in plain_text if char in string.ascii_lowercase])

    key = list(key.lower())
    key = "".join([char for char in key if char in string.ascii_lowercase])

    matrix_key, matrix_index = get_matrix(key)
    
    if("i" in matrix_index):
        plain_text.replace("j", "i")
    else:
        plain_text.replace("i", "j")

    di_graph = get_digraph(plain_text)

    cipher_text = ""
    for pair in di_graph:

        x1, y1 = matrix_key[pair[0]]
        x2, y2 = matrix_key[pair[1]]

        new_pair = ""

        if x1 == x2:
            new_pair += matrix_index[(x1, (y1 + 1) % 5)]
            new_pair += matrix_index[(x2, (y2 + 1) % 5)]
        elif y1 == y2:
            new_pair += matrix_index[((x1 + 1) % 5, y1)]
            new_pair += matrix_index[((x2 + 1) % 5, y2)]
        else:
            new_pair += matrix_index[(x1, y2)]
            new_pair += matrix_index[(x2, y1)]
        
        cipher_text += new_pair

    return cipher_text

def decrypt(cipher_text, key):

    cipher_text = list(cipher_text.lower())
    cipher_text = "".join([char for char in cipher_text if char in string.ascii_lowercase])

    key = list(key.lower())
    key = "".join([char for char in key if char in string.ascii_lowercase])

    matrix_key, matrix_index = get_matrix(key)
    
    if("i" in matrix_index):
        cipher_text.replace("j", "i")
    else:
        cipher_text.replace("i", "j")

    di_graph = get_digraph(cipher_text)

    plain_text = ""
    for pair in di_graph:

        x1, y1 = matrix_key[pair[0]]
        x2, y2 = matrix_key[pair[1]]

        new_pair = ""

        if x1 == x2:
            new_pair += matrix_index[(x1, (y1 - 1) % 5)]
            new_pair += matrix_index[(x2, (y2 - 1) % 5)]
        elif y1 == y2:
            new_pair += matrix_index[((x1 - 1) % 5, y1)]
            new_pair += matrix_index[((x2 - 1) % 5, y2)]
        else:
            new_pair += matrix_index[(x1, y2)]
            new_pair += matrix_index[(x2, y1)]
        
        plain_text += new_pair

    return plain_text

print(encrypt("cosmec means communications security", "galois"))
print(decrypt("dldfsdndjhbddtntuebluojmcvbserulyo", "galois"))
