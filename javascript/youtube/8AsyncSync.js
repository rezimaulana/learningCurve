//async start out very similiar, start at the top and execute the code until it gets to the bottom but during that execution it'll run into
//certain async functions or code or it will split off and execute that async code seperately from the rest of the code
//thats usually because it needs to wait, reduce some operations that takes a long period time
//sync will start at the very top of the file and execute all the way down to the bottom of file each line in order until it gets to the bottom and it will stop

let a = 1
let b = 2

setTimeout(function(){
    console.log('Asynchronous Timeout: '+a)
}, 100)

a = 10
//it always better to put variabel into the async function other than relying on them from the outside the async

/* fetch('/').then(function(){
    console.log('Fetch')
}) */

console.log('Synchronous')
console.log(a)
console.log(b)