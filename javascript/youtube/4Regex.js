//regular expression help search through text
function filterRegex(str){
    let result = str.match(/[aiueo]/gi)
    return result
}

let text = "The fat cat ran down the street. It was searching for a mouse to eat."

console.log(filterRegex(text).join(''))

let no1 = "1234567890"
let no2 = "123-456-7890"
let no3 = "123 456 7890"
let no4 = "(123) 456-7890"
let no5 = "+1 123 456 7890"