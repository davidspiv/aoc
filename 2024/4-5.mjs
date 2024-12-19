import { readFileSync } from 'node:fs';

//2709 too high

const str = readFileSync('./2024/4.dat', { encoding: 'utf8' });
const grid = str.split('\n').map((row) => row.split(''));

function main() {
	const numRows = grid.length;
	const numCols = grid[0].length;
	let cout = 0;

	for (let row = 0; row < numRows; row++) {
		for (let col = 0; col < numCols; col++) {
			if (grid[row][col] === 'A') {
				cout += diag1(row, col) && diag2(row, col);
			}
		}
	}
	console.log(cout);
}

function diag1(row, col) {
	const char1 = grid[row - 1]?.[col - 1] || '';
	const char2 = grid[row + 1]?.[col + 1] || '';
	if (`${char1}${char2}` === 'MS' || `${char1}${char2}` === 'SM') {
		return true;
	}
	return false;
}

function diag2(row, col) {
	const char1 = grid[row - 1]?.[col + 1] || '';
	const char2 = grid[row + 1]?.[col - 1] || '';
	if (`${char1}${char2}` === 'MS' || `${char1}${char2}` === 'SM') {
		return true;
	}
	return false;
}

main();
