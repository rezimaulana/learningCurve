'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'cubeSum' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY operations
 */

function cubeSum(n, operations) {
        const result = []
    const a = filler => Array(n + 1).fill(null).map(filler)
    const m = a(_ => a(_ => a(_ => 0)))
    for (const o of operations) {
        let [type, ...params] = o.split(' ')
        if (type === 'UPDATE') {
            let [x, y, z, w] = params
            m[x][y][z] = +w
        } else {
            let sum = 0
            let [x1, y1, z1, x2, y2, z2] = params
            for (let x = x1; x <= x2; x++)
                for (let y = y1; y <= y2; y++)
                    for (let z = z1; z <= z2; z++)
                        sum += m[x][y][z]
            result.push(sum)
        }
    }
    return result
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const T = parseInt(readLine().trim(), 10);

    for (let TItr = 0; TItr < T; TItr++) {
        const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');

        const matSize = parseInt(firstMultipleInput[0], 10);

        const m = parseInt(firstMultipleInput[1], 10);

        let ops = [];

        for (let i = 0; i < m; i++) {
            const opsItem = readLine();
            ops.push(opsItem);
        }

        const res = cubeSum(matSize, ops);

        ws.write(res.join('\n') + '\n');
    }

    ws.end();
}
