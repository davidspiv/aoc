import { readFileSync } from 'node:fs';

//append 'do()' to end of string to ensure regex works for all cases
const str = `${readFileSync('3.dat', { encoding: 'utf8' })}do()`;
const regexp1 = /don't\(\).*?do\(\)+/gs;
const newString = str.replace(regexp1, '');
const regexp2 = /mul\(([0-9]{1,3}),([0-9]{1,3})\)/g;
const matches = [...newString.matchAll(regexp2)];
let total = 0;

for (let i = 0; i < matches.length; i++) {
	const factor1 = Number.parseInt(matches[i][1]);
	const factor2 = Number.parseInt(matches[i][2]);
	total += factor1 * factor2;
}

console.log(total);
