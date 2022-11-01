let arr = [ [11,2,4], [4,5,6], [10,8,-12] ]
console.log(arr[0][0])
console.log(arr.length)
console.log(arr[0].length)

let leftDiagonal = 0
let rightDiagonal = 0
let result = 0
for (let i = 0; i< arr.length; i++){
    for (let j = 0; j<arr[i].length; j++) {
        if (arr[0][0]) {
            console.log(arr[i][j]);
        }
    }
}

