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
        combined_string = string + ' ' + word
        return say(combined_string)
    return sayMore

def triples(limit):
    "Finds all pythagorean triples up to the limit"
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
    "Generates powers of a base up to the limit"
    number = 1
    while number <= limit:
        yield number
        number *= base

def interleave(arr, *argv):
    "Combines two arrays in alternating pattern"
    arr1 = arr
    arr2 = []
    for arg in argv:
        arr2.append(arg)
    if len(arr1) == 0:
        return arr2
    if len(arr2) == 0:
        return arr1
    merged_array = []
    length = max(len(arr1), len(arr2))
    for i in range(0, length):
        if i < len(arr1):
            merged_array.append(arr1[i])
        if i < len(arr2):
            merged_array.append(arr2[i])
    return merged_array

class Cylinder:
    "A cylinder with a radius and height."
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height

    def widen(self, width_factor):
        "Increases radius by a factor"
        self.radius *= width_factor

    def stretch(self, height_factor):
        "Increases height by a factor"
        self.height *= height_factor

    @property
    def volume(self):
        return math.pi * (self.radius ** 2) * self.height

    @property
    def surface_area(self):
        return (2 * math.pi * self.radius * self.height) + (2 * math.pi * (self.radius ** 2))

def make_crypto_functions(key, iv):
    "Returns two functions"
    def encrypt(byte):
        "Encrypts a string"
        cipher = AES.new(key, AES.MODE_CBC, iv)
        return cipher.encrypt(byte)

    def decrypt(byte):
        "Decrypts a string"
        cipher = AES.new(key, AES.MODE_CBC, iv)
        return cipher.decrypt(byte)

    return (encrypt, decrypt)

def random_name(**kwargs):
    "Fetches random name using uinames API"
    if kwargs['gender'] != 'male' and kwargs['gender'] != 'female':
        raise ValueError('{"error":"Invalid gender"}')
    api_request = requests.get('https://uinames.com/api/?amount=1', params=kwargs)
    json_data = json.loads(api_request.text)
    return '{}, {}'.format(json_data['surname'], json_data['name'])
