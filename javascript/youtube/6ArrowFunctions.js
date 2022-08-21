function sum(a,b){
    return a+b
}

function isPositive(number){
    return number >=0
}

function randomNumber(){
    return Math.random
}

/* document.addEventListener('click', function(){
    console.log('Click')
}) */

//remove the function keyword because in arrow function those 'function keyword already exist'
let sum2 = (a,b) => {
    return a+b
}
//we can go even further to reduce the syntax because we only have one line of code and it returns something
let sum3 = (a,b) => a + b
//if you do this everything after the arrow is assumed to be return
let isPositive2 = (number) => {
    return number >=0
}
//if you only had 1 parameter you can remove the ()
let isPositive3 = number => number >=0
let randomNumber2 = () => {
    return Math.random
}
//with 0 parameter you have to type the ()
let randomNumber3 = () => Math.random
//arrow functions arent that useful when it comes to narrowing down the amount of words that you have to write
//arrow functions are useful to create anonymous function such as when were passing those to another function
/* document.addEventListener('click', () => {
    console.log('Click')
})
document.addEventListener('click', () => console.log('Click')) */

class Person {
    constructor(name) {
        this.name = name
    }
    printNameArrow(){
        setTimeout(() => {
            console.log('Arrow : '+this.name)
        }, 100)
    }
    printNameFunction(){
        setTimeout(function() {
            console.log('Function : '+this.name)
        }, 100)
    }
}

let person = new Person('Rezi')
person.printNameArrow()
person.printNameFunction()

//normal function didnt work
//normally these standar function syntax that we've been using since js came out it defines this based on where the function is called
//the function call down here
//so it redifined
//arrow function didnt redifined