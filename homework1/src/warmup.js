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

function powersGenerator(base, limit, output) {
  let number = 1;
  let end = false;
  function next() {
    output({ number, end });
    number *= base;
    if (number >= limit) {
      end = true;
      number = undefined;
    }
  }
}

function interleave() {

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
  return Object.freeze({ radius, height, surfaceArea, volume, widen, stretch, toString });
}


module.exports = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  interleave,
  cylinder,
};
