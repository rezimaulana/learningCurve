//recursion is the functions that calls itself
//call itself inside of the functions
//you had to have some exit conditions that jumps you out of the recursion so the function stop call itself over and over again

//normal functions
function countDown(n){
    for (let i = n; i > 0; i--){
        console.log(i)
    }
    console.log('Hooray')
}
countDown(3)

//recursive
function countDownRecursive(n){
    if (n<=0){
        console.log('Hooray')
        return
    }//breakout statement
    console.log(n)
    countDownRecursive(n-1)
}

countDownRecursive(3)

//normal functions
function sumRange(n){
    let total = 0;
    for (let i = n; i>0; i--){
        total += i
    }
    return total
}

console.log(sumRange(3))

//recursive  functions
function sumRangeRecursive(n, total = 0){
    if (n<=0){
        return total
    }
    return sumRangeRecursive(n-1, total + n)
}

console.log(sumRangeRecursive(3))
//you didnt have to use recursion on 2 example above
//but the next code you always have to use it

function printChildren(t){
    //cannot be implemented on normal functions, you can do it but very complex and almost impossible
}

function printChildrenRecursive(t){
    if(t.children.length === 0) {
        return 
    }
    t.children.forEach(child => {
        console.log(child.name)
        printChildrenRecursive(child)
    })
}

const tree = {
    name: 'John',
    children: [
        {
            name: 'Jim',
            children: []
        },
        {
            name: 'Zoe',
            children: [
                {name: 'Kyle', children: []},
                {name: 'Sophia', children: []}
            ]
        }
    ]
}

console.log(printChildrenRecursive(tree))
//very difficult to do it with normal functions loop because you dont know how deeply nested these children could be
//they could be nested 2 level deep or they can be nested 100 level deep
