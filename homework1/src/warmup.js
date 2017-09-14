function change(amount) {
  if (amount < 0) {
    throw new RangeError('RangeError: amount cannot be negative');
  }
  const result = [];
  let remaining = amount;
  [25, 10, 5, 1].forEach((coin) => {
    result.push(Math.floor(remaining / coin));
    remaining %= coin;
  });
  return result;
}

function stripQuotes(s) {
  return s.replace(/\/|'|"/gi, '');
}

function scramble(s) {
  const result = s.split('');
  for (let i = 0; i < s.length; i += 1) {
    const j = Math.floor(Math.random() * (i + 1));
    const scrambler = result[i];
    result[i] = result[j];
    result[j] = scrambler;
  }
  return result.join('');
}

function powers(base, limit, output) {
  let p = 1;
  while (p <= limit) {
    output(p);
    p *= base;
  }
}

function* powersGenerator(base, limit) {
  let number = 1;
  while (number <= limit) {
    yield number;
    number *= base;
  }
}

function say(string) {
  if (string === undefined) {
    return '';
  }
  function sayAgain(word) {

  }
}

function interleave(...args) {
  const arr = args[0];
  const arr1 = [];
  for (let i = 1; i < args.length; i += 1) {
    arr1.push(args[i]);
  }
  if (arr.length === 0) {
    return arr1;
  } else if (arr1.length === 0) {
    return arr;
  }
  const mergedArray = [];
  for (let i = 0, len = Math.max(arr.length, arr1.length); i < len; i += 1) {
    if (i < arr.length) {
      mergedArray.push(arr[i]);
    }
    if (i < arr1.length) {
      mergedArray.push(arr1[i]);
    }
  }
  return mergedArray;
}

function cylinder(c) {
  let { radius, height } = c;
  if (radius === undefined) {
    radius = 1;
  }
  if (height === undefined) {
    height = 1;
  }
  const surfaceArea = () => (2 * Math.PI * radius * height) + (2 * Math.PI * radius * radius);
  const volume = () => (Math.PI * radius * radius * height);
  const widen = (rFactor) => { radius *= rFactor; };
  const stretch = (hFactor) => { height *= hFactor; };
  const toString = () => `Cylinder with radius ${radius} and height ${height}`;
  return Object.freeze({
    get radius() {
      return radius;
    },
    get height() {
      return height;
    },
    surfaceArea,
    volume,
    widen,
    stretch,
    toString });
}

const crypto = require('crypto');

function makeCryptoFunctions(key, algorithm) {
  function encrypt(string) {
    const cipher = crypto.createCipher(algorithm, key);
    let encrypted = cipher.update(string, 'utf8', 'hex');
    encrypted += cipher.final('hex');
    return encrypted;
  }

  function decrypt(string) {
    const decipher = crypto.createDecipher(algorithm, key);
    let decrypted = decipher.update(string, 'hex', 'utf8');
    decrypted += decipher.final('utf8');
    return decrypted;
  }

  return [encrypt, decrypt];
}

function randomName(o) {
  const { gender, region } = o;
}

module.exports = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  say,
  interleave,
  cylinder,
  makeCryptoFunctions,
  randomName,
};
