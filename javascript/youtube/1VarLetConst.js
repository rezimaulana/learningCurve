// 2 blocks
if(true){
    var varVariable='This is true' //function scope if there's no function then globally scope
    //available outside this block
}

var varVariable='This is false' //var variable can be reassigned multiple times by redeclaring varible
// let and const cannot be redeclare

console.log(varVariable)

if(true){
    let letVariable='This is true' //block scope
    console.log(letVariable) //available inside this
    const constVariable='This is true' //block scope
    console.log(constVariable) //available inside this
    //if you console log in the outside it will be error
}

/* var allow us to create variabel after we use it and still allow to go through and say that variabel is exist but the value is undefined
console.log(varVariable)
var varVariable='This is true' 
console.log(varVariable) 
let and const didnt allow us to do that it need to define first*/

/* constant didnt allow you to redeclare variabel
thats essentially the only thing that constant prevents us from doing
const is exactly the same as let otherwise 
const constVar = 1
let letVar = 1
letVar = 2
constVar = 2
console.log(letVar)
console.log(constVar) */

//but const does allow us to actually change the properties of the object if its an object
const constVar = {name: 'Bob'}
constVar.name = 'sally'
console.log(constVar)