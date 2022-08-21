function makeRequest(location){
    return new Promise((resolve, reject) => {
        console.log(`Making request to ${location}`)
        if (location === 'Google') {
            resolve('Google says hi')
        } else {
            reject('We can only talk to Google')
        }
    })
}
function processRequest(response){
    return new Promise((resolve, reject) => {
        console.log('Processing response')
        resolve(`Extra information + ${response}`)
    })
}

//using promises
/* makeRequest('Facebook').then(response => {
    console.log('Response Received')
    return processRequest(response)
}).then(processedResponse => {
    console.log(processedResponse)
}).catch(err => {
    console.log(err)
}) */
//its all waiting for the previous code to be executed before going on to the next code which exactly what we want

//async and await making promises easier to work with
//we need to tell javascrip to async this function and use keyword await
//the code should await until this makerequest is finished and then afterwards it'll execute the next thing
//once javascript hit that await statement it'll just await this function do other work inside the program
//then as soon as this makerequest finished executing it'll come back to here return the result into this response variabel
async function doWork() {
    try{
        const response = await makeRequest('Google')
        console.log('Response Received')
        const processedResponse = await processRequest(response)
        console.log(processedResponse)
    } catch(err) {
        console.log(err)
    }
}
doWork()
//it work the same as promise
//but to catch error we need to use try catch