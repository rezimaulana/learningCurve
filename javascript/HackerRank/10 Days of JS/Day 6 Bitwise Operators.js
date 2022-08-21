'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function getMaxLessThanK(n,k) {
    let max =0
    for(let a=n; a>1; a--) {
        for(let b=a-1; b>0; b--) {
            if(a & b < k && a & b > max) {
                max = a & b
            }
        }
    }
    return max    
}
