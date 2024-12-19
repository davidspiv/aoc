import { readFileSync } from 'node:fs';

function main() {
	const str = readFileSync('./2024/4.dat', { encoding: 'utf8' });
	const grid = str.split('\n').map((row) => row.split(''));
	const numRows = grid.length;
	const numCols = grid[0].length;
	const cartesianOctants = [
		[0, -1],
		[0, 1],
		[-1, 0],
		[1, 0],
		[1, 1],
		[1, -1],
		[-1, 1],
		[-1, -1],
	];
	let cout = 0;

	for (let row = 0; row < numRows; row++) {
		for (let col = 0; col < numCols; col++) {
			if (grid[row][col] === 'X') {
				for (const [rowDir, colDir] of cartesianOctants) {
					const char1 = grid[row + 1 * rowDir]?.[col + 1 * colDir] || '';
					const char2 = grid[row + 2 * rowDir]?.[col + 2 * colDir] || '';
					const char3 = grid[row + 3 * rowDir]?.[col + 3 * colDir] || '';
					cout += `${char1}${char2}${char3}` === 'MAS';
				}
			}
		}
	}
	console.log(cout);
}

main();
