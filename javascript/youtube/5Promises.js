//promise either have two result, either that promise has completed it is resolved or that promise is failed and it is rejected
let p = new Promise((resolve, reject) => {
    let a = 1 + 1
    if (a == 2) {
        resolve('Success')
    } else {
        reject('Failed')
    }
})

p.then((message) => {
    console.log('This is in the then '+message)
}).catch((message) => {
    console.log('This is in the catch '+message)
})

//promises are really great when you need to do something that's going to take long time in the background
//you just want to do something after it;s completed instead of making everything else wait for it
//then also you can catch it to see if its fail so the way you can retry it or give the user error message if it did fail
//promise are meant to replace callback

//using callback
const userLeft = false
const userWatchingCatMeme = true

function watchTutorialCallback(callback, errorCallback) {
    if (userLeft) {
        errorCallback({
            name: 'User Left',
            message: ':('
        })
    } else if (userWatchingCatMeme) {
        errorCallback({
            name: 'User Watching Cat Meme',
            message: 'WebDevSimplified < Cat'    
        })
    } else {
        callback('Thumbs up and Subscribe')
    }
}

watchTutorialCallback((message) => {
    console.log('Success ' +message)
}, (error) => {
    console.log(error.name+' '+error.message)
})
//true + true = User Left :(
//false + false = Thumbs up and Subscribe
//true + false = User Left :(
//false + true = User Watching Cat Meme WebDevSimplified < Cat

//using promises
//we can completely remove both of these callback functions for parameters
//the whole point to use promise is that we have no longer have these callback all we need to do is return a promise
function watchTutorialPromises() {
    return new Promise((resolve, reject) => {
        if (userLeft) {
            reject({
                name: 'User Left',
                message: ':('
            })
        } else if (userWatchingCatMeme) {
            reject({
                name: 'User Watching Cat Meme',
                message: 'WebDevSimplified < Cat'    
            })
        } else {
            resolve('Thumbs up and Subscribe')
        }
    })
}

watchTutorialPromises().then((message) => {
    console.log('Success ' +message)
}).catch((error) => {
    console.log(error.name+' '+error.message)
})

//instead of using callbacks as you can see the code is a lot cleaner to write than with it using callbacks
//because as you start nesting callbacks you started to get in a huge world of trouble where your code just keeps getting indented to indented even further
//use the promises instead of nesting callbacks all you do is just add another then so it would look just like this
//you would have then and then, instead of having a callback inside of a callback inside of a callback
//which is whats known as callbacks hell

const recordVideoOne = new Promise((resolve, reject) => {
    resolve('Video 1 Recorded')
})
const recordVideoTwo = new Promise((resolve, reject) => {
    resolve('Video 2 Recorded')
})
const recordVideoThree = new Promise((resolve, reject) => {
    resolve('Video 3 Recorded')
})

//to run these in parallel at the same time, so we dont have to worry about waiting for one before we start the next 
//we can just say Promise.all and is going to run every single one of these promises and as soon as it's done it is then going to call .then .catch method
//depending on if they resolved or fail so in our case all of these are going to resolve 
Promise.all([
    recordVideoOne,
    recordVideoTwo,
    recordVideoThree
]).then((messages) => {
    console.log(messages)
})
//you can really see but these all are running at the exact same time, they wont have to wait for others to finish

//will return as soon as the first one finished
Promise.race([
    recordVideoOne,
    recordVideoTwo,
    recordVideoThree
]).then((messages) => {
    console.log(messages)
})