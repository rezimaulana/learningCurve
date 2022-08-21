//all the other methods here, they dont change the underlying object  
const items = [
    {name: 'Bike', price: 100},
    {name: 'Tv', price: 200},
    {name: 'Album', price: 10},
    {name: 'Book', price: 5},
    {name: 'Phone', price: 500},
    {name: 'Computer', price: 1000},
    {name: 'Keyboard', price: 25}
]
console.log(items)
//filter to get rid anything thas doesnt match condition
const filteredItems = items.filter((item)=>{
    return item.price <= 100
})
console.log(filteredItems)
//map take an object to get only names or single key or take one array and convert it to another array it has 
const itemNames = items.map((item)=>{
    return item.name
})
console.log(itemNames)
//find allows you to take single object in an array 
//this just going to return the very first item that it finds in the array
const foundItem = items.find((item)=>{
    return item.name === 'book'
})
console.log(foundItem)
//forEach 
//doesnt using return so we no longer need variabel
items.forEach((item)=>{
    console.log(item.name)
})
//some
//going to return true or false, it just check arrays to see if anything in the array returns true for this and if it does the entire thing return true
const hasInexpensiveItems = items.some((item)=>{
    return item.price <= 100
})
console.log(hasInexpensiveItems)
//every
//is very similiar to some, except instead of checking for atleast one item it checks to make sure every single item falls under that
const hasEnexpensiveItems = items.every((item)=>{
    return item.price <= 100
})
console.log(hasEnexpensiveItems)
//reduce
//to get the total price of all the different items in this array, normally what you do is you would just do a for loop 
const total = items.reduce((currentTotal, item)=>{
    return item.price + currentTotal
}, 0)
console.log(total)
//includes
//is going to check if whatever we pass in the includes method is inside of the array
const numbers = [1,2,3,4,5]
const includesTwo = numbers.includes(2)
console.log(includesTwo)
