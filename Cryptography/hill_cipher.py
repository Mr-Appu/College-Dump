# Hill Cipher for key = 2x2 matrix

import numpy as np
import string

def get_digraph(text):

    text += "x" if len(text)%2 else ""

    di_graph = []
    for idx in range(0, len(text), 2):

        first = ord(text[idx]) - ord('a')
        second = ord(text[idx + 1]) - ord('a')
        
        di_graph.append(np.array([first, second]))

    return di_graph

def convert(di_graph, key):

    di_graph_c = []
    for pair in di_graph:
        di_graph_c.append(np.matmul(key, pair) % 26)

    return di_graph_c

def get_text(di_graph):
    
    text = ""
    for pair in di_graph:
        first = chr(pair[0] + ord('a'))
        second = chr(pair[1] + ord('a'))
        text += first + second

    return text

def get_inverse(matrix):
    
    inverse = np.linalg.inv(matrix) 
    det = int(np.linalg.det(matrix))
    
    adjoint = (inverse * det)
    det_mod_inv =  pow(det, -1, 26)

    inverse = np.round((adjoint * det_mod_inv) % 26)
    inverse = inverse.astype(np.int32)

    return inverse

def encrypt(plain_text, key):

    plain_text = list(plain_text.lower())
    plain_text = "".join([char for char in plain_text if char in string.ascii_lowercase])

    key = np.array(key)
    if(key.shape != (2, 2)):
        return -1

    di_graph = get_digraph(plain_text)
    di_graph = convert(di_graph, key)

    cipher_text = get_text(di_graph)

    return cipher_text

def decrypt(cipher_text, key):

    cipher_text = list(cipher_text.lower())
    cipher_text = "".join([char for char in cipher_text if char in string.ascii_lowercase])

    key = np.array(key)
    if(key.shape != (2, 2)):
        return -1
    
    key = get_inverse(key)

    di_graph = get_digraph(cipher_text)
    di_graph = convert(di_graph, key)

    plain_text = get_text(di_graph)

    return plain_text

print(encrypt("herbert yardley wrote the american black chamber", [[9, 4], [5, 7]]))
print(decrypt("blboajhdqptocggvuvixblwgajccanbeioumljipaj", [[9, 4], [5, 7]]))