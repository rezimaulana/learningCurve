'use strict';

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
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

function matrixRotation(matrix, r) {
    const numberOfRows = matrix.length;
    const numberOfColumns = matrix[0].length;
    const deep = Math.floor(Math.min(numberOfRows, numberOfColumns)/2);
    for(let rep = 0; rep<r; rep++){
        for(let innerDeep = 0; innerDeep <=deep-1; innerDeep++){
        let auxRow;
        for(let i = innerDeep; i<numberOfRows - innerDeep; i++){
        const row = matrix[i];
        if(i === innerDeep){
            let aux = row[row.length-1-innerDeep]
            for(let j = row.length -1 - innerDeep; j>innerDeep; j--){
                let aux2 = aux;
                aux = row[j-1]
                row[j-1] = aux2
            }
            auxRow = aux;
        }
        if(i === matrix.length - 1 -innerDeep){
            let aux = auxRow
            for(let j = innerDeep; j<row.length - 1 - innerDeep; j++){
                let aux2 = aux;
                aux = row[j+1]
                row[j+1] = aux2
            }
            auxRow = aux;
        }else{
            let aux2 = auxRow
            auxRow = matrix[i+1][innerDeep]
            matrix[i+1][innerDeep] = aux2
        }
    }
    for(let i= matrix.length - 1 - innerDeep; i>innerDeep; i--){
        let aux2 = auxRow
        const totalLength = matrix[i-1].length
        auxRow = matrix[i-1][totalLength-1-innerDeep]
        matrix[i-1][totalLength-1-innerDeep] = aux2
    }
        }
    }
    
    const joinedMatrix = matrix.map(row => row.join(' ')).join('\n')
    console.log(joinedMatrix)

}

function main() {
    const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');

    const m = parseInt(firstMultipleInput[0], 10);

    const n = parseInt(firstMultipleInput[1], 10);

    const r = parseInt(firstMultipleInput[2], 10);

    let matrix = Array(m);

    for (let i = 0; i < m; i++) {
        matrix[i] = readLine().replace(/\s+$/g, '').split(' ').map(matrixTemp => parseInt(matrixTemp, 10));
    }

    matrixRotation(matrix, r);
}
