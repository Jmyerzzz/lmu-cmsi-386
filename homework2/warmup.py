import json
import math
import random
import re
import requests
from Crypto.Cipher import AES

def change(amount):
    if amount < 0:
        raise ValueError('amount cannot be negative')
    result = []
    remaining = amount
    for coin in (25, 10, 5, 1):
        result.append(remaining // coin)
        remaining %= coin
    return tuple(result)

def strip_quotes(string):
    p = re.compile('(\'|\")')
    return p.sub('', string)

def scramble(string):
    return ''.join(random.sample(string, len(string)))

def say(string=''):
    if not string:
        return ''
    def sayMore(word=''):
        if not word:
            return string
        combinedString = string + ' ' + word
        return say(combinedString)
    return sayMore

def triples(limit):
    result = []
    if limit == 0:
        return result
    for x in range(1, limit+1):
        y = x+1
        z = y+1
        while z <= limit:
            while z * z < x * x + y * y:
                z = z + 1
            if z * z == x * x + y * y and z <= limit:
                result.append((x,y,z))
            y = y + 1
    return result

def powers(base, limit):
    number = 1
    while number <= limit:
        yield number
        number *= base

def interleave(arr, *argv):
    arr1 = arr
    arr2 = []
    for arg in argv:
        arr2.append(arg)
    if len(arr1) == 0:
        return arr2
    if len(arr2) == 0:
        return arr1
    mergedArray = []
    length = max(len(arr1), len(arr2))
    for i in range(0, length):
        if i < len(arr1):
            mergedArray.append(arr1[i])
        if i < len(arr2):
            mergedArray.append(arr2[i])
    return mergedArray

class Cylinder:
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height
    def volume(self):
        return math.pi * (self.radius ** 2) * self.height
    def surface_area(self):
        return (2* math.pi * self.radius * self.height) + (2 * math.pi * (self.radius **2))
    def widen(self, wFactor):
        self.radius *= wFactor
        return self
    def stretch(self, sFactor):
        self.height *= sFactor
        return self

def make_crypto_functions(key, iv):
    def encrypt(byte):
        cipher = AES.new(key, AES.MODE_CBC, iv)
        return cipher.encrypt(byte)

    def decrypt(byte):
        cipher = AES.new(key, AES.MODE_CBC, iv)
        return cipher.decrypt(byte)

    return (encrypt, decrypt)

def random_name(**kwargs):
    if kwargs['gender'] != 'male' and kwargs['gender'] != 'female':
        raise ValueError('{"error":"Invalid gender"}')
    apiRequest = requests.get('https://uinames.com/api/?amount=1', params=kwargs)
    jsonData = json.loads(apiRequest.text)
    return '{}, {}'.format(jsonData['surname'], jsonData['name'])
